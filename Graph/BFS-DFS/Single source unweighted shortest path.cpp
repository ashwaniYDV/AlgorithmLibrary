void bfs_custom(ll start) {
    queue < ll > q;
    q.push(start);
    vis[start] = 1;
    dp[start] = 0;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v: g[u]) {
            if (vis[v]) continue;
            dp[v] = dp[u] + 1;
            q.push(v);
            vis[v] = 1;
        }
    }
}

void dfs_custom(ll u, ll dis) {
    vis[u] = 1;
    dp[u] = dis;
    for (auto v: g[u]) {
        if (!vis[v]) {
            dfs(v, dis + 1);
        }
    }
}

int32_t main() {
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    cin >> x;
    // method1 bfs
    bfs_custom(x);
    // method2 dfs
    // 	dfs_custom(x);
    fa(i, 1, n + 1) cout << dp[i] << " ";
}
