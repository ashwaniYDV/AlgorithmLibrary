// https://atcoder.jp/contests/abc191/tasks/abc191_c
// https://youtu.be/DEmJ9dwB8l8

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
const int MAXN = 5e5+5;
const int N = 15;
int n, m, k;

string s[N];
int vis[N][N];
int vertices = 0;

bool isSafe(int i, int j) {
	if(i < 0 || i >= n || j < 0 || j >= m || s[i][j] == '.' || vis[i][j]) return false;
	return true;
}

void dfs(int i, int j) {
	if(!isSafe(i, j)) return;

	if(i-1 >= 0 && j+1 < m && s[i-1][j] == '.' && s[i][j+1] == '.') vertices++;
	if(i-1 >= 0 && j-1 >= 0 && s[i-1][j] == '.' && s[i][j-1] == '.') vertices++;
	if(i+1 < n && j+1 < m && s[i+1][j] == '.' && s[i][j+1] == '.') vertices++;
	if(i+1 < n && j-1 >= 0 && s[i+1][j] == '.' && s[i][j-1] == '.') vertices++;

	if(i-1 >= 0 && j+1 < m && s[i-1][j] == '#' && s[i][j+1] == '#' && s[i-1][j+1] == '.') vertices++;
	if(i-1 >= 0 && j-1 >= 0 && s[i-1][j] == '#' && s[i][j-1] == '#' && s[i-1][j-1] == '.') vertices++;
	if(i+1 < n && j+1 < m && s[i+1][j] == '#' && s[i][j+1] == '#' && s[i+1][j+1] == '.') vertices++;
	if(i+1 < n && j-1 >= 0 && s[i+1][j] == '#' && s[i][j-1] == '#' && s[i+1][j-1] == '.') vertices++;

	vis[i][j] = 1;
 
	f(z, 4) {
		dfs(i + dx[z], j + dy[z]);
	}
}
 
void solve() {
	int x, y;
	cin >> n >> m;
	f(i, n) cin >> s[i];
 
	f(i, n) {
		f(j, m) {
			if(s[i][j] == '#') {
				dfs(i, j);
				cout << vertices << endl;
				return;
			}
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
