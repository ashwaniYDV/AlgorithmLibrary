// https://leetcode.com/problems/find-eventual-safe-states/editorial/

/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
*/


// Method 1
class Solution {
public:
    enum Color {WHITE, GRAY, BLACK};
    
    bool isCycle(int u, vector<int>& color, vector<vector<int>>& g) {
        color[u] = GRAY;
        
        for(int v: g[u]) {
            if(color[v] == GRAY) return true;
            if(color[v] == WHITE) {
                if(isCycle(v, color, g)) return true;
            }
        }
        
        color[u] = BLACK;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> color(n, WHITE);
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(!isCycle(i, color, g)) res.push_back(i);
        }
        
        return res;
    }
};


// Method 2
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> rev_g(n);

        for (int u = 0; u < n; u++) {
            for (int v: graph[u]) {
                // reverse edge
                rev_g[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> safe(n);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            safe[u] = true;

            for (auto& v: rev_g[u]) {
                // Delete the edge "node -> neighbor".
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};
