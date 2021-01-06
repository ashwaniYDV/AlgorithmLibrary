/*
Q1) Check if two nodes are on same path in a tree
Q2) Whether one node lies in the subtree of another node

Ans) For any two nodes u, v if they are in same path then,

Intime[v] < Intime[u] and Outtime[v] > Outtime[u]
                 OR
Intime[u] < Intime[v] and Outtime[u ]> Outtime[v]
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e6+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
vl g[N];
ll n, m;

ll in[N], out[N], vis[N];
ll timer = 1;

void dfs(ll u){
    in[u] = timer++;
    vis[u] = 1;
    for(ll v: g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    out[u] = timer++;
}

void solve() {
    ll t, k, u, v;
    cin >> n;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    dfs(1);
    ll queries;
    cin >> queries;
    f(i, queries){
        cin >> u >> v;
        if((in[u] > in[v] && out[u] < out[v]) || (in[u] < in[v] && out[u] > out[v])){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
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
INPUT:
5
1 2
2 3
2 4
4 5
6
3 5
1 2
1 5
2 4
3 2
3 4

OUTPUT:
NO
YES
YES
YES
YES
NO
*/
