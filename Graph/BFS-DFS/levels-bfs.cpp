vl g[N];
ll a[N], dp[N], level[N], in[N], out[N];
ll n, m;

void bfs(ll start){
	queue<ll>q;
	q.push(start);
	map<ll,ll>vis;
	vis[start]=1;
	level[start]=0;

	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(ll v: g[u]){
			if(vis[v]) continue;
			q.push(v);
			level[v]=level[u]+1;
			vis[v]=1;
		}
	}
}
 
int32_t main() {
	cin>>n;
	f(i,n-1) cin>>u>>v, g[u].pb(v), g[v].pb(u);
	ll arr[n];
	f(i,n) cin>>arr[i];
	bfs(1);
	fa(i,1,n+1){
		cout<<level[i]<<" ";
	}
}
