// https://youtu.be/2yAEj-0A8bk


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

void kickstart(int testcase, int res) {
    cout << "Case #" << testcase << ": " << res << endl;
}


ll dp[20][2][2][2];

ll digit_dp(string str, ll pos, ll evenPos, ll leadingzeros, ll tight) {
    if(pos == str.length()) return 1;

    if(dp[pos][evenPos][leadingzeros][tight] != -1) return dp[pos][evenPos][leadingzeros][tight];
    
    int res = 0;

    if(evenPos) {
        vector<int> digits = {0, 2, 4, 6, 8};

        int ub = tight ? (str[pos] - '0') : 9;

        for(int dig: digits) {
            if(dig <= ub) {
                res += digit_dp(str, pos + 1, 0, 0, (tight & (dig == ub)));
            }
        }
    } else {
        vector<int> digits = {1, 3, 5, 7, 9};

        int ub = tight ? (str[pos] - '0') : 9;

        if(leadingzeros) {
            res += digit_dp(str, pos+1, 0, 1, 0);
        }

        for(int dig: digits) {
            if(dig <= ub) {
                res += digit_dp(str, pos + 1, 1, 0, (tight & (dig == ub)));
            }
        }
    }
    
    return dp[pos][evenPos][leadingzeros][tight] = res;
}

int go(int num) {
    string str = to_string(num);
    memset(dp, -1, sizeof(dp));
    return digit_dp(str, 0, 0, 1, 1);
}

void solve(int testcase) {
    int l, r;
    cin >> l >> r;
    int res = go(r) - go(l - 1);
    kickstart(testcase, res);
}

int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    fa(i, 1, T+1)
    solve(i);
    return 0;
}
