// Single source shortest path for weighted graphs
// It fails for negative weights (in that case we can use bellman ford)


const int N = 1e5+5;
int n, m;
int dis[N], parent[N];
vector<pair<int, int> > g[N];
 
void dijkstra(int source, int destination) {
	for(int i = 1; i <= n; i++) {
		dis[i] = 1e18;
		parent[i] = -1;
	}

	dis[source] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, source});

	while(!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		int u = x.second;

		for(auto it: g[u]) {
			int v = it.first;
			int w = it.second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
				parent[v] = u;
			}
		}
	}

	if(dis[destination] == 1e18) {
		cout << "-1";
		return;
	}

	int node = destination;
	vector<int> ans;
	while(parent[node] != -1) {
		ans.push_back(node);
		node = parent[node];
	}
	ans.push_back(source);
	reverse(ans.begin(), ans.end());
	for(auto i: ans) {
		cout << i << " ";
	}
}
 
void solve() {
	int u, v, w;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> u>> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dijkstra(1, n);
}
