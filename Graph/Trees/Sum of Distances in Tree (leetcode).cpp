// https://leetcode.com/problems/sum-of-distances-in-tree/

/*
Find sum of distances from one node to all the other nodes for all the nodes 1...n
and return an array as answer where asn[i] = sum of distances from node i to all the other nodes 
*/


class Solution {
public:
    int n;
    
    void getSubtreeSize( int u, int par, vector<int>& subtreeSize, vector<vector<int>>& g) {
        subtreeSize[u] = 1;
        for(int v: g[u]) {
            if(v == par) continue;
            getSubtreeSize(v, u, subtreeSize, g);
            subtreeSize[u] += subtreeSize[v];
        }
    }
    
    void getRes(int u, int par, vector<int>& subtreeSize, vector<vector<int>>& g, vector<int>& res) {
        for(int v: g[u]) {
            if(v == par) continue;
            res[v] = res[u] + n - 2 * subtreeSize[v];
            getRes(v, u, subtreeSize, g, res);
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        vector<int> subtreeSize(n, 0);
        vector<int> res(n, 0);
        vector<vector<int>> g(n);
        for(auto& edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        // get subtree size of all nodes taking 0 as root
        getSubtreeSize(0, -1, subtreeSize, g);

        // sum of distance from root node is the sum of `subtreeSize` except the root itself
        for(int i = 1; i < n; i++) {
            res[0] += subtreeSize[i];
        }

        // after getting the distance sum of root, we can deduce the distance sum of the other node.
        getRes(0, -1, subtreeSize, g, res);

        return res;
    }
};
