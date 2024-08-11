// https://www.codechef.com/problems/CHEFRRUN
// https://youtu.be/s1pYDKbYtmo

/*
In general SCC of size >= 2 contribues to answer.
But we can have SCC of size 1 (i.e. only one node) and if it contains self loop then this size = 1 also contribues to answer.
*/


const int N = 1e6+5;
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
    cin >> n;
    int a[n];

    f(i, n) {
        cin >> a[i];

        g[i].clear();
        transpose_g[i].clear();
        vis[i] = 0;
    }

    f(i, n) {
        u = i;
        v = (i + a[i] + 1) % n;
        
        g[u].pb(v), transpose_g[v].pb(u);
    }

    // to store nodes in decreasing order of out time in stack
    f(i, n) {
        if(!vis[i]) dfs(i);
    }


    f(i, n) vis[i] = 0;

    int res = 0;
    while(!st.empty()) {
        int ind = st.top();
        st.pop();

        if(!vis[ind]) {
            SCC.clear();
            revDfs(ind);

            // SCC[0] == g[SCC[0]][0] is condition for self loop, and self loop also contributes in answer
            if(SCC.size() == 1 && (SCC[0] != g[SCC[0]][0])) continue;
            
            res += SCC.size();

            SCC.clear();
        }
    }

    cout << res << endl;
}
