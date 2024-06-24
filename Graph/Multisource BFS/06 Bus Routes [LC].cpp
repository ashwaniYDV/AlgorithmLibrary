// https://leetcode.com/problems/bus-routes/description/

/*
You are given an array bus routes where routes[i] is a bus route that the ith bus repeats forever.
Eg, if routes[0] = [1, 5, 7], this means that 0th bus travels in sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at bus stop source (You are not on any bus initially), 
and you want to go to the bus stop target. 
You can travel between bus stops by buses only.
Return least number of buses you must take to travel from source to target. 
Return -1 if it is not possible.
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // build the graph (bus as node, bus-transfer as edge)
        // build hash table for `stop2bus`
        // hash table for `bus2stop` is `routes` only
        unordered_map<int, unordered_set<int>> stop2bus;
        for (int bus = 0; bus < routes.size(); bus++) {
            for (auto& stop : routes[bus]) stop2bus[stop].insert(bus);
        }

        // start from the buses which pass the bus stop `source`
        queue<pair<int, int>> q;
        unordered_set<int> bus_taken; // visited array
        for (auto& bus : stop2bus[source]) {
            q.push({bus, 1});
            bus_taken.insert(bus);
        }

        while (!q.empty()) {
            int bus = q.front().first;
            int totalBusTaken = q.front().second;
            q.pop();

            for (auto& next_stop : routes[bus]) {
                if (next_stop == target) return totalBusTaken;

                for (auto& next_bus : stop2bus[next_stop]) {
                    if (bus_taken.count(next_bus)) continue;
                    
                    q.push({next_bus, totalBusTaken + 1});
                    bus_taken.insert(next_bus);
                }
            }
        }

        // unreachable
        return -1;
    }
};
