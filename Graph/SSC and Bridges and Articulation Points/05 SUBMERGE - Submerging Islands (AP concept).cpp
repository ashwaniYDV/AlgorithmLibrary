// https://www.spoj.com/problems/SUBMERGE/

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
const int N = 1e5+5;
int n, m;


vector<int> g[N];
int in[N], low[N], isArticulation[N];
int timer;

void dfs(int u, int par) {
    in[u] = low[u] = ++timer;
    int children = 0;

    for(int v: g[u]) {
        if(v == par) continue;
        // If v is not visited
        if(in[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            // Case-2: Atleast 1 component will get separated
            if(low[v] >= in[u] && par != -1) isArticulation[u] = 1;

            children++;
        } else {
            low[u] = min(low[u], in[v]);
        }
    }

    // Case-1: u is root
    if(par == -1 && children >= 2) isArticulation[u] = 1;
}

void solve() {
    int u, v;
    cin >> n >> m;
    if(n == 0 && m == 0) 
        exit(0);

    loop(i, 1, n) {
        g[i].clear();
    }

    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    loop(i, 1, n) in[i] = -1, low[i] = -1, isArticulation[i] = 0;
    timer = 0;

    loop(i, 1, n) {
        if(in[i] == -1) {
            dfs(i, -1);
        }
    }

    int cnt = 0;
    loop(i, 1, n) {
        if(isArticulation[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;
}

signed main() {
    IOS
    int t = 1;
    // cin >> t;
    while(1) {
        solve();
    }
} 
