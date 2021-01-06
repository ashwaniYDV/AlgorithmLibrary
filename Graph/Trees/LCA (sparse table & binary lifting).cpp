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
ll n, m;
 
ll level[N];

// (Sparse Table) or LCA[i][j] represents 2^(j)th parent of node i
ll LCA[N][(ll)ceil(log2(N))+1];

// height is not the height of tree but log2(N) of nodes
ll height=(ll)ceil(log2(N));

void dfs(ll u, ll lvl, ll par) {
    level[u] = lvl;
    LCA[u][0] = par;

    for(auto v: g[u]) {
        if(v != par) {
            dfs(v, lvl + 1, u);
        }
    }
}

// generating sparse table
void init() {
    // initializing parent and level of each node
    dfs(1, 0, -1);

    for(ll i = 1; i <= height; i++) {
        for(ll node = 1; node <= n; node++) {
            if(LCA[node][i-1] != -1) {
                // for 2^i node, first getting 2^(i - 1)th node
                ll parNode = LCA[node][i - 1];
                // 2^(i)th node = 2^(i - 1)th + 2^(i - 1)th node
                LCA[node][i] = LCA[parNode][i - 1];
            }else{
                LCA[node][i] = -1;
            }
        }
    }
}

// binary lifting
ll getLCA(ll a, ll b) {
    if(level[b] < level[a]) swap(a, b);

    ll d = level[b] - level[a];

    // method 1
    // for(ll i = 18; i >= 0; i--){
    //  if(d & (1<<i)) b = LCA[b][i];
    // }

    // method 2
    while(d) {
        ll i = log2(d);
        b = LCA[b][i];
        d -= (1 << i);
    }

    if(a == b) return a;

    // naive approach O(n)
    // while(LCA[a][0] != LCA[b][0]){
    //     a = LCA[a][0];
    //     b = LCA[b][0];
    // }

    // efficient approach O(logn)
    for(ll i = height; i >= 0; i--){
        if(LCA[a][i] != LCA[b][i]){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    // parent of a or b
    return LCA[a][0];
}
 
void solve() {
    ll u, v;
    cin >> n;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    init();
    cout << getLCA(7, 3);

}
 
int32_t main() {
    IOS
    solve();
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
    return 0;
}

/*
INPUT
7
1 2
1 3
2 4
2 5
3 6
6 7

OUTPUT
3
*/
