// https://codeforces.com/gym/102942/problem/F

#include<bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
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
const int N = 1e7+5;
int n, m;

void solve() {
	int x, y, k;
	cin >> n >> k;

	int a[n];
	f(i, n) cin >> a[i];

	map<int, int> mp;
	int total = 0, res = 0;
	int i = 0, j = 0;

	while(j < n) {
		if(mp[a[j]]) {
			total++;
			mp[a[j]]++;
			j++;
		} else {
			if(a[j] <= k) {
				k -= a[j];
				total++;
				mp[a[j]]++;
				j++;
			} else if(i == j) {
				i++;
				j++;
			} else {
				x = a[i];
				while(mp[x] != 0) {
					mp[a[i]]--;
					total--;
					if(mp[a[i]] == 0) {
						k += a[i];
					}
					i++;
				}
			}
		}

		res = max(res, total);
	}
	cout << res << endl;
}

int32_t main() {
	IOS
	int T = 1;
	cin >> T;
	while(T--)
	solve();
	return 0;
}
