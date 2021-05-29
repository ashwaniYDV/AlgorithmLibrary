// https://codeforces.com/contest/342/problem/E


const int N = 2e5+5;
int n, m;
 
set<int> g[N];
int parent[N];
int subTreeSize[N];
int res[N];


/************* LCA Part ****************/
int level[N];
int height=(int)ceil(log2(N));

// LCA[i][j] represents 2^(j)th parent of node i
int LCA[N][(int)ceil(log2(N))+1];

void dfsLCA(int u, int lvl, int par) {
    level[u] = lvl;
    LCA[u][0] = par;
    for(auto v: g[u]) {
        if(v != par) {
            dfsLCA(v, lvl + 1, u);
        }
    }
}

void initLCA() {
    // initializing parent and level of each node
    dfsLCA(1, 0, -1);

    for(int i = 1; i <= height; i++) {
        for(int node = 1; node <= n; node++) {
            if(LCA[node][i-1] != -1) {
                int parNode = LCA[node][i - 1];
                LCA[node][i] = LCA[parNode][i - 1];
            }else{
                LCA[node][i] = -1;
            }
        }
    }
}

int getLCA(int a, int b) {
    if(level[b] < level[a]) swap(a, b);

    int d = level[b] - level[a];

    // method 1
    // for(int i = height; i >= 0; i--){
    //     if(d & (1<<i)) b = LCA[b][i];
    // }

    // method 2
    while(d) {
        int i = log2(d);
        b = LCA[b][i];
        d -= (1 << i);
    }

    if(a == b) return a;

    for(int i = height; i >= 0; i--){
        if(LCA[a][i] != LCA[b][i]){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    // parent of a or b
    return LCA[a][0];
}

int getDistance(int a, int b) {
    int lca = getLCA(a, b);
    return (level[a] + level[b] - 2 * level[lca]);
}
/************************************************/


/************* Decomposition Part ****************/
int dfs0(int u, int par) {
    subTreeSize[u] = 1;
    for(int v: g[u]) {
        if(v != par)
            subTreeSize[u] += dfs0(v, u);
    }
    return subTreeSize[u];
}

int getCentroid(int u, int par, int n) {
    for(int v: g[u]) {
        if(v != par && subTreeSize[v] > n/2)
            return getCentroid(v, u, n);
    }
    return u;
}
 
void decompose(int u, int par) {
    int stSize = dfs0(u, -1);
    int centroid = getCentroid(u, par, stSize);
    parent[centroid] = par;
 
    for(int v : g[centroid]) {
        g[v].erase(centroid);
        decompose(v, centroid);
    }
}
/************************************************/

// we are assuming parent of root of centroid tree is -1
void update(int u) {
    int curr = u;
    while(curr != -1) {
        res[curr] = min(res[curr], getDistance(curr, u));
        curr = parent[curr];
    }
}
 
int query(int node) {
    int curr = node;
    int ans = INF;
    while(curr != -1) {
        ans = min(ans, res[curr] + getDistance(curr, node));
        curr = parent[curr];
    }
    return ans;
}
 
void solve() {
    int u, v, type;
    cin >> n >> m;
 
    f(i, n-1) cin >> u >> v, g[u].insert(v), g[v].insert(u);

    initLCA();
    decompose(1, -1);

    res[1] = 0;
    for(int i = 2; i <= n; i++) {
        res[i] = getDistance(i, 1);
    }

    while(m--) {
        cin >> type >> u;
        if(type == 1) {
            update(u);
        } else {
            cout << query(u) << endl;
        }
    }
}
 
signed main() {
    IOS
    int t = 1;
    // cin >> t;
    f(i, t) {
        solve();
    }
}
