// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
// https://atcoder.jp/contests/dp/tasks/dp_d
// https://atcoder.jp/contests/dp/tasks/dp_e

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
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>=n;a<n?i+=1:i-=1)
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 2000+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

// method 1 (top down approach) 
ll dp[105][100005];
ll fun(ll pos, ll W, ll weight[], ll value[]){
    if(pos < 0 || W == 0) return 0;

    if(dp[pos][W] != -1) return dp[pos][W];

    if(W < weight[pos]) return fun(pos - 1, W, weight, value);

    return dp[pos][W] = max(value[pos] + fun(pos - 1, W - weight[pos], weight, value), fun(pos - 1, W, weight, value));
}

// method 2
ll knapSack(ll n, ll W, ll weight[], ll value[]) {
    ll dp[n+1][W+1]; 
  
    // Build table dp[][] in bottom up manner 
    for (ll i = 0; i <= n; i++) { 
        for (ll w = 0; w <= W; w++) { 
            if (i==0 || w==0)
                dp[i][w] = 0; 
            else if (weight[i-1] <= w) 
                dp[i][w] = max(value[i-1] + dp[i-1][w-weight[i-1]],  dp[i-1][w]); 
            else
                dp[i][w] = dp[i-1][w]; 
       } 
   } 
   return dp[n][W]; 
}

void solve() {
    ll t, k, x, y;

    ll value[] = {60, 100, 120};
    ll weight[] = {10, 20, 30}; 
    ll  W = 50; 
    ll n = sizeof(value)/sizeof(value[0]);
    cout << knapSack(n, W, weight, value);
    // cout << fun(n - 1, W, weight, value);
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
