// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-revisited-9e1091ea/
// Shortest Path Revisited
// https://unacademy.com/class/tricky-variations-of-dijkstra-algorithm/TA76JSGL
// Pulkit Chhabra Unacademy

/*
Problem:
In the country of HackerEarth, there are N cities and M bi-directional roads. 
We need to transport essential items from City 1  to all other cities. (There exists a path always)

But every road has some positive amount of Toll Charge associated with it say C (it is not same for all roads). 
We need to find the minimum amount of charge that it required to deliver essential items for each city.

Fortunately, to our rescue we have K special offers, which means while travelling from City 1 to any other city 
we can select at-most K roads and we will not be charged for using those roads.

Can you now find the minimum charge that we have to pay to deliver essential items for each city.

(Remember we require to provide answers for each destination city separately i.e. we have K offers for every city and not as a whole)

*/

/*
Since the value of K is small, we can use Dynamic Programming Here.

We will modify Dijikstra Algorithm to incorporate at most K special offers.

At every step of Dijikstra Algorithm, we can decide whether we wish to use a special offer or not.

So, recurrence can be like , where dp[i][j] represents the minimum charge required to reach city i if we use j special offers.

At a particular iteration of Dijikstra, assume we have node u currently, so

dp[v][j] = weight of edge(u, v) + dp[u][j]

// since weight of edge(u, v) is set as 0 by using offer
dp[v][j+1] = dp[u][j]
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
// #define endl "\n"
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 5e5+5;
int n, m;


vector<pair<int,int>> g[N];
int k;
int dp[N][20];

void dijkstra() {
	int source = 1;
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j <= k; j++)
    		dp[i][j] = INF;
    }

    dp[source][0] = 0;
    // {distance, {node, j}}, where j <= k
    set<pair<int, pair<int, int>>> s;
    s.insert({dp[source][0], {source, 0}});

	while (!s.empty()) {
	    int u = s.begin()->second.first;
	    int j = s.begin()->second.second;
	    s.erase(s.begin());

	    for (auto x : g[u]) {
	        int v = x.first, w = x.second;
	        if (dp[v][j] > dp[u][j] + w) {
	        	s.erase({dp[v][j], {v, j}});
	        	dp[v][j] = dp[u][j] + w;
	        	s.insert({dp[v][j], {v, j}});
	       	}
	       	// now setting w = 0, if possible
	       	if (j < k && dp[v][j + 1] > dp[u][j]) {
	        	s.erase({dp[v][j + 1], {v, j + 1}});
	        	dp[v][j + 1] = dp[u][j];
	        	s.insert({dp[v][j + 1], {v, j + 1}});
	       	}
	    }
	}

	for (int i = 1; i <= n; i++) {
        int res = INF;
        for (int j = 0; j <= k; j++) {
            res = min(res, dp[i][j]);
        }
        cout << res << " ";
    }
}
 
void solve() {
	int u, v, w;
	cin >> n >> m >> k;

    f(i, m) {
    	cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    dijkstra();
}


signed main() {
    IOS
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
} 
