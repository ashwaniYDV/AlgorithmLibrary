/*
For each subtree node calculate the MEX of values in that subtree.
*/

/*
NOTE: mex[u] can be from 0 to n only.
Thus this while(st[u]->count(mex[u])) loop runs overall O(N) in all the calls.
Thus time complexity is O(N)log(N) or O(N)log^2(N).
*/

const int N = 1e5+5;
int n, m;
vi g[N];
int value[N];
set<int> *st[N];
int mex[N];

void dfs(int u, int par) {
    int mx = 0;
    int mxNode = -1;
    
    for(int v : g[u]) {
        if(v == par) continue;
        dfs(v , u);
        if(st[v]->size() > mx) {
            mx = st[v]->size(), mxNode = v;
        }
        mex[u] = max(mex[u], mex[v]);
    }

    if(mxNode == -1) {
        st[u] = new set<int>();
    } else {
        st[u] = st[mxNode];
    }
    
    st[u]->insert(value[u]);
    
    for(int v : g[u]) {
        if(v != par && v != mxNode) {
            for(int c : *st[v]) {
                st[u]->insert(c);
            }
        }
    }

    while(st[u]->count(mex[u])) {
        mex[u]++;
    }
}

void solve() {
    int u, v, q, root;
    cin >> n;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    for(int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    dfs(1, -1);

    for(int i = 1; i <= n; i++) {
        cout << mex[i] << " ";
    }
}
