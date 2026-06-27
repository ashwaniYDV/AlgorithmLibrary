/*
You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0 to n - 1. 
This is represented by a 2D integer array edges, where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with weight wi.
You are also given a string labels of length n, where labels[i] is the character assigned to node i, and an integer k.
Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels of the nodes along the path contains at most k consecutive identical characters. 
If no valid path exists, return -1.

 

Example 1:
Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1
Output: 3

Example 2:
Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 2
Output: 2

Example 3:
Input: n = 3, edges = [[0,1,1],[1,2,1]], labels = "aaa", k = 2
Output: -1

Constraints:
1 <= n == labels.length <= 5 * 10^4
0 <= edges.length <= 5 * 10^4
edges[i] == [ui, vi, wi]
0 <= ui, vi <= n - 1
ui != vi
1 <= wi <= 10^4
labels consists of lowercase English letters
1 <= k <= 50
*/


class Solution {
public:
    const int INF = 1e9;

    int dijkstra(int src, int dest, int n, vector<vector<pair<int, int>>>& g, string& labels, int k) {
        vector<vector<int>> dp(n, vector<int>(k+1, INF));

        // {distance, node, j}, where j is from 1 to k
        priority_queue <array<int, 3>, vector<array<int, 3>> , greater <array<int, 3>>> pq;

        // j = 1 since its count of this first character
        dp[src][1] = 0;
        pq.push({dp[src][1], src, 1});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int w = it[0], u = it[1], j = it[2];

            if(w > dp[u][j]) continue;

            for (auto& x: g[u]) {
                int v = x.first, w = x.second;
                
                // case 1: if its same character incrrement the count
                // case 2: if its a new character then set count to 1
                int newJ = (labels[u] == labels[v]) ? j + 1 : 1;

                // we cannot have more than k consecutive characters
                if(newJ > k) continue;

                if (dp[v][newJ] > dp[u][j] + w) {
                    dp[v][newJ] = dp[u][j] + w;
                    pq.push({dp[v][newJ], v, newJ});
                }
                
            }
        }

        int res = INF;
        for (int j = 1; j <= k; j++) {
            res = min(res, dp[n-1][j]);
        }

        return res == INF ? -1 : res;
    }

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for(auto& it: edges) {
            int u = it[0], v = it[1], w = it[2];
            g[u].push_back({v, w});
        }

        return dijkstra(0, n-1, n, g, labels, k);
    }
};
