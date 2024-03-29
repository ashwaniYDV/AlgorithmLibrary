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
 
vector<int> g[N];
 
pair<int, int> bfs(int root) {
	vector<int> depth(n+1, 0);
	queue<int> q;
	q.push(root);
	depth[root] = 0;
 
	while(!q.empty()) {
		int u = q.front();
        q.pop();
 
		for(int v: g[u]) {
			if(depth[v] || v == root) continue;
            depth[v] = depth[u] + 1;
            q.push(v);
		}
	}

	int pos = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		if(depth[i] > mx) {
			mx = depth[i];
			pos = i;
		}
	}

	return {pos, mx};
}

void dfs(int u, int par, int d, vector<int>& depth) {
	depth[u] = d;
	for(int v: g[u]) {
		if(v == par) continue;
		dfs(v, u, d + 1, depth);
	}
}

void diameterOfTreeBFS() {
	pair<int, int> x = bfs(1);
	int diameter = bfs(x.first).second;
	cout << diameter << endl;
	// cout << diameter + 1<< endl;
}

void diameterOfTreeDFS() {
	vector<int> depth(n+1, 0);
	dfs(1, -1, 0, depth);
	int pos = 0, mx = 0;
	for(int i = 1; i <= n; i++) {
		if(depth[i] > mx) {
			mx = depth[i];
			pos = i;
		}
	}
	depth.resize(n+1, 0);
	dfs(pos, -1, 0, depth);

	int diameter = 0;
	for(int i = 1; i <= n; i++) {
		diameter = max(diameter, depth[i]);
	}

	cout << diameter << endl;
	// cout << diameter +1 << endl;
}

void solve() {
	int u, v;
	cin >> n;
	for(int i = 1; i <= n-1; i++) {
		cin >> u>> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	diameterOfTreeBFS();
	diameterOfTreeDFS();
}
 
int32_t main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}

/*
Input:
5
1 2
1 3
2 4
2 5

Output:
3
3
*/
