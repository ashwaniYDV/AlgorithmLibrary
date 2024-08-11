/* 
Kosaraju's Algorithm to calculate and print Strongly Connected Components (SCC) in directed graph
https://youtu.be/Rs6DXyWpWrI
*/


vector<int> g[N];
vector<int> transpose_g[N];
int vis[N];
stack<int> st;

void dfs(int u) {
    vis[u] = 1;

    for(int v: g[u]) {
        if(!vis[v]) dfs(v);
    }

    st.push(u);
}

void revDfs(int u) {
    vis[u] = 1;
    cout << u << " ";

    for(int v: transpose_g[u]) {
        if(!vis[v]) revDfs(v);
    }
}

void solve() {
    int x, y, z, k, u, v;
    cin >> n >> m;

    f(i, m) cin >> u >> v, g[u].pb(v);

    // Method 1 for creating transpose_g
    // f(i, m) cin >> u >> v, g[u].pb(v), transpose_g[v].pb(u);

    // Method 2 for creating transpose_g
    loop(i, 1, n) {
        for(int v: g[i]) {
            transpose_g[v].pb(i);
        }
    }
    
    // to store nodes in decreasing order of out time in stack
    loop(i, 1, n) {
        if(!vis[i]) dfs(i);
    }


    loop(i, 0, n) vis[i] = 0;

    ll totalSCC = 0;
    // driver
    while(!st.empty()) {
        int ind = st.top();
        st.pop();

        if(!vis[ind]) {
            totalSCC++;
            cout << "SCC\n";
            revDfs(ind);
            cout << endl;
        }
    }

    cout << "Total SCC = " << totalSCC << endl;

}

/*
INP:
5 5
3 1
1 2
2 3
1 4
4 5
OUT:
SCC
1 3 2 
SCC
4 
SCC
5 
Total SCC = 3
*/
