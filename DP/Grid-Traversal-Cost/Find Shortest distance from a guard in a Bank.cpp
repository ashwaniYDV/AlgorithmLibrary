// https://www.geeksforgeeks.org/find-shortest-distance-guard-bank

/*
Multi Source Shortest Path in Unweighted Graph:
https://www.geeksforgeeks.org/multi-source-shortest-path-in-unweighted-graph/
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
const int N = 2e5+5;
int n, m;

vector<vector<char>> grid;
vector<vector<int>> vis, ans;

struct node {
	int i, j, dist;
};

bool isSafe(int i, int j) {
	if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == 'W')
		return false;
	return true;
}

void bfs() {
	queue<node> q;
	f(i, n) {
		f(j, m) {
			if(grid[i][j] == 'G') {
				q.push({i, j, 0});
				vis[i][j] = 1;
				ans[i][j] = 0;
			}
			if(grid[i][j] == 'W') {
				ans[i][j] = -1;
			}
		}
	}

	while(!q.empty()) {
		node x = q.front();
		q.pop();

		f(z, 4) {
			int i = x.i + dx[z], j = x.j + dy[z];
			if(!isSafe(i, j)) continue;
			vis[i][j] = 1;
			ans[i][j] = x.dist + 1;
			q.push({i, j, ans[i][j]});
		}
	}

	f(i, n) {
		f(j, m) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

void solve() {
    grid = {
    	{'O', 'O', 'O', 'O', 'G'},
        {'O', 'W', 'W', 'O', 'O'},
        {'O', 'O', 'O', 'W', 'O'},
        {'G', 'W', 'W', 'W', 'O'},
        {'O', 'O', 'O', 'O', 'G'}
    };
    n = grid.size();
    m = grid[0].size();
    vis.resize(n, vector<int>(m, 0));
    ans.resize(n, vector<int>(m, 0));
    bfs();
}

int32_t main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
