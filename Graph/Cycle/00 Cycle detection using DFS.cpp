bool dfs (ll u, ll par) {
	vis[u] = 1;
	for (auto v: g[u]) {
		if (!vis[v]) {
			if (dfs(v, u)) return true;
		} else {
			if(v != par) return true;
		}
	}
	return false;
}

void solve() {
	cin >> n >> m;
	f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);
	if (dfs(1, 0)) cout << "Cyclic";
	else cout << "Acyclic";
}
