vector<int> g[N];
int vis[N];
vector<pair<int, int>> tree;

void dfs(int u) {
	vis[u] = 1;

	for(int v: g[u]) {
		if(vis[v]) continue;
		tree.push_back({u, v});
		dfs(v);
	}
}

void solve() {
	int u, v;
	cin >> n >> m;
	f(i, m) {
		cin >> u>> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);
	for(auto i: tree) cout << i.F << " " << i.S << endl;
}

/*
Input: 
5 7
1 2
1 5
2 4
2 5
5 4
2 3
4 3

1----2
|  / |\
| /	 | \3
|/   | / 
5----4/

Output:
1 2
2 4
4 5
4 3

1----2
     | 
   	 |  3
     | / 
5----4/
*/
