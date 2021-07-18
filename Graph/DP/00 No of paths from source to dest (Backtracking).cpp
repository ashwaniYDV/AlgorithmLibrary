// No of possible paths from source to destination (directed as well as undirected graph)


vl g[N];
ll vis[N];
ll res = 0;

void dfs(ll u, ll dest) {
    if(u == dest) {
        res++;
        return;
    }
    vis[u] = 1;
    for(ll v: g[u]) {
        if(!vis[v]) {
            dfs(v, dest);
        }
    }
    vis[u] = 0;
}

void solve() {
    ll m, x, u, v, source, dest;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    cin >> source >> dest;
    dfs(source, dest);
    cout << res << endl;
}

int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    // cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}



/*

Input:
5
6
1 2
1 3
3 4
3 5
2 5
4 5
2
4
         1
       /   \
     3      2
    | \    /
    |  \  /
    4___5

Output:
4

*/
