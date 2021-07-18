// https://cses.fi/problemset/task/1688/
// https://youtu.be/s9zZOVsF_eo?si=8jIcu5tDx99iepM7

const int N = 2e5+5;
int n, m;
 
vector<int> g[N];
const int height = 30;
int LCA[N][height + 1];
int level[N], parent[N];

void dfs(int u, int par, int lvl) {
    level[u] = lvl;
    for (auto v: g[u]) {
        if (v != par) {
            dfs(v, u, lvl + 1);
        }
    }
}

void init() {
    dfs(1, -1, 0);

    loop(i, 1, n) {
        LCA[i][0] = parent[i];
    }

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

    // method 1
    b = getKthAncestor(b, d);

    // method 2
    // while(d) {
    //     int i = log2(d);
    //     b = LCA[b][i];
    //     d -= (1 << i);
    // }

    if (a == b) return a;

    for(int i = height - 1; i >= 0; i--) {
        if (LCA[a][i] != LCA[b][i]) {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }

    return LCA[a][0];
}

void solve() {
    int u, v, q;
    cin >> n >> q;

    parent[1] = -1;
    loop(i, 2, n) {
        cin >> u;
        parent[i] = u;
        g[u].pb(i), g[i].pb(u);
    }

    init();

    while(q--) {
        cin >> u >> v;
        cout << getLCA(u, v) << endl;
    }
}
