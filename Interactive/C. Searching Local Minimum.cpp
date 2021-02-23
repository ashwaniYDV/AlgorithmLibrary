// https://codeforces.com/contest/1480/problem/C

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
// #define endl "\n"
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 5e5+5;
const int N = 2e3+5;
int n, m, k;
 
 
void solve() {
	int x, y, z;
	cin >> n;
	if(n == 1) {
		cout << "! 1" << endl;
		return;
	}
	int a[n+1] = {0};
 
	cout << "? 1" << endl;
	cin >> y;
	a[1] = y;
	cout << "? 2" << endl;
	cin >> z;
	a[2] = z;
	if(y < z) {
		cout << "! " << 1 << endl;
		return;
	}
 
	cout << "? " << n << endl;
	cin >> y;
	a[n] = y;
	cout << "? " << (n-1) << endl;
	cin >> z;
	a[n-1] = z;
	if(y < z) {
		cout << "! " << n << endl;
		return;
	}
 
	int low = 2, high = n-1, mid;
 
	while(low <= high) {
		mid = low + (high - low) / 2;
 
		if(a[mid-1] == 0) {
			cout << "? " << mid - 1 << endl;
			cin >> x;
		} else {
			x = a[mid-1];
		}
		if(a[mid] == 0) {
			cout << "? " << mid << endl;
			cin >> y;
		} else {
			y = a[mid];
		}
		if(a[mid+1] == 0) {
			cout << "? " << mid + 1 << endl;
			cin >> z;
		} else {
			z = a[mid+1];
		}
 
		if(y < x && y < z) {
			cout << "! " << mid << endl;
			return;
		}
 
		if(z < y) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
 
}
 
int32_t main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
