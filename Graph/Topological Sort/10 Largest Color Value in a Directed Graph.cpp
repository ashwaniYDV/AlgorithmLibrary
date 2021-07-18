// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

/*
There is a directed graph of n colored nodes and m edges. 
The nodes are numbered from 0 to n - 1.
You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). 
You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. 
The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
*/

/*
dp[v][c] := max count of vertices with color c of any path ending at vertex v.
*/

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> g(n);
        vector<int> indegree(n);

        for (auto& it : edges) {
            g[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);

                // base case of DP
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int visitedNodesCount = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visitedNodesCount++;

            for (auto& v : g[u]) {
                for (int i = 0; i < 26; i++) {
                    if(colors[v] - 'a' == i) {
                        dp[v][i] = max(dp[v][i], dp[u][i] + 1);
                    } else {
                        dp[v][i] = max(dp[v][i], dp[u][i]);
                    }
                }

                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // there is cycle
        if(visitedNodesCount < n) return -1;

        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};



class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> g(n);
        vector<int> indegree(n);

        for (auto& it : edges) {
            g[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);

                // base case of DP
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int visitedNodesCount = 0;
        int res = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visitedNodesCount++;
            res = max(res, dp[u][colors[u] - 'a']);

            for (auto& v : g[u]) {
                for (int i = 0; i < 26; i++) {
                    if(colors[v] - 'a' == i) {
                        dp[v][i] = max(dp[v][i], dp[u][i] + 1);
                    } else {
                        dp[v][i] = max(dp[v][i], dp[u][i]);
                    }
                }

                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // there is cycle
        if(visitedNodesCount < n) return -1;
        return res;
    }
};