// https://codeforces.com/problemset/problem/204/A

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define endl "\n"
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 5e3+5;
int n, m;


ll dp[20][10][10][2];

ll digit_dp(string str, ll pos, ll firstDig, ll curDig, ll tight) {
    if(pos == str.length()) {
        return firstDig == curDig;
    };

    if(dp[pos][firstDig][curDig][tight] != -1) return dp[pos][firstDig][curDig][tight];
    
    int res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    for(int i = 0; i <= ub; i++) {
        if(pos == 0)
            res += digit_dp(str, pos + 1, i, i, (tight & (i == ub)));
        else
            res += digit_dp(str, pos + 1, firstDig, i, (tight & (i == ub)));
    }
    
    return dp[pos][firstDig][curDig][tight] = res;
}

int go(int n) {
    string str = to_string(n);
    memset(dp, -1, sizeof(dp));
    return digit_dp(str, 0, 0, 0, 1);
}

void solve() {
    int x, y, l, r;
    cin >> l >> r;

    int res = 0;
    if(r <= 10) {
        loop(i, l, r) if(i <= 9) res++;
        cout << res << endl;
        return;
    }

    if(l <= 10) {
        loop(i, l, 10) if(i <= 9) res++;
        l = 11;
    }

    res += go(r) - go(l-1);
    cout << res << endl;
}

signed main() {
    IOS
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
} 
