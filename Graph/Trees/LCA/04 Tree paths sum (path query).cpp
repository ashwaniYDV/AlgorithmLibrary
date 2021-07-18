// https://www.codechef.com/CCHI2021/problems/CCBTS05

/*
You are given a weighted tree with N nodes, rooted at node R. The nodes are numbered from 1 to N. 
There are Q queries of the form (U, V), and you should output the sum of the weights on all the edges on the shortest path from node U to V.
*/

// AC
const int N = 1e5+5;
int n, m;

const int height = (int)ceil(log2(N));
vector<pair<int, int>> g[N];
int level[N], levelSum[N];
vector<vector<int>> LCA;

void dfs(int u, int par, int lvl, int lvlSum) {
    level[u] = lvl;
    LCA[u][0] = par;
    levelSum[u] = lvlSum;

    for (auto it: g[u]) {
        int v = it.F, w = it.S;
        if (v != par) {
            dfs(v, u, lvl + 1, lvlSum + w);
        }
    }
}

void init(int root) {
    dfs(root, -1, 0, 0);

    for(int i = 1; i <= height; i++) {
        for(int node = 1; node <= n; node++) {
            // for 2^i node, first getting 2^(i - 1)th node
            int parNode = LCA[node][i - 1];
            if(parNode != -1) {
                // 2^(i)th node = 2^(i - 1)th + 2^(i - 1)th node
                LCA[node][i] = LCA[parNode][i - 1];
            } else {
                LCA[node][i] = -1;
            }
        }
    }
}

int getKthAncestor(int node, int k) {
    for(int i = height-1; i >= 0; i--) {
        if(k & (1 << i)) {
            node = LCA[node][i];
            if(node == -1) return -1;
        }
    }
    return node;
}

int getLCA(int a, int b) {
    if(level[a] > level[b]) swap(a, b);

    int d = level[b] - level[a];
    b = getKthAncestor(b, d);

    if (a == b) return a;

    for(int i = height - 1; i >= 0; i--) {
        if (LCA[a][i] != LCA[b][i]) {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }

    return LCA[a][0];
}

int getDistance(int a, int b) {
    int lca = getLCA(a, b);
    return (levelSum[a] + levelSum[b] - 2 * levelSum[lca]);
}

void solve() {
    int u, v, w, q, root;
    cin >> n >> q >> root;

    loop(i, 0, n) {
        g[i].clear();
        level[i] = 0;
        levelSum[i] = 0;
    }

    LCA.resize(N, vector<int>(height+1, -1));

    f(i, n-1) {
        cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    init(root);
    while(q--) {
        cin >> u >> v;
        cout << getDistance(u, v) << endl;
    }
}
 
signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    PRECISION(10);
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}

































// Method 1 (Generalized)
const int N = 1e5+5;
int n, m;

const int height = (int)ceil(log2(N));
vector<pair<int, int>> g[N];
int level[N];
vector<vector<int>> LCA, LCASum;

void dfs(int u, int par, int lvl, int wt) {
    level[u] = lvl;
    LCA[u][0] = par;
    LCASum[u][0] = wt;

    for (auto it: g[u]) {
        int v = it.F, w = it.S;
        if (v != par) {
            dfs(v, u, lvl + 1, w);
        }
    }
}

void init() {
    dfs(1, -1, 0, 0);

    for(int i = 1; i <= height; i++) {
        for(int node = 1; node <= n; node++) {
            int parNode = LCA[node][i - 1];
            if(parNode != -1) {
                LCA[node][i] = LCA[parNode][i - 1];
                LCASum[node][i] = LCASum[parNode][i - 1] + LCASum[node][i - 1];
            } else {
                LCA[node][i] = -1;
                LCASum[node][i] = 0;
            }
        }
    }
}

int getLCA(int a, int b) {
    if(level[a] > level[b]) swap(a, b);

    int sum = 0;

    int d = level[b] - level[a];
    for(int i = height-1; i >= 0; i--) {
        if(d & (1 << i)) {
            sum += LCASum[b][i];
            b = LCA[b][i];
        }
    }

    if (a == b) return sum;

    for(int i = height - 1; i >= 0; i--) {
        if (LCA[a][i] != LCA[b][i]) {
            sum += LCASum[a][i];
            a = LCA[a][i];
            sum += LCASum[b][i];
            b = LCA[b][i];
        }
    }

    return sum + LCASum[a][0] + LCASum[b][0];
}

void solve() {
    int u, v, w, q;
    cin >> n;

    LCA.resize(N, vector<int>(height+1, -1));
    LCASum.resize(N, vector<int>(height+1, 0));

    f(i, n-1) {
        cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    init();

    cin >> q;
    while(q--) {
        cin >> u >> v;
        cout << getLCA(u, v) << endl;
    }
}

/*
Input:
9
1 2 3
1 3 4
2 4 1
2 5 5
3 6 2
3 7 3
1 8 1
8 9 4
5
1 3
4 6
2 5
1 7
3 8

Output:
4
10
5
7
5
*/































// Method 2 (Generalized)
const int N = 1e5+5;
int n, m;

const int height = (int)ceil(log2(N));
vector<pair<int, int>> g[N];
int level[N];
vector<vector<int>> LCA, LCASum;

void dfs(int u, int par, int lvl) {
    level[u] = lvl;

    for (auto it: g[u]) {
        int v = it.F, w = it.S;
        if (v != par) {
            dfs(v, u, lvl + 1);
        }
    }
}

void build(int u, int par, int wt) {
    LCA[u][0] = par;
    LCASum[u][0] = wt;
    
    for(int i = 1; i < height; i++) {
        int parNode = LCA[u][i - 1];
        if(parNode != -1) {
            LCA[u][i] = LCA[parNode][i - 1];
            LCASum[u][i] = LCASum[parNode][i - 1] + LCASum[u][i - 1];
        } else {
            LCA[u][i] = -1;
            LCASum[u][i] = 0;
        }
    }
    for(auto it: g[u]) {
        int v = it.F, w = it.S;
        if(v != par) {
            build(v, u, w);
        }
    }
}

int getLCA(int a, int b) {
    if(level[a] > level[b]) swap(a, b);

    int sum = 0;

    int d = level[b] - level[a];
    for(int i = height-1; i >= 0; i--) {
        if(d & (1 << i)) {
            sum += LCASum[b][i];
            b = LCA[b][i];
        }
    }

    if (a == b) return sum;

    for(int i = height - 1; i >= 0; i--) {
        if (LCA[a][i] != LCA[b][i]) {
            sum += LCASum[a][i];
            a = LCA[a][i];
            sum += LCASum[b][i];
            b = LCA[b][i];
        }
    }

    return sum + LCASum[a][0] + LCASum[b][0];
}

void solve() {
    int u, v, w, q;
    cin >> n;

    LCA.resize(N, vector<int>(height+1, -1));
    LCASum.resize(N, vector<int>(height+1, 0));

    f(i, n-1) {
        cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    dfs(1, -1, 0);
    build(1, -1, 0);

    cin >> q;
    while(q--) {
        cin >> u >> v;
        cout << getLCA(u, v) << endl;
    }
}
