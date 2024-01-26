// https://codeforces.com/blog/entry/81827

/*
Question asked in Google online coding challenge on 22nd AUG, 2020.

You are given a tree with N nodes numbered 1 to N. Each node is having weight Ai.
Find the maximum path sum between any two node u and v of the tree. Return the maximum path sum value. 

Constraints:
1 <= N <= 1e4
-1e6 <= Ai <= +1e6
*/

const int N = 1e5+5;
int n, m;

vi g[N];
int heightSum[N], a[N];
int res;

void dfs(int u, int par) {
    heightSum[u] = a[u];
    int mx1 = 0, mx2 = 0, child = 0;

    for (int v: g[u]) {
        if(v == par) continue;

        dfs(v, u);

        heightSum[u] = max(heightSum[u], a[u] + heightSum[v]);

        if(heightSum[v] > mx1) {
            mx2 = mx1;
            mx1 = heightSum[v];
        } else if(heightSum[v] > mx2) {
            mx2 = heightSum[v];
        }

        child++;
    }

    res = max(res, heightSum[u]);

    if(child >= 2) {
        res = max(res, a[u] + mx1 + mx2);
    }
} 

void solve() {
    int u, v;
    cin >> n;
    loop(i, 1, n) cin >> a[i];
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    
    res = -INF;
    dfs(1, -1);
    cout << res << endl;
}
