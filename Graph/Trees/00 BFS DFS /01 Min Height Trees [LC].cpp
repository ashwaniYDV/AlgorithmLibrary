// https://leetcode.com/problems/minimum-height-trees/

/*
Given a undirected tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi].
You can choose any node of the tree as the root. 
When you select a node x as the root, the result tree has height h. 
Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order.
*/

class Solution {
public:
    int n;

    void dfs(int u, int par, int d, vector<int>& depth, vector<vector<int>>& g) {
        depth[u] = d;
        for(int v: g[u]) {
            if(v == par) continue;
            dfs(v, u, d+1, depth, g);
        }
    }

    vector<int> diameter(vector<vector<int>>& g) {
        vector<int> depth1(n);
        dfs(0, -1, 0, depth1, g);
        int node1 = 0, mx1 = 0;
        for(int i = 0; i < n; i++) {
            if(depth1[i] > mx1) {
                mx1 = depth1[i];
                node1 = i;
            }
        }

        dfs(node1, -1, 0, depth1, g);
        int node2 = 0, mx2 = 0;
        for(int i = 0; i < n; i++) {
            if(depth1[i] > mx2) {
                mx2 = depth1[i];
                node2 = i;
            }
        }

        vector<int> depth2(n);
        dfs(node2, -1, 0, depth2, g);

        int minHeight = n;
        for(int i = 0; i < n; i++) {
            minHeight = min(minHeight, max(depth1[i], depth2[i]));
        }

        vector<int> res;
        for(int i = 0; i < n; i++) {
            if (max(depth1[i], depth2[i]) == minHeight) {
                res.push_back(i);
            }
        }

        return res;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        this->n = n;
        vector<vector<int>> g(n);
        for(auto& it: edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }

        return diameter(g);
    }
};
