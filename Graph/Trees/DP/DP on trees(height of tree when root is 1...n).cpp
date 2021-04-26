// https://youtu.be/Xng1Od_v6Ug

/*
DP on trees
Type2@rachitiitr
in-out DP
Que1: Find height of tree when each node is considered root one by one from 1...n
Que2: Find diameter of tree
*/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
typedef long long int ll;
// #define int long long int
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
const ll N = 3e4+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
vl g[N];

/*
in[u] height of subtree of node u when 0 is the root
out[u] height of tree when u is the root
*/
ll in[N], out[N];
ll n, m;

// calculares height of subtree of each node when 1 is root
void dfs1(ll u, ll par) {
    in[u] = 0;
    for(ll v: g[u]){
        if(v == par) continue;
        dfs1(v, u);
        in[u] = max(in[u], 1 + in[v]);
    }
}

void dfs2(ll u, ll par) {
    ll mx1 = -1, mx2 = -1;

    // for top 2 values of in[v] of children of node u (mx1 is largest and mx2 is second largest)
    for(ll v: g[u]){
        if(v == par) continue;
        if(in[v] >= mx1) mx2 = mx1, mx1 = in[v];
        else if(in[v] > mx2) mx2 = in[v];
    }

    // we have to use either mx1 or mx2 (if mx1 is same as in[v] then use mx2)
    for(ll v: g[u]){
        if(v == par) continue;
        ll use = mx1;

        if(mx1 == in[v]){
            use = mx2;
        }

        out[v] = max(1 + out[u], 2 + use);

        dfs2(v, u);
    }
}
 
void solve() {
    ll u, v;
    cin >> n;
    f(i, n - 1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    dfs1(1, 0);
    dfs2(1, 0);

    ll diameter = 0;
    loop(i, 1, n){
        cout << max({in[i], out[i]}) << " ";
        diameter = max({diameter, in[i] + out[i]});
    }
    cout << endl << "Diameter: " << diameter << endl;
}
 
int32_t main() {
    IOS
    solve();
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
    return 0;
}

/*
    1
   / \
   2  3
  / \  \
 4   5  6
         \
          7
INPUT
7
1 2
1 3
2 4
2 5
3 6
6 7
OUTPUT
3 4 3 5 5 4 5 
Diameter: 5
*/
