// https://codeforces.com/contest/1133/problem/F1

// // Method DFS
const int N = 2e5+5;
int n, m; 
vpii res;
int vis[N];
vi g[N];

void dfs(int u) {
	vis[u] = 1;

	for(int v: g[u]) {
		if(vis[v]) continue;
		res.pb({u, v});
		dfs(v);
	}
}

void solve() { 
	int u, v;
    cin >> n >> m;
    while(m--) {
    	cin >> u >> v;
    	g[u].pb(v); 
    	g[v].pb(u);
    }

    int mx = 0, vertex = 0;
    loop(i, 1, n) {
    	if(g[i].size() > mx) {
    		vertex = i;
    		mx = g[i].size();
    	}
    }

    vi temp;
    vis[vertex] = 1;

    for(int v: g[vertex]) {
    	res.pb({vertex, v});
    	temp.pb(v);
    	vis[v] = 1;
    }

    for(int u: temp) {
    	dfs(u);
    }

    for(auto i: res) {
    	cout << i.F << " " << i.S << endl;
    }
} 
























// Method BFS
const int N = 2e5+5;
int n, m; 

vpii res;
int vis[N];
vi g[N];

void bfs(int root) {
	queue<int> q;
	q.push(root);
	vis[root] = 1;

	while(q.size()) {
		int u = q.front();
		q.pop();

		for(int v: g[u]) {
			if(vis[v]) continue;

			res.pb({u, v});
			vis[v] = 1;
			q.push(v);
		}
	}
}

void solve() { 
	int u, v;
    cin >> n >> m;
    while(m--) {
    	cin >> u >> v;
    	g[u].pb(v); 
    	g[v].pb(u);
    }

    int mx = 0, vertex = 0;
    loop(i, 1, n) {
    	if(g[i].size() > mx) {
    		vertex = i;
    		mx = g[i].size();
    	}
    }

    bfs(vertex);

    for(auto i: res) {
    	cout << i.F << " " << i.S << endl;
    }
} 
