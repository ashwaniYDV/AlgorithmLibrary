// since it's for directed graph, therefore works for undirected as well

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

ll cycleDetected=0;
ll color[N]; // all white
map<ll,ll>vis;
void dfs(ll u, ll par){
	vis[u]=1;
	color[u]=1; // grey
	for(ll v: g[u]){
		if(color[v] == 1){
			// do anything you want when cycle detected
			cycleDetected=1;
		}
		if(color[v]==0)
			dfs(v,u);
	}
	color[u]=2; // black
}

int32_t main()
{
	IOS
	ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;
	string s;
	cin>>n>>m;
	f(i,m) cin>>u>>v, g[u].pb(v);
	fa(i,1,n+1){
		if(!vis[i]){
			dfs(i,0);
		}
	}
	if(cycleDetected){
		cout<<"Yes, there is/are cycle(s)";
	}else{
		cout<<"There is no cycle";
	}

}
