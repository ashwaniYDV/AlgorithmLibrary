#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>n;a<n?i+=1:i-=1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;

const ll mod = 1000000007;
const ll N = 1e6+5, M = N, ninf = -2e5, inf = 1e7;
vl g[N], dist;
ll a[N], b[N], dp[N], in[N], out[N], vis[N], level[N];
ll n, m;


void bfs_custom(ll start){
	queue<ll>q;
	q.push(start);
	vis[start]=1;
	dp[start]=0;

	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(ll v: g[u]){
			if(vis[v]) continue;
			dp[v]=dp[u]+1;
            q.push(v);
            vis[v]=1;
		}
	}
}

void dfs_custom (ll u, ll dis) {
	vis[u]=1;
	dp[u] = dis;
	for (auto v: g[u]) {
		if (!vis[v]) {
			dfs(v, dis+1);
		}
	}
}


int32_t main()
{
	IOS
	ll k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n>>m;
	f(i,m) cin>>u>>v, g[u].pb(v), g[v].pb(u);
	cin>>x;
	// method1 bfs
	bfs_custom(x);
	// method2 dfs
// 	dfs_custom(x);
	fa(i,1,n+1)cout<<dp[i]<<" ";
}
