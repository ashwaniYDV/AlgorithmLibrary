// https://www.codechef.com/ZCOPRAC/problems/ZCO14004
// https://unacademy.com/class/learn-dp-through-problem-solving-3/URYJEHRL

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
const int MAXN = 1e5+5;
const int N = 2e5+5;
int n, m;

int goDp[N][3];

int go(int pos, int state, vi& a) {
	if(pos >= n) return 0;

	if(goDp[pos][state] != -1) return goDp[pos][state]; 

	int x = 0, y = 0;
	if(state < 2) {
		x = a[pos] + go(pos+1, state+1, a);
	}
	y = go(pos+1, 0, a);

	return goDp[pos][state] = max(x, y);
}

void solve() {
	cin >> n;
	vi a(n);
	f(i, n) cin >> a[i];
	memset(goDp, -1, sizeof goDp);
	cout << go(0, 0, a) << endl;

	int dp[n+1] = {0};
	
	dp[0] = a[0];
	dp[1] = a[0] + a[1];
	dp[2] = max({a[0]+a[1], a[0]+a[2], a[1]+a[2]});
	
	fa(i, 3, n) {
		dp[i] = max({dp[i-1], a[i] + dp[i-2], a[i] + a[i-1] + dp[i-3]});
	}

	cout << dp[n-1] << endl;
}
 
int32_t main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
