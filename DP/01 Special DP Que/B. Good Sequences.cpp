// https://codeforces.com/contest/264/problem/B

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int N = 1e5+5;
int n, m;
 
int dp[N+5]; // dp[x] = maximum length of good sequence upto number x
int dpDiv[N+5];
 
vi getDivisors(int n) {
	// all divisors except 1
	vi div;
	for(int i=2; i*i <= n; i++) {
		if(n % i == 0) {
			div.pb(i);
			if(i != n/i)
				div.pb(n/i);
		}
	}
	div.pb(n);
 
	return div;
}
 
void solve() {
	int x, y, z;
 
	cin >> n;
	vi a(n);
	f(i, n) {
		cin >> a[i];
		dp[a[i]] = 1;
	}
 
	int res = 1;
 
	for(int i = 0; i < n; i++) {
		x = a[i];
		vi div = getDivisors(x);
 
		for(int d: div) {
			dp[x] = max(dp[x], dpDiv[d] + 1);
		}
 
 
		for(int d: div) {
			dpDiv[d] = dp[x];
		}
 
		res = max(res, dp[x]);
	}
	
	cout << res << endl;
}
 
signed main() {
	IOS
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
} 
