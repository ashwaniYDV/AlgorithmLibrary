// https://cses.fi/problemset/task/1133/
// https://youtu.be/nGhE4Ekmzbc
// https://youtu.be/lWCZOjUOjRc

/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the sum of the distances from the node to all other nodes.

Input:
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.
Then there are n−1 lines describing the edges. 
Each line contains two integers a and b: there is an edge between nodes a and b.
*/



// Method 1 (Re-rooting DP)
const int N = 2e5+5;
int n, m;

vector<int> g[N];
int subtreeSize[N];
int subtreeRes[N];
int res[N];

void dfs(int u, int par) {
    subtreeSize[u] = 1;
    subtreeRes[u] = 0;

    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u);
        subtreeSize[u] += subtreeSize[v];
        subtreeRes[u] += subtreeSize[v] + subtreeRes[v];
    }
}

void getRes(int u, int par, int parResWithoutCurChild) {
    res[u] = subtreeRes[u] + (parResWithoutCurChild + (n - subtreeSize[u]));
    for(int v: g[u]) {
        if(v == par) continue;
        getRes(v, u, res[u] - (subtreeRes[v] + subtreeSize[v]));
    }
}

void solve() {
    int u, v;
    cin >> n;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    dfs(1, -1);
    getRes(1, 0, 0);

    loop(i, 1, n) {
        cout << res[i] << " ";
    }
}























// Method 2 (my leetcode soln)
const int N = 2e5+5;
int n, m;

vector<int> g[N];
int subtreeSize[N];
int res[N];

void getSubtreeSize(int u, int par) {
    subtreeSize[u] = 1;
    for(int v: g[u]) {
        if(v == par) continue;
        getSubtreeSize(v, u);
        subtreeSize[u] += subtreeSize[v];
    }
}

void getRes(int u, int par) {
    for(int v: g[u]) {
        if(v == par) continue;
        res[v] = res[u] + (n - subtreeSize[v]) - subtreeSize[v];
        // res[v] = res[u] + n - 2 * subtreeSize[v];
        getRes(v, u);
    }
}

void solve() {
    int u, v;
    cin >> n;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    getSubtreeSize(1, -1);

    // calculating res[1]
    // sum of distance from root node is the sum of `subtreeSize` except the root itself
    for(int i = 2; i <= n; i++) {
        res[1] += subtreeSize[i];
    }

    // after getting the distance sum of root, we can deduce the distance sum of the other node.
    getRes(1, -1);

    loop(i, 1, n) {
        cout << res[i] << " ";
    }
}
