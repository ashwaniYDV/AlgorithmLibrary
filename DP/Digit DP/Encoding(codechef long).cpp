// https://www.codechef.com/problems/ENCODING
// https://youtu.be/B7ZWUBfaIq0

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
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
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5;
int n, m;


int power10[N];
int precalc(){
    power10[0] = 1;
    for(int i = 1; i < N; i++) {
        power10[i] = (power10[i-1] * 10LL) % MOD;
    }
}

int cntdp[100001][2];
int cnt(string& str, int pos, bool tight){
    if(tight == 0) return power10[n - pos];
    if(pos == n) return 1;

    if(cntdp[pos][tight] != -1) return cntdp[pos][tight];

    int ub = str[pos] - '0';
    ll res = 0;
    for(int dig = 0; dig <= ub; dig++) {
        res = (res + cnt(str, pos+1, dig == ub)) % MOD;
    }
    return cntdp[pos][tight] = res % MOD;
}

int dp[100001][11][2];
int digit_dp(string& str, int pos, int prevDigit, bool tight) {
    if(pos == n) return 0;

    if(dp[pos][prevDigit][tight] != -1) return dp[pos][prevDigit][tight];

    ll res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    for(int dig = 0; dig <= ub; dig++){
        if(dig != prevDigit){
            ll contri = (dig * power10[n - 1 - pos] * cnt(str, pos+1, tight & (dig == ub))) % MOD;
            res = (res + contri) % MOD;
        }
        res = (res + digit_dp(str, pos+1, dig, tight & (ub == dig))) % MOD;
    }

    return dp[pos][prevDigit][tight] = res % MOD;
}

int bruteForce(string& L, int nl){
    int prev_dig = 99;
    ll res = 0;
    for(int i = 0; i < nl; i++) {
        int dig = L[i] - '0';
        if(dig != prev_dig) {
            res = (res + dig * power10[nl - 1 - i]) % MOD;
        }
        prev_dig = dig;
    }
    return res % MOD;
}

void solve() {
    int nl, nr; 
    string L, R; 
    cin >> nl >> L;
    cin >> nr >> R;

    memset(dp, -1, sizeof dp);
    memset(cntdp, -1, sizeof cntdp);
    n = nr;
    ll ansR = digit_dp(R, 0, 99, 1);

    memset(dp, -1, sizeof dp);
    memset(cntdp, -1, sizeof cntdp);
    n = nl;
    ll ansL = digit_dp(L, 0, 99, 1);

    cout << (ansR - ansL + bruteForce(L, nl) + MOD) % MOD << '\n';
}

int32_t main() {
    IOS
    precalc();
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
