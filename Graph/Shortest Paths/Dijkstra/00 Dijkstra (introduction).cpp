/*
Single source shortest path for weighted graphs
It fails for negative weights (in that case we can use Bellman Ford)

TC = O(E*logV) = O(n*logn)

Note:
=====
* We can use normal queue also instead of priority_queue, but time complexity will be more
* Dijkstra is a greedy algorithm due to priority_queue

Resources:
==========
Abdul bari
    * https://youtu.be/XB4MIexjvY0?si=6RgT8zXWYmrDe7gJ
Take u forward (strive)
    * https://youtu.be/V6H1qAeB-l4?si=ceG_YhrrftjzU0Ym
    * using set ==> https://youtu.be/PATgNiuTP20?si=47mYXSs_MFKpxSHe
    * Time complexity ==> https://youtu.be/3dINsjyfooY?si=gsmCRxlOgmDbCPOS
*/




const int N = 1e5+5;
int n, m;

vector<pair<int, int>> adj[N];
void dijkstra(int source) {
    for(int i = 0; i <= n; i++) {
		dp[i] = INF;
	}

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, source});
    dp[source] = 0;

    while(!pq.empty()){
        pair<int, int> x = pq.top();
        pq.pop();

        int u = x.second;
        int cost = x.first;

        if(cost > dp[u]) continue;

        for(pair<int, int> y: adj[u]){
			int v = y.first, w = y.second;
            if(dp[v] > dp[u] + w) {
                dp[v] = dp[u] + w;
                pq.push({dp[v], v});
            }
        }
    }
}
















vector<int> g[N], dist;
int a[N], b[N], dp[N], in[N], out[N], level[N];
int n, m;

vector<pair<int,int>> adj[N];
void dijkstra(int source){
    for (int i = 1; i <= n; i++) dp[i] = INT_MAX;

    set<pair<int,int>> s;
    s.insert({0, source});
	dp[source] = 0;

	while (!s.empty()){
	    int u = s.begin()->second;
	    s.erase(s.begin());

	    for (auto it : adj[u]) {
	        int v = it.first, w = it.second;
	        if (dp[v > dp[u]+w]) {
	        	s.erase({dp[v], v});
	        	dp[v] = dp[u]+w;
	        	s.insert({dp[v], v});
	       	}
	    }
	}
}

void solve() {
	cin>>n>>m;
	for(int i = 0; i < m; i++) cin>>u>>v>>k, adj[u].pb({v, k}), adj[v].pb({u, k});
	cin>>x;
	dijkstra(x);
	for(int i=1; i<=n; i++){
		cout<<dp[i]<<" ";
	}
}
















vector<int> g[N], dist;
int a[N], b[N], dp[N], in[N], out[N], level[N];
int n, m;
 
vector<pair<int,int>> adj[N];
void dijkstra(int source){
	int INF=1e18;
	f(i, n+1) dp[i]=INF;
	dp[source] = 0;

	set<pair<int,int>> s;
	for(int i=1;i<=n;i++){
		if(i!=source)
		s.insert({INF, i});
	}
	s.insert({0, source});
 
	while(!s.empty()){
       int a=s.begin()->first;
       int u=s.begin()->second;
       s.erase(s.begin());
 
       for(auto i: adj[u]){																			
            int to=i.first;
            int w=i.second;
            if(dp[to] > dp[u] + w){
            	s.erase({dp[to],to});
            	dp[to]=dp[u]+w;
                s.insert({dp[to],to});
            }
       }
	}
} 


void solve() {
	cin>>n>>m;
	for(int i = 0; i < m; i++) cin>>u>>v>>k, adj[u].pb({v, k}), adj[v].pb({u, k});
	cin>>x;
 	dijkstra(x);
	
	for(int i=1; i<=n; i++)
		cout<<dp[i]<<" ";
}
