// check if a node is visited or not in a graph when started from 1 

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>n;a<n?i+=1:i-=1)
#define pb push_back
#define F first
#define S second
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

const ll mod = 1000000007;
const ll N = 3e5, M = N;
vl g[N];
ll a[N], dp[N];

 
vector <ll> adj[1222250];
map<ll,ll> visited;
void dfs(ll u){
	visited[u]=1;
	for(ll v: adj[u]){
		if(visited[v]) continue;
		dfs(v);
	}
}

 
int main()
{
	ios
	ll t,n,m,k,x,y,z,p,q,u,v;
	ll ct=0,flag=0;
	cin>>n>>m;
	f(i,m) cin>>u>>v, adj[u].pb(v), adj[v].pb(u);
	cin>>x;
	dfs(1);
	if(visited[x]) cout<<"Yes "<<x<<" is visited";
	else cout<<"No "<<x<<" is not visited";
}
