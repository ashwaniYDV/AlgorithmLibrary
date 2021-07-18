/*
Print all paths from source to destination node in a directed/undirected graph.
*/



vl g[N];
ll vis[N];

void dfs(ll u, ll dest, vector<ll> res) {
    if(u == dest) {
        for(ll x: res) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    vis[u] = 1;
    for(ll v: g[u]) {
        if(!vis[v]) {
            res.pb(v);
            dfs(v, dest, res);
            // backtrack
            res.pop_back();
        }
    }
    // backtrack
    vis[u] = 0;
}

void solve() {
    ll m, x, u, v, source, dest;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    cin >> source >> dest;
    vector<ll> res;
    res.pb(source);
    dfs(source, dest, res);
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
2 1 3 4 
2 1 3 5 4 
2 5 3 4 
2 5 4 


*/






/*

In backtracking problems Vis can be used globally as well as in parameter as shown 
since we have to backtrack in either case so doesn't matter.

void dfs(ll u, ll dest, vector<ll> res, vector<ll> vis) {
    if(u == dest) {
        for(ll x: res) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    vis[u] = 1;
    for(ll v: g[u]) {
        if(!vis[v]) {
            res.pb(v);
            dfs(v, dest, res, vis);
            // backtrack
            res.pop_back();
        }
    }
    // backtrack
    vis[u] = 0;
}

void solve() {
    ll m, x, u, v, source, dest;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    cin >> source >> dest;
    vector<ll> res, vis(n + 1, 0);
    res.pb(source);
    dfs(source, dest, res);
}

*/
