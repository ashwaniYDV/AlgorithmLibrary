// https://codeforces.com/contest/20/problem/C
// https://github.com/Ashishgup1/Competitive-Coding/blob/master/Dijkstra.cpp

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
#define debug2(x,y) cout << (#x) <<", "<<(#y)<< " are: " << (x) <<", "<<(y)<< endl;
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
// #define endl "\n"
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;

// Dijkstra with Path:

int arrival[N], departure[N], vis[N], parent[N];
vector<pair<int, int> > g[N];
set<int> times[N];
 
void dijkstra(int source, int destination) {
	for(int i = 1; i <= n; i++) {
		arrival[i] = 1e18;
		departure[i] = 1e18;
		parent[i] = -1;
	}

	arrival[source] = 0;
	set<pair<int, int>> s;
	s.insert({0, source});

	while(!s.empty()) {
		auto x = *(s.begin());
		s.erase(x);
		int u = x.second;
		vis[u] = 1;
		departure[u] = arrival[u];

		for(auto it: g[u]) {
			int v = it.first;
			int w = it.second;
			if(arrival[v] > departure[u] + w) {
				s.erase({arrival[v], v});
				arrival[v] = departure[u] + w;
				s.insert({arrival[v], v});
				parent[v] = u;
			}
		}
	}

	if(!vis[destination]) {
		cout << "-1";
		return;
	}

	int node = destination;
	vector<int> ans;
	while(parent[node] != -1) {
		ans.push_back(node);
		node = parent[node];
	}
	ans.push_back(source);
	reverse(ans.begin(), ans.end());
	for(auto i: ans) {
		cout << i << " ";
	}
}
 
void solve() {
	int u, v, w;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> u>> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dijkstra(1, n);
}

int32_t main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
