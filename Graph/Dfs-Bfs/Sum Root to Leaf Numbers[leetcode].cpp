// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
const ll N = 1e5+1;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
vl g[N];
ll n, m;
ll a[N], vis[N];

ll ans = 0;

void dfs(ll u, ll sum){
    sum = sum*10;
    sum += a[u];

    vis[u] = 1;

    if(g[u].size() == 1){
        cout << sum << endl;
        ans += sum;
    }

    for(ll v: g[u]){
        if(!vis[v]){
            dfs(v, sum);
        }
    }
}

void solve() {
    ll t, k, u, v;
    cin >> n;
    f(i, n - 1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    loop(i, 1, n) cin >> a[i];
    dfs(1, 0);
    cout << "Total: " << ans;
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
5
1 2
1 3
2 4
2 5
4 9 0 5 1


495
491
40
Total: 1026

*/
