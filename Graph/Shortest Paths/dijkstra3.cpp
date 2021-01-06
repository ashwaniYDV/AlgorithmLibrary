// Single source shortest path for weighted graphs
// It fails for negative weights (in that case we can use bellman ford)

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
const ll N = 1e6+5, M = N, ninf = -2e5, inf = 10000000;
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


int32_t main()
{
	IOS
	ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n>>m;
	f(i,m) cin>>u>>v>>k, adj[u].pb({v, k}), adj[v].pb({u, k});
	cin>>x;
 	dijkstra(x);
	
	for(ll i=1; i<=n; i++)
		cout<<dp[i]<<" ";
}
