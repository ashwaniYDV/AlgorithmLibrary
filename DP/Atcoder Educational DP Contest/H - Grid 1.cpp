// https://atcoder.jp/contests/dp/tasks/dp_h

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
const int MAXN = 20;
const int N = 1e5+5;
int n, m;
 
/************************************************************************************/
int binpow(int n, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) res = res * n;
        n = n * n;
        p >>= 1;
    }
    return res;
}
int power(int n, int p) {
    int res = 1;
    n %= MOD;
    while (p > 0) {
        if (p & 1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        p >>= 1;
    }
    return res;
}
int modInverse(int n, int p) { 
    return power(n, p - 2);
} 
 
int fact[MAXN], inv[MAXN], invfact[MAXN];
void initFactorials() {
    fact[0] = 1;
      for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i * 1LL) % MOD;
    }
 
    //calculate inverses of [1,N] mod p
    inv[1]=1;
    for(int i=2;i<MAXN;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
 
    invfact[0]=1;
    for(int i=1;i<MAXN;i++)invfact[i]=(invfact[i-1]*inv[i])%MOD;
}
 
int nCrMod(int n, int r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    int num = fact[n], den = (fact[r] * fact[n-r]) % MOD;
    int inv = modInverse(den, MOD);
    return (num * inv) % MOD;
}
 
/*
Rotate Left by rotL
rotate(v.begin(), v.begin()+rotL, v.end());
Rotate Right by rotR
rotate(v.begin(), v.begin()+ n-rotR, v.end());
*/
/************************************************************************************/


void solve() {
    int u, v;
    cin >> n >> m;
    string s[n];
    f(i, n) cin >> s[i];

    int dp[n+1][m+1];

    dp[0][0] = 1;

    fa(i, 1, n) {
        if(s[i][0] == '#') {
            dp[i][0] = 0;
        } else {
            dp[i][0] = dp[i-1][0];
        }
    }
    fa(j, 1, m) {
        if(s[0][j] == '#') {
            dp[0][j] = 0;
        } else {
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(s[i][j] == '#') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
    
}
signed main() {
    IOS
    int t = 1;
    // cin >> t;
    f(i, t) {
        solve();
    }
}
