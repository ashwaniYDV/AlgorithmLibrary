// https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/


const int N = 2e5+5;
int n, m;

vector<int> g[N];
vector<int> transpose_g[N];
int vis[N];
stack<int> st;
vector<int> SCC;

void dfs(int u) {
    vis[u] = 1;

    for(int v: g[u]) {
        if(!vis[v]) dfs(v);
    }

    st.push(u);
}

void revDfs(int u) {
    vis[u] = 1;
    SCC.pb(u);

    for(int v: transpose_g[u]) {
        if(!vis[v]) revDfs(v);
    }
}

void solve() {
    int u, v;
    cin >> n >> m;

    f(i, m) cin >> u >> v, g[u].pb(v), transpose_g[v].pb(u);

    // to store nodes in decreasing order of out time in stack
    loop(i, 1, n) {
        if(!vis[i]) dfs(i);
    }


    loop(i, 1, n) vis[i] = 0;

    int res[n+1] = {0};

    while(!st.empty()) {
        int ind = st.top();
        st.pop();

        if(!vis[ind]) {
            SCC.clear();
            revDfs(ind);

            if(SCC.size() > 1) {
                for(int u: SCC)
                    res[u] = 1;
            }
            
            SCC.clear();
        }
    }

    loop(i, 1, n)
        cout << res[i] << " ";
}
