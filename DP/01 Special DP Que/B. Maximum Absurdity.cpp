// https://codeforces.com/contest/332/problem/B

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
 
 
void solve() {
	int x, y, z, k;
	cin >> n >> k;
	vi a(n);
	f(i, n) cin >> a[i];
 
	m = n - k + 1;
	vi b(m);
 
	f(i, k) b[0] += a[i];
 
	for(int i = k; i < n; i++) {
		b[i - k + 1] = b[i - k] + a[i] - a[i - k];
	}
 
	vpii prefMax(m);
	prefMax[0] = {b[0], 0};
 
	for(int i = 1; i < m; i++) {
		if(b[i] > prefMax[i - 1].F) {
			prefMax[i] = {b[i], i};
		} else {
			prefMax[i] = prefMax[i - 1];	
		}
	}
	int pos1, pos2;
	int mx = 0;
 
	for(int i = k; i < m; i++) {
		if(b[i] + prefMax[i - k].F > mx) {
			mx = b[i] + prefMax[i - k].F;
			pos1 = prefMax[i - k].S;
			pos2 = i;
		}
	}
 
	cout << pos1+1 << " " << pos2+1 << endl;
}
 
signed main() {
	IOS
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
} 
