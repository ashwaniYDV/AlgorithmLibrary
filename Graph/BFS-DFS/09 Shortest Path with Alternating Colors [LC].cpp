// https://leetcode.com/problems/shortest-path-with-alternating-colors/

/*
Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  
In this graph, each edge is either red or blue, and there could be self-edges or parallel edges.
Each [i, j] in red_edges denotes a red directed edge from node i to node j.  
Similarly, each [i, j] in blue_edges denotes a blue directed edge from node i to node j.

Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to node X 
such that the edge colors alternate along the path (or -1 if such a path doesn't exist).
*/

class Solution {
public:
    #define INF 1e9
    #define RED 1
    #define BLUE 2
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> g[n];
        
        // red color = 1
        for(auto it: red_edges) {
            g[it[0]].push_back({it[1], RED});
        }
        // blue color = 2
        for(auto it: blue_edges){
            g[it[0]].push_back({it[1], BLUE});
        }

        queue<vector<int>> q;
        // since root does not has any previous edge, we can take previous edge color as any color other than red or blue
        // {node, prevEdgeColor}
        q.push({0, 0});

        vector<int> disR(n, INF), disB(n, INF);
        disR[0] = 0;
        disB[0] = 0;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int u = it[0], prevEdgeColor = it[1];

            for(auto it: g[u]) {
                int v = it[0], nextEdgeColor = it[1];
                if(prevEdgeColor == nextEdgeColor) continue;

                // red
                if(nextEdgeColor == RED && disR[v] == INF) {
                    disR[v] = disB[u] + 1;
                    q.push({v, nextEdgeColor});
                } 
                // blue
                if(nextEdgeColor == BLUE && disB[v] == INF) {
                    disB[v] = disR[u] + 1;
                    q.push({v, nextEdgeColor});
                }
            }
        }
        
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            res[i] = min(disR[i], disB[i]);
            if(res[i] == INF) res[i] = -1;
        }
        return res;
    }
};
