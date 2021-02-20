// https://atcoder.jp/contests/abc192/tasks/abc192_e

#include<bits/stdc++.h>
using namespace std;
 
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
const int N = 1e5+5;
int n, m, x, y;

vector<pair<int, pii>>g[N];

int findNextTime(int N, int K) { 
    int rem = (N + K) % K; 
  
    if (rem == 0) 
        return N; 
    else
        return N + K - rem; 
} 

void dijkstra(int x) {
	int dp[n+5];
	f(i, n+5) dp[i] = INF;

    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    dp[x] = 0;

    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        int u = x.S;

        for(auto i: g[u]) {
        	int v = i.F, t = i.S.F, k = i.S.S;
			int tempT = findNextTime(dp[u], k);

            if(dp[v] > (tempT + t)) {
                dp[v] = (tempT + t);
                pq.push({dp[v], v});
            }
        }
    }

    if(dp[y] == INF) {
    	cout << -1 << endl;
    	return;
    }
    cout << dp[y] << endl;
}

void solve() {
	int u, v, t, k;
	cin >> n >> m >> x >> y;
	f(i, m) {
		cin >> u >> v >> t >> k;
		g[u].pb({v, {t, k}});
		g[v].pb({u, {t, k}});
	}
    dijkstra(x);
}
 
int32_t main() {
	IOS
	int T = 1;
	// cin >> T;
	while(T--)
	solve();
	return 0;
}
