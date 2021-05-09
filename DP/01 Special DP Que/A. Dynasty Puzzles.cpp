// https://codeforces.com/contest/191/problem/A

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
 
 
void solve() {
    int x, y, l, r;
    cin >> n;
    vector<string> s(n);
    f(i, n) cin >> s[i];
 
    int dp[26][26] = {0};
 
    f(i, n) {
        int l = s[i][0] - 'a', r = s[i].back() - 'a';
        int sz = s[i].size();
 
        f(j, 26) {
            if (dp[j][l] != 0) 
                dp[j][r] = max(dp[j][r], dp[j][l] + sz);
        }
        dp[l][r] = max(dp[l][r], sz);
    }
 
    int res = 0;
    f(i, 26) {
        res = max(res, dp[i][i]);
    }
 
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
