/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. 
The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. 
You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 10^9 + 7.


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

Constraints:
1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 10^9
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
*/


class Solution {
public:
    #define ll long long
    const ll INF = 1e18, MOD = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<array<int, 2>>> g(n);
        for(auto& it: roads) {
            int u = it[0], v = it[1], w = it[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        
        // dijkstra
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
        pq.push({0, 0});

        vector<ll> disDp(n, INF), cntDp(n, 0);
        disDp[0] = 0;
        cntDp[0] = 1;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ll cost = it[0], u = it[1];

            if(cost > disDp[u]) continue;

            for(auto& it: g[u]) {
                int v = it[0], w = it[1];
                if(disDp[v] > disDp[u] + w) {
                    disDp[v] = disDp[u] + w;
                    
                    cntDp[v] = cntDp[u];
                    pq.push({disDp[v], v});
                } else if(disDp[v] == disDp[u] + w) {
                    cntDp[v] = (cntDp[v] + cntDp[u]) % MOD;
                }
            }
        }

        return cntDp[n-1];
    }
};
