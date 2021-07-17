// https://codeforces.com/problemset/problem/696/B

/*
Expected value[v] = Expected value[u] + (1 / 2) * (x + y)
where x = 1 and y = subtreesize[u] - subtreesize[v]
*/

ld expected[100001];
vector<int> g[100001];
int subtreeSize[100001];

void dfsSubtree(int u, int p) {
    subtreeSize[u] = 1;
    for(int v: g[u]) {
        if(v != p) {
            dfsSubtree(v, u);
            subtreeSize[u] += subtreeSize[v];
        }
    }
}
void dfs(int u, int p) {
    for(int v: g[u]) {
        if(v != p) {
            int x = 1;
            int y = subtreeSize[u] - subtreeSize[v];
            expected[v] = expected[u] + (x + y) / 2.00;
            dfs(v, u);
        }
    }
}

void solve() {
    int x, y, z, k;
    cin >> n;
    loop(i, 2, n) {
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    expected[1] = 1;
    dfsSubtree(1, -1);
    dfs(1, -1);
    loop(i, 1, n) cout << expected[i] << " ";

}
