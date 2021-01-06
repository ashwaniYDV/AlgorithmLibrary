/*
Print all paths from source to destination node in a directed/undirected graph.
*/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;i<n;i++)
#define loop(i,a, n) for(ll i = a; i <= n; i++)
#define loopb(i,a, n) for(ll i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setmem(x, k) memset(x, k, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e4;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

vl g[N];
ll vis[N];

void dfs(ll u, ll dest, vector<ll> res) {
    if(u == dest) {
        for(ll x: res) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    vis[u] = 1;
    for(ll v: g[u]) {
        if(!vis[v]) {
            res.pb(v);
            dfs(v, dest, res);
            // backtrack
            res.pop_back();
        }
    }
    // backtrack
    vis[u] = 0;
}

void solve() {
    ll m, x, u, v, source, dest;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    cin >> source >> dest;
    vector<ll> res;
    res.pb(source);
    dfs(source, dest, res);
}
 
int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    // cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}


/*

Input:
5
6
1 2
1 3
3 4
3 5
2 5
4 5
2
4
         1
       /   \
     3      2
    | \    /
    |  \  /
    4___5

Output:
2 1 3 4 
2 1 3 5 4 
2 5 3 4 
2 5 4 


*/






/*

In backtracking problems Vis can be used globally as well as in parameter as shown 
since we have to backtrack in either case so doesn't matter.

void dfs(ll u, ll dest, vector<ll> res, vector<ll> vis) {
    if(u == dest) {
        for(ll x: res) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    vis[u] = 1;
    for(ll v: g[u]) {
        if(!vis[v]) {
            res.pb(v);
            dfs(v, dest, res, vis);
            // backtrack
            res.pop_back();
        }
    }
    // backtrack
    vis[u] = 0;
}

void solve() {
    ll m, x, u, v, source, dest;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    cin >> source >> dest;
    vector<ll> res, vis(n + 1, 0);
    res.pb(source);
    dfs(source, dest, res);
}

*/
