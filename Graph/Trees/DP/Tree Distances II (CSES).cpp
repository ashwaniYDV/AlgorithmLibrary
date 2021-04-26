// https://youtu.be/nGhE4Ekmzbc
// https://cses.fi/problemset/task/1133/

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
const int MAXN = 1e4+5;
const int N = 2e5+5;
int n, m;


vector<int> g[N];
int subtreeSize[N];
int res[N];

void getSubtreeSize(int u, int par) {
    subtreeSize[u] = 1;
    for(int v: g[u]) {
        if(v == par) continue;
        getSubtreeSize(v, u);
        subtreeSize[u] += subtreeSize[v];
    }
}

void getRes(int u, int par) {
    for(int v: g[u]) {
        if(v == par) continue;
        res[v] = res[u] + (n - subtreeSize[v]) - subtreeSize[v];
        // res[v] = res[u] + n - 2 * subtreeSize[v];
        getRes(v, u);
    }
}

void solve() {
	int u, v;
	cin >> n;
	f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
	getSubtreeSize(1, -1);

	// sum of distance from root node is the sum of `subtreeSize` except the root itself
    for(int i = 2; i <= n; i++) {
        res[1] += subtreeSize[i];
    }

    // after getting the distance sum of root, we can deduce the distance sum of the other node.
    getRes(1, -1);

    loop(i, 1, n) {
    	cout << res[i] << " ";
    }
}
 
signed main() {
	IOS
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
} 
