// https://youtu.be/l6aA9a_x3gE
// https://cses.fi/problemset/task/1131/

/*
Diameter of binary tree concept:

The question can be solved by small modification to program of Height of tree.
The idea is max value of Height(leftSubtree)+Height(rightSubtree) (at any node ) is the diameter. 
Keep track of maxium diameter duing traversal and find the height of the tree.

So although the longest path doesn't have to go through the root node, it has to pass the root node of some subtree of the tree 
(because it has to be from one leaf node to another leaf node, otherwise we can extend it for free). 
*/

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
#define UNIQUE(a) sort(a.begin(), a.end() ); a.erase( unique( a.begin(), a.end() ), a.end() );
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
#define endl "\n"
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 2e5+5;
int n, m;

vi g[N];
int height[N];
int diameter = 0;

void dfs(int u, int par) {
	height[u] = 0;
	int mx1 = 0, mx2 = 0, child = 0;

	for (int v: g[u]) {
		if(v == par) continue;

		dfs(v, u);

		height[u] = max(height[u], 1 + height[v]);

		if(height[v] > mx1) {
			mx2 = mx1;
			mx1 = height[v];
		} else if(height[v] > mx2) {
			mx2 = height[v];
		}

		child++;
	}

	diameter = max(diameter, height[u]);

	if(child >= 2) {
		diameter = max(diameter, 2 + mx1 + mx2);
	}
} 

void solve() {
	int u, v;
	cin >> n;
	f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
	dfs(1, -1);
	cout << diameter << endl;
}

signed main() {
	IOS
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
} 
