// https://youtu.be/MtFPqCcsoeA
/*
No cycle or Even cycle graph -> Bipartite
Odd cycle graph -> Not-Bipartite
*/

#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>=n;a<n?i+=1:i-=1)
#define rep(i,a, n) for(i = a; i < n; i++)
#define ren(i,a, n) for(i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setmem(x, k) memset(x, k, sizeof(x))
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
const ll N = 1e6+5, M = N, ninf = -2e5, inf = (int)1e9;
vl g[N];
// ll a[N], b[N], dp[N], in[N], out[N], vis[N], level[N];
ll n, m;


ll vis[N], color[N];

bool dfs(ll u, ll c){
	vis[u]=1;
	color[u]=c;
	for(ll v: g[u]){
		if(!vis[v]){
			if(dfs(v, c^1) == false) return false;
		}else{
			if(color[v]==color[u]) return false;
		}
	}
	return true;
}

int32_t main()
{
	IOS
	ll t,k,z,p,q,u,v,x,y,ct=0,flag=0;
	cin>>n>>m;
	f(i,m) cin>>u>>v, g[u].pb(v), g[v].pb(u);
	bool check=true;
	fa(i,1,n+1){
		if(!vis[i])
			check=check && dfs(i,1);
	}
	if(check)
		cout<<"Graph is bipartite.";
	else
		cout<<"Graph is not bipartite.";
}
