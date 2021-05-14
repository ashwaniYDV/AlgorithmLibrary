// https://leetcode.com/problems/coin-change-2/
// https://youtu.be/jaNZ83Q3QGc

/*
Que) ax+by+cz+..... = sum
Find number of non negative solutions
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
const ll N = 1e5+1;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;


// Top down
// ll fun(ll a[], ll sum, ll n){
//     if(n < 0 || sum < 0) return 0;
//     if(sum == 0) return 1;

//     return fun(a, sum, n - 1) + fun(a, sum - a[n], n);
// }
// cout << fun(a, sum, n - 1)

// order of m memory
ll fun(ll a[], ll sum){
    ll dp[sum + 1] = {0};
    // for sum = 0, no of ways = 1;
    dp[0] = 1;
    for(ll i = 0; i < n; i++){
        for(ll j = 1; j <= sum; j++){
            if(j >= a[i]){
                dp[j] += dp[j - a[i]];
            }
        }
    }
    return dp[sum];
}
// or this way
ll fun(ll a[], ll sum) {
    ll dp[sum + 1] = {0};
    // for sum = 0, no of ways = 1;
    dp[0] = 1;
    for (ll j = 1; j <= sum; j++) {
        for (ll i = 0; i < n; i++) {
            if (j >= a[i]) {
                dp[j] += dp[j - a[i]];
            }
        }
    }
    return dp[sum];
}

// order of n*m memory
void solve() {
    ll x, y, z, sum;
    cin >> n;
    ll a[n];
    f(i, n) cin >> a[i];
    cin >> sum;
    ll dp[n + 1][sum + 1];
    for(ll i = 0; i <= n; i++) dp[i][0] = 1;
    for(ll j = 1; j <= sum; j++) dp[0][j] = 0;

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= sum; j++){
            if(j < a[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - a[i - 1]];
            }
        }
    }
    cout << dp[n][sum] << endl;
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
