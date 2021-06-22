// Single source shortest path for weighted graphs
// It fails for negative weights (in that case we can use bellman ford)


vector<pll> adj[N];
void dijkstra(ll source){
	f(i,n+1) dp[i]=inf;
    priority_queue <pll, vector<pll>, greater<pll> > pq;
    pq.push({0, source});
    dp[source] = 0;

    while(!pq.empty()){
        pll x = pq.top();
        pq.pop();

        ll u = x.second;

        // if(dp[u] < x.first) continue;

        for(pll y: adj[u]){
            if(dp[y.first] > dp[u] + y.second){
                dp[y.first] = dp[u] + y.second;
                pq.push({dp[y.first], y.first});
            }
        }
    }
}

int32_t main()
{
	IOS
	ll k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n>>m;
	f(i,m) cin>>u>>v>>x, adj[u].pb({v,x}), adj[v].pb({u,x});
	cin>>x;
	dijkstra(x);
	for(ll i=1; i<=n; i++){
		cout<<"Distance of "<<i<<" from "<<x<<" is "<<dp[i]<<endl;
	}
}























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
