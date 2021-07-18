// https://www.geeksforgeeks.org/maximum-edge-removal-tree-make-even-forest/

/*
Given an undirected tree which has even number of vertices, we need to remove the maximum number of edges from this tree 
such that each connected component of the resultant forest has an even number of vertices. 
*/


const int N = 1e5+5;
int n, m;

vi g[N];
int subtreeSize[N];
int res = 0;

void dfs(int u, int par) {
    subtreeSize[u] = 1;

    for(int v: g[u]) {
        if(v != par) {
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
        }
    }
    if(subtreeSize[u] % 2 == 0) res++;
}

void solve() {
    int u, v;
    cin >> n;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    res = 0;
    dfs(1, -1);
    cout << res << endl;
} 
