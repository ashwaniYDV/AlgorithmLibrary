// https://codeforces.com/problemset/problem/1195/C

#include<bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
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
const int MAXN = 1e3+5;
const int N = 1e5+5;
int n, m, k;

// int dp[N][2];
// int go(int pos, int state, vector<vector<int>>& a) {
// 	if(pos >= n) return 0;

// 	if(dp[pos][state] != -1) return dp[pos][state];

// 	int x = 0, y = 0;
// 	x = a[pos][state] + go(pos + 1, 1 - state, a);
// 	y = go(pos + 1, state, a);

// 	return dp[pos][state] = max(x, y);
// }

void solve() {
	int x, y;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(2));
	f(i, n) cin >> a[i][0];
	f(i, n) cin >> a[i][1];

	// memset(dp, -1, sizeof dp);
	// cout << max(go(0, 0, a), go(0, 1, a)) << endl;

	vector<vector<int>> dp(n, vector<int>(3, 0));
	dp[0][0] = a[0][0], dp[0][1] = a[0][1], dp[0][2] = 0;

	fa(i, 1, n) {
		dp[i][0] = max({dp[i-1][1] + a[i][0], dp[i-1][2] + a[i][0], a[i][0]});
		dp[i][1] = max({dp[i-1][0] + a[i][1], dp[i-1][2] + a[i][1], a[i][1]});
		dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
	}

	cout << max({dp[n-1][0], dp[n-1][1]}) << endl;
}

int32_t main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
