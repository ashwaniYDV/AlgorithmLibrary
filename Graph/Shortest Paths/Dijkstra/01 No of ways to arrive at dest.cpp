// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. 
The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road 
between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] 
means that there is a road between intersections ui and vi that takes timei minutes to travel. 
You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. 
Since the answer may be large, return it modulo 109 + 7.
*/


#define ll long long
class Solution {
  public:
    const int N = 2e5+5;
    const int MOD = 1e9+7;
    const ll INF = 1e18+7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        int u, v, w;
        vector<pair<int, int>> g[N];
        for(auto it: roads) {
            int u = it[0], v = it[1], w = it[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    
        // djikstra begins
        ll dis[N]; 
        int numOfWays[N];
        int src = 0;
        for(int i = 0; i < n; i++) {
            dis[i] = INF;
            numOfWays[i] = 0;
        }
    
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        
        pq.push({0, src});
        dis[src] = 0;
        numOfWays[src] = 1;
    
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
    
            ll cost = it.first;
            int u = it.second;
    
            // this step is awesome in priority queue method
            if(cost > dis[u]) continue;
            
            for(auto it: g[u]) {
                int v = it.first, w = it.second;
                if(dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                    numOfWays[v] = numOfWays[u];
                }
                else if(dis[u] + w == dis[v]) {
                    numOfWays[v] = (numOfWays[v] + numOfWays[u]) % MOD;
                }
            }
        }
        // djikstra ends
        
        return numOfWays[n-1];
    }
};
