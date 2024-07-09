// https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/

/*
There is an undirected graph of n nodes. 
You are given a 2D array edges, where edges[i] = [ui, vi, lengthi] 
describes an edge between node ui and node vi with a traversal time of lengthi units.
Additionally, you are given an array disappear, 
where disappear[i] denotes the time when the node i disappears from the graph and you won't be able to visit it.
Notice that the graph might be disconnected and might contain multiple edges.
Return the array answer, with answer[i] denoting the minimum units of time required to reach node i from node 0. 
If node i is unreachable from node 0 then answer[i] is -1.
*/

class Solution {
public:
    const int INF = 1e9;
    
    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& g, vector<int>& disappear) {
        vector<int> dp(n, INF);

        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, 0});
        dp[0] = 0;

        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();

            int u = x.second;

            // this is important, otherwise TLE
            if (dp[u] < x.first) continue;

            for (auto it: g[u]) {
                int v = it.first, w = it.second;
                if ((dp[v] > dp[u] + w) && (dp[u] + w < disappear[v])) {
                    dp[v] = dp[u] + w;
                    pq.push({dp[v], v});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(dp[i] >= INF) dp[i] = -1;
        }
        return dp;
    }

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> g(n);
        for (auto i : edges) {
            int u = i[0], v = i[1], w = i[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        return dijkstra(n, g, disappear);
    }
};