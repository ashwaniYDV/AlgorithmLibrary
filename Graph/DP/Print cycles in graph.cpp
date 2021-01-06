/*
Btw what if the graph was something like a wheatstone bridge, 
how would one print all cycles since this code only prints two out of the three cycles 
in a wheatstone bridge
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

void dfs(ll u, ll parent, vl s){
    vis[u] = 1;
    s.pb(u);
    for(ll v: g[u]){
        if(vis[v] == 0) {
            dfs(v, u, s);
        } else if(vis[v] == 1){
            if(v != parent){
                cout << "Cycle \n";
                cout << v << " ";
                ll pos = ((ll)s.size()) - 1;
                while(pos >= 0 && s[pos] != v){
                    cout << s[pos] << " ";
                    --pos;
                }
                cout << "\n";
            }
        }
    }
    vis[u] = 2;
    s.pop_back();
}

void solve() {
    ll x, u, v;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    vl s;
    fa(i, 1, n + 1){
        if(!vis[i]){
            dfs(i, -1, s);
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
Input 1:
5
6
1 2
1 3
3 4
2 5
2 3
2 4

Output 1:
Cycle 
1 3 2 
Cycle 
2 4 3 

*/
