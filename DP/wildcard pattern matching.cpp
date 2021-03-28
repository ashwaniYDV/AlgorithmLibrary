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
const int N = 1e3+5;
int n, m;

int dp[N][N];
string str, pat;

bool go(int s = 0, int p = 0) {
    if(p == pat.length()) {
        return dp[s][p] = (s == str.length());
    }
    if(s == str.length()) {
        for(int i = p; i < pat.length(); i++) {
            if(pat[i] != '*') {
                return (dp[s][p] = 0);
            }
        }
        return (dp[s][p] = 1);
    }

    if(dp[s][p] != -1) return dp[s][p];

    // ? -> match one
    if(pat[p] == '?' or pat[p] == str[s]) {
        return dp[s][p] = go(s+1, p+1);
    }

    // * -> match all or match none
    if(pat[p] == '*') {
        return dp[s][p] = go(s+1, p) or go(s, p+1);
    }

    return dp[s][p] = 0;
}

int dp_sol(int n, int m) {
    int dp[n + 1][m + 1];

    // empty pattern can only match with empty string 
    if (m == 0) return (n == 0); 

    memset(dp, 0, sizeof dp);

    // empty pattern can match with empty string 
    dp[0][0] = 1;

    // Only '*' can match with empty string 
    for (int j = 1; j <= m; j++) {
        if (pat[j - 1] == '*') 
            dp[0][j] = dp[0][j - 1];
    }

    // fill the table in bottom-up fashion 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= m; j++) { 
            // Two cases if we see a '*' 
            // a) We ignore ‘*’ character and move to next character in pattern, 
            // i.e., ‘*’ indicates an empty sequence. 
            // b) '*' character matches with ith character in input 
            if (pat[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; 
            }
  
            // Current characters are considered as matching in two cases 
            // (a) current character of pattern is '?' 
            // (b) characters actually match 
            else if (pat[j - 1] == '?' || str[i - 1] == pat[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; 
            }
  
            // If characters don't match 
            else dp[i][j] = false; 
        } 
    } 
  
    return dp[n][m];
}

void solve() {
    cin >> str >> pat;
    n = str.size(), m = pat.size();
    memset(dp, -1, sizeof dp);
    cout << go(0, 0) << endl;
    cout << dp_sol(n, m) << endl;
}

signed main() {
    IOS
    int T = 1;
    // cin >> T;
    while (T--)
    	solve();
    return 0;
}
