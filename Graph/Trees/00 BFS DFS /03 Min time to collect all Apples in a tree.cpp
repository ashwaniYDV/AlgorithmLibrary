// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

/*
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. 
You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, 
starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. 
Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
*/


/*
Res = 2 * (Toal no of edges from root till last nodes having apple and neglecting further below nodes edges)
*/

class Solution {
public:
    int res = 0;
    vector<vector<int>> g;

    bool dfs(int u, int par, vector<bool>& hasApple) {
        bool flag = false;
        for (int v : g[u]) {
            if (v != par) {
                if (dfs(v, u, hasApple)) {
                    res++;
                    flag = true;
                }
            }
        }
        if (hasApple[u]) {
            flag = true;
        }
        return flag;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        g = vector<vector<int>>(n);
        for (auto it : edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        res = 0;
        dfs(0, -1, hasApple);
        return 2 * res;
    }
};
