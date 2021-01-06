#include<bits/stdc++.h>
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
const ll N = 3e5, M = N, ninf = -2e5;
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
 
int32_t main()
{
	IOS
	ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n;
	f(i,n-1) cin>>u>>v, g[u].pb(v), g[v].pb(u);
	ll arr[n];
	f(i,n) cin>>arr[i];
	bfs(1);
	fa(i,1,n+1){
		cout<<level[i]<<" ";
	}
}
