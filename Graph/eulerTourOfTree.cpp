// euler tour of tree
// beween any indice is all the nodes in the subtree of this indice

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug cout << "debug" << endl;
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>=n;a<n?i+=1:i-=1)
#define loop(i,a, n) for(ll i = a; i <= n; i++)
#define loopb(i,a, n) for(ll i = a; i >= n; i--)
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
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e3+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
vl g[N];
ll n, m;
ll eulertour[2*N], vis[N];

ll idx = 0;

void dfs_euler_tour(ll u) {
	vis[u] = 1;
	eulertour[idx++] = u;
	for(ll v: g[u]){
		if(!vis[v]){
			dfs_euler_tour(v);
			eulertour[idx++] = u;
		}
	}
}

void solve() {
	ll u, v, root;
	cin >> n;
	f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
	cin >> root;
	dfs_euler_tour(root);
	f(i, 2*n-1) cout << eulertour[i] << " ";
}

int32_t main() {
	IOS
	ll T;
	// cin >> T;
	// while(T--)
	solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}

/*
Input
4
1 2
2 3
2 4
1

Output
1 2 3 2 4 2 1 
*/
