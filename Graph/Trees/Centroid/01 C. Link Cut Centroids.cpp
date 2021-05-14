// https://codeforces.com/problemset/problem/1406/C
// https://www.youtube.com/watch?v=ZWd1SbJeBV0


const int N = 2e5 + 5;
int n, m;

vi g[N];
int subtreeSize[N];
int centroid;
int leaf, anyOtherVertex;

void getCentroid(int u, int par) {
    // since we have removed a leaf (i.e. considering a new tree of size n-1)
    int graphSize = n - 1;
    subtreeSize[u] = 1;
    bool is_centroid = true;
    for (int v: g[u]) {
        // since we have removed a leaf (i.e. considering a new tree without this leaf)
        if (v == par || v == leaf) continue;

        getCentroid(v, u);
        subtreeSize[u] += subtreeSize[v];
        if (subtreeSize[v] > graphSize / 2) is_centroid = false;
    }
    if (graphSize - subtreeSize[u] > graphSize / 2)
        is_centroid = false;

    if (is_centroid)
        centroid = u;
}

void solve() {
    int u, v;
    cin >> n;

    for (int i = 1; i <= n; i++)
        g[i].clear(), subtreeSize[i] = 0;

    // if tree size is odd then we only have one centroid (so we will remove and ad the same edge for answer)
    pair < int, int > resPair;

    f(i, n - 1) {
        cin >> u >> v, g[u].pb(v), g[v].pb(u);
        resPair = {u, v};
    }

    if (n % 2) {
        cout << resPair.first << " " << resPair.second << endl;
        cout << resPair.first << " " << resPair.second << endl;
        return;
    }

    // case: tree size is even

    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) leaf = i;
        else anyOtherVertex = i;
    }

    getCentroid(anyOtherVertex, -1);

    int leafParent = g[leaf][0];
    // remove leaf from its parent
    cout << leaf << " " << leafParent << endl;
    // add leaf to the new centroid (where new centroid is calculated considering new tree after this leaf is detached)
    cout << centroid << " " << leaf << endl;
}

signed main() {
    IOS
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
