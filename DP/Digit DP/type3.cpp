// https://youtu.be/hxbqUX7IIvw
// Hackerearth - Benny and the broken odometer
// https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/

/*
One fine day, Benny decided to calculate the number of kilometers that she traveled by her bicycle. 
Therefore, she bought an odometer and installed it onto her bicycle. But the odometer was broken. 
It was not able to display the digit 3. This would precisely mean, that the odometer won't be able to display the numbers having one of their digits as 3.

For example, after the number 1299, the odometer will show 1400.

Benny was traveling a lot and now she wants to know the number of kilometers that she has traveled. 
You will be given only the number that Benny saw on the odometer. Your task is to determine the real distance.
*/
 
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


ll dp[11][2][2];

ll digit_dp(string str, ll pos = 0, ll tight = 1, ll flag = 0){
    if(pos == str.length()) return flag;

    if(dp[pos][tight][flag] != -1) return dp[pos][tight][flag];
    
    int res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    for(int i = 0; i <= ub; i++) {
        ll fl = flag;
        if(i == 3) fl = 1;

        res += digit_dp(str, pos + 1, (tight & (i == ub)), fl);
    }
    
    return dp[pos][tight][flag] = res;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    string str = to_string(n);
    int res = digit_dp(str);
    cout << n - res << endl;
}

int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
