// https://youtu.be/eCG3T1m7rFY

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
const ll N = 1e6+5, M = N, ninf = -2e5, inf = (int)1e9;
vl g[N];
ll a[N], b[N], dp[N], in[N], out[N], vis[N], level[N];
ll n, m;
 
bool dfs (ll u, ll par) {
	vis[u]=1;
	for (auto v: g[u]) {
		if (!vis[v]) {
			if (dfs(v, u)) return true;
		} else {
			if(v != par) return true;
		}
	}
	return false;
}

void solve() {
	ll t,k,z,p,q,u,v,x,y,ct=0,flag=0;
	cin >> n >> m;
	f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);
	if (dfs(1, 0)) cout << "Cyclic";
	else cout << "Acyclic";
}
 
int32_t main() {
	IOS
	ll _;
	// cin>>_;
	// while (_--)
		solve();
	cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
}
