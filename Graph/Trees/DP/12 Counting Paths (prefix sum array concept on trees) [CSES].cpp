// https://cses.fi/problemset/task/1136/
// https://youtu.be/8Nq3THy2Kw0

/*
You are given a tree consisting of n nodes, and m paths in the tree.
Your task is to calculate for each node the number of paths containing that node.

Input:
The first input line contains integers n and m: the number of nodes and paths. The nodes are numbered 1,2,…,n.
Then there are n−1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Finally, there are m lines describing the paths. Each line contains two integers a and b: there is a path between nodes a and b.

Output:
Print n integers: for each node 1,2,…,n, the number of paths containing that node.

Example
Input:
5 3
1 2
1 3
3 4
3 5
1 3
2 5
1 4

Output:
3 1 3 1 1
*/


const int N = 2e5 + 5;
int n, m;

vector<int> g[N];
const int height = 25;
int LCA[N][height + 5], level[N];
int prefRes[N];

void dfs(int u, int par, int lvl) {
    level[u] = lvl;
    LCA[u][0] = par;

    for (int v : g[u]) {
        if (v != par) {
            dfs(v, u, lvl + 1);
        }
    }
}


void init() {
    dfs(1, -1, 0);

    for (int i = 1; i <= height; i++) {
        for (int node = 1; node <= n; node++) {
            int parNode = LCA[node][i - 1];
            if (parNode != -1) {
                LCA[node][i] = LCA[parNode][i - 1];
            } else {
                LCA[node][i] = -1;
            }
        }
    }
}

int getLCA(int a, int b) {
    if (level[b] < level[a]) swap(a, b);

    int d = level[b] - level[a];

    for (int i = height; i >= 0; i--) {
        if (d & (1 << i)) b = LCA[b][i];
    }

    if (a == b) return a;

    for (int i = height; i >= 0; i--) {
        if (LCA[a][i] != LCA[b][i]) {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    // parent of a or b
    return LCA[a][0];
}


void dfsToComputePref(int u, int par) {
    for (int v : g[u]) {
        if (v != par) {
            dfsToComputePref(v, u);
            prefRes[u] += prefRes[v];
        }
    }
}

void solve() {
    int u, v, a, b;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    init();

    while (m--) {
        cin >> a >> b;
        int lca = getLCA(a, b);

        prefRes[a] += 1;
        prefRes[b] += 1;
        prefRes[lca] -= 1;

        int parLCA = LCA[lca][0];
        if (parLCA != -1) {
            prefRes[parLCA] -= 1;
        }
    }

    dfsToComputePref(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << prefRes[i] << " ";
    }
}
