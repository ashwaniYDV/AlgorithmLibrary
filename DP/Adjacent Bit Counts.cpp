// https://www.geeksforgeeks.org/count-binary-strings-k-times-appearing-adjacent-two-set-bits/

/*
Let there be an array dp[i][j][2] where dp[i][j][0]
denotes number of binary strings with length i having
j number of two adjacent 1's and ending with 0.
Similarly dp[i][j][1] denotes the same binary strings
with length i and j adjacent 1's but ending with 1.
Then: 
    dp[1][0][0] = 1 and dp[1][0][1] = 1
    For all other i and j,
        dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]
        dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1]

Then, output dp[n][k][0] + dp[n][k][1]
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

// dp[i][j][0] stores count of binary strings of length i with j consecutive 1's and ending at 0.
// dp[i][j][1] stores count of binary strings of length i with j consecutive 1's and ending at 1. 

void solve() {
    ll t, k, x, y;
    cin >> n >> k;
    ll dp[n+1][k+1][2];

    memset(dp, 0, sizeof(dp));

    // If n = 1 and k = 0.
    dp[1][0][0] = 1; // string = 0
    dp[1][0][1] = 1; // string = 1

    loop(i, 2, n){
        loop(j, 0, k){
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];

            dp[i][j][1] = dp[i - 1][j][0];
            if(j - 1 >= 0) dp[i][j][1] += dp[i - 1][j - 1][1];
        }
    }
    cout << dp[n][k][0] + dp[n][k][1] << endl;
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
