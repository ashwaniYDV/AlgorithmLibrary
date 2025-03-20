// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/

/*
There is an undirected weighted graph with n vertices labeled from 0 to n - 1.
You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.
A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. 
It's important to note that a walk may visit the same edge or vertex more than once.
The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. 
In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.
You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. 
If there exists no such walk, the answer is -1.
Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.
*/


/*
Intuition:
----------
* Any 2 nodes in a connected component will have the same answer = bitwise AND of all the edge values in the connected component.

* If query[i] = {u, v}, then
  if u, v belongs to diff connected component, its answer will be -1
  if u, v belongs to same connected component, its answer will be bitwise AND of all the edges in the connected component
*/


class Solution {
public:
    struct DSU {
        vector<int> par;
        DSU(int n) {
            par.resize(n + 1, -1);
        }
        int findParent(int a) {
            if (par[a] < 0)
                return a;
            return par[a] = findParent(par[a]);
        }
        bool unionSet(int a, int b) {
            a = findParent(a);
            b = findParent(b);
            if (a == b)
                return 0;
            if (par[a] > par[b])
                swap(a, b);
            par[a] += par[b];
            par[b] = a;
            return 1;
        }
        bool sameSet(int x, int y) {
            return findParent(x) == findParent(y);
        }
        int size(int x) {
            return -par[findParent(x)];
        }
    };

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for (auto& it : edges) {
            int u = it[0], v = it[1];
            dsu.unionSet(u, v);
        }

        vector<int> bitwiseAnd(n, -1);

        for (auto& it : edges) {
            int u = it[0], v = it[1], w = it[2];
            int par = dsu.findParent(u);
            if (bitwiseAnd[par] == -1) {
                bitwiseAnd[par] = w;
            } else {
                bitwiseAnd[par] &= w;
            }
        }

        vector<int> res;
        for (auto& it : query) {
            int u = it[0], v = it[1];
            if (!dsu.sameSet(u, v)) {
                res.push_back(-1);
            } else {
                int par = dsu.findParent(u);
                res.push_back(bitwiseAnd[par]);
            }
        }

        return res;
    }
};
