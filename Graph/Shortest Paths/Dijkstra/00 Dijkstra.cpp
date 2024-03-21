/*
Single source shortest path for weighted graphs
It fails for negative weights (in that case we can use bellman ford)

TC = O(E*logV)
Worst cace TC = O(E*V) = O(n^2)

Resources
=========
https://youtu.be/XB4MIexjvY0?si=6RgT8zXWYmrDe7gJ
https://youtu.be/V6H1qAeB-l4?si=ceG_YhrrftjzU0Ym
https://youtu.be/PATgNiuTP20?si=47mYXSs_MFKpxSHe
https://youtu.be/3dINsjyfooY?si=gsmCRxlOgmDbCPOS
*/




const int N = 1e5+5;
int n, m;

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
        ll cost = x.first;

        if(cost > dp[u]) continue;

        for(pll y: adj[u]){
            if(dp[y.first] > dp[u] + y.second){
                dp[y.first] = dp[u] + y.second;
                pq.push({dp[y.first], y.first});
            }
        }
    }
}
















vl g[N], dist;
ll a[N], b[N], dp[N], in[N], out[N], level[N];
ll n, m;

vector<pair<ll,ll>> adj[N];
void dijkstra(ll source){
    for (ll i = 1; i <= n; i++) dp[i] = INT_MAX;

    dp[source] = 0;
    set<pair<ll,ll>> s;
    s.insert({dp[source], source});
	while (!s.empty()){
	    ll u = s.begin()->second;
	    s.erase(s.begin());
	    for (auto v : adj[u]) {
	        ll a = v.first, b = v.second;
	        if (dp[u]+b < dp[a]){
	        	s.erase({dp[a], a});
	        	dp[a] = dp[u]+b;
	        	s.insert({dp[a], a});
	       	}
	    }
	}
}

void solve() {
	cin>>n>>m;
	f(i,m) cin>>u>>v>>k, adj[u].pb({v, k}), adj[v].pb({u, k});
	cin>>x;
	dijkstra(x);
	for(ll i=1; i<=n; i++){
		cout<<dp[i]<<" ";
	}
}
















vl g[N], dist;
ll a[N], b[N], dp[N], in[N], out[N], level[N];
ll n, m;
 
vector<pair<ll,ll>> adj[N];
void dijkstra(ll source){
	ll INF=1e18;
	f(i, n+1) dp[i]=INF;
	dp[source] = 0;

	set<pair<ll,ll>> s;
	for(ll i=1;i<=n;i++){
		if(i!=source)
		s.insert({INF, i});
	}
	s.insert({0, source});
 
	while(!s.empty()){
       ll a=s.begin()->first;
       ll u=s.begin()->second;
       s.erase(s.begin());
 
       for(auto i: adj[u]){																			
            ll to=i.first;
            ll w=i.second;
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
	f(i,m) cin>>u>>v>>k, adj[u].pb({v, k}), adj[v].pb({u, k});
	cin>>x;
 	dijkstra(x);
	
	for(ll i=1; i<=n; i++)
		cout<<dp[i]<<" ";
}
