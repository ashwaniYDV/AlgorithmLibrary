// https://practice.geeksforgeeks.org/contest/code-battle/problems/
// Problem = Count the Subtress

/*
Given a tree having N nodes numbered from 1 to N, and (N-1) edges where the i'th edge is between nodes Edges[i][0] and Edges[i][1]. 
The tree is rooted at node 1 and each node has a colour where the colour of the i'th node is given by A[i]. 
Count the number of sub trees that do not contain any two nodes which have the same color. 
*/

class Solution {
public:
    vector < vector < int >> g;
    set < int > * st[100005];
    vector < int > color;
    vector < int > res;
    vector < int > subtreeSize;

    void dfs(int u, int par) {
        int mx = 0;
        int mxNode = -1;
        subtreeSize[u] = 1;

        for (int v: g[u]) {
            if (v == par) continue;
            dfs(v, u);
            if (st[v] -> size() > mx)
                mx = st[v] -> size(), mxNode = v;

            subtreeSize[u] += subtreeSize[v];
        }

        if (mxNode == -1)
            st[u] = new set < int > ();
        else
            st[u] = st[mxNode];

        st[u] -> insert(color[u]);

        for (int v: g[u]) {
            if (v != par && v != mxNode) {
                for (int c: * st[v])
                    st[u] -> insert(c);
            }
        }

        res[u] = st[u] -> size();
    }

    int countSubtree(int n, vector<int> A, vector<vector<int>> Edges) {
        g.resize(n + 1);
        color.resize(n + 1, 0);
        res.resize(n + 1, 0);
        subtreeSize.resize(n + 1, 0);

        for (auto it: Edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {
            color[i + 1] = A[i];
        }
        dfs(1, -1);

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (res[i] == subtreeSize[i]) cnt++;
        }

        return cnt;
    }
};
