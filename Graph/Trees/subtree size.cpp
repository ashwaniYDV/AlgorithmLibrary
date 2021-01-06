#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize "03"
#pragma GCC target("sse4")

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
const ll N = 1e5+5;
vl g[N];
ll a[N], b[N], dp[N], in[N], out[N], vis[N], level[N];
ll n, m;

ll subTreeSize[N];
ll dfs (ll u) {
	vis[u]=1;
	ll currSize=1;
	for (auto v: g[u]) {
		if (!vis[v]) {
			currSize+=dfs(v);
		}
	}
	subTreeSize[u]=currSize;
	return currSize;
}

void solve() {
	ll t,k,z,p,q,u,v,x,y,ct=0,flag=0;
	cin>>n;
	f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
	dfs(1);
	fa(i,1,n+1) cout<<"Subtree size of "<<i<<" is "<<subTreeSize[i]<<" \n";
}
 
int32_t main() {
	IOS
	ll _;
	// cin>>_;
	// while (_--)
		solve();
}
