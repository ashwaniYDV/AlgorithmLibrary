// https://www.codechef.com/CCHI2021/problems/CCBTS05

// TLE 
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_map;
// methods: find_by_order(k); & order_of_key(k); To make it an ordered_multiset, use pairs of (value, time_of_insertion) to distinguish values which are similar
 
typedef long long int ll;
#define int long long int
#define ld long double
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debug2(x,y) cerr << (#x) <<", "<<(#y)<< " are: " << (x) <<", "<<(y)<< endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define kickstart(testcase, res) cout << "Case #" << testcase << ": " << res << endl;
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for(int i=a;i<n;i++)
#define loop(i,a, n) for(int i = a; i <= n; i++)
#define loopb(i,a, n) for(int i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;

vector<pii> g[N];

ll level[N];
ll height = (ll)ceil(log2(N));

// LCA[i][j] represents 2^(j)th parent of node i
// ll LCA[N][(ll)ceil(log2(N))+1];
vector<vector<int>> LCA(N, vector<int>((ll)ceil(log2(N))+1, 0));

void dfs(ll u, ll lvl, ll par) {
	level[u] = lvl;
	LCA[u][0] = par;

	for(auto i: g[u]) {
		int v = i.F, w = i.S;
		if(v != par) {
			dfs(v, lvl + w, u);
		}
	}
}

void init(int root) {
	// initializing parent and level of each node
	dfs(root, 0, 0);

	for(ll i = 1; i <= height; i++) {
		for(ll node = 1; node <= n; node++) {
			if(LCA[node][i-1] != -1) {
				ll parNode = LCA[node][i - 1];
				LCA[node][i] = LCA[parNode][i - 1];
			}else{
				LCA[node][i] = -1;
			}
		}
	}
}

ll getLCA(ll a, ll b) {
	if(level[b] < level[a]) swap(a, b);

	ll d = level[b] - level[a];

	// method 1
	// for(ll i = 18; i >= 0; i--){
	// 	if(d & (1<<i)) b = LCA[b][i];
	// }

	// method 2
	while(d) {
		ll i = log2(d);
		b = LCA[b][i];
		d -= (1 << i);
	}

	if(a == b) return a;

	for(ll i = height; i >= 0; i--){
		if(LCA[a][i] != LCA[b][i]){
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}
	// parent of a or b
	return LCA[a][0];
}

ll getDistance(ll a, ll b) {
	ll lca = getLCA(a, b);
	return (level[a] + level[b] - 2 * level[lca]);
}
 
void solve() {
	ll u, v, w, q, root;
	cin >> n >> q >> root;

	f(i, n+4) {
		g[i].clear();
		level[i] = 0;
	}
	height = (ll)ceil(log2(N));
	LCA.resize(N, vector<int>((ll)ceil(log2(N))+1, 0));

	f(i, n-1) {
		cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
	}

	init(root);
	while(q--) {
		cin >> u >> v;
		cout << getDistance(u, v) << endl;
	}


}

int32_t main() {
	IOS
	int T = 1;
	cin >> T;
	while(T--)
	solve();
	return 0;
}
