// https://www.scaler.com/problems/construct-roads/

/*
A country consist of N cities connected by N - 1 roads. 
King of that country want to construct max no of roads such that the new country formed remains bipartite country.

Bipartite country is a country, whose cities can be partitioned into 2 sets in such a way, 
that for each road (u, v), u and v belong to different sets. 
Also, there should be no multiple roads between two cities and no self loops.

Return max no of roads king can construct. 
Since the answer could be large return answer % 10^9 + 7.

NOTE: All cities can be visited from any city.
*/





/*
As we know, the tree is itself bipartite.
Run a DFS over the given tree and partition it into two sets.
We can’t add an edge between any 2 nodes in the same set and we can add an edge between every 2 nodes in different sets, 
so let the number of nodes in the left set be x and the number of nodes in the right set be y.

The maximum number of edges that can exist is x * y, 
but N - 1 edges already exist so the maximum number of edges to be added is x * y - (N - 1).
*/



const int maxN = 1e5 + 5;
long long col[2];
vector < int > g[maxN];
const int mod = 1e9 + 7;

void dfs(int u, int parent, int c) {
    col[c]++;
    for (auto v: g[u]) {
        if (v != parent) {
            dfs(v, u, 1 - c);
        }
    }
}

int Solution::solve(int A, vector < vector < int > > & B) {
    int N = A;
    col[0] = col[1] = 0;
    for (int i = 0; i <= N; i++) {
        g[i].clear();
    }
    for (int i = 0; i < B.size(); i++) {
        int u = B[i][0], v = B[i][1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);
    long long ans = col[0] * col[1];
    ans -= N - 1;
    return ans % mod;
}
