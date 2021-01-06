#include<bits/stdc++.h>
using namespace std;
 
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
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 5e5+5;
const int N = 1e6+5;
int n, m;

int fun(int pos, int idx, vector<vector<int>>& a, vector<vector<int>>& dp) {
    if(pos == n){
        return 0;
    }
    if (dp[pos][idx] != -1) return dp[pos][idx];
    int mx;
    if(idx == 0)
        mx = a[pos][idx] + max(fun(pos + 1, 1, a, dp), fun(pos + 1, 2, a, dp));
    if(idx == 1)
        mx = a[pos][idx] + max(fun(pos + 1, 0, a, dp), fun(pos + 1, 2, a, dp));
    if(idx == 2)
        mx = a[pos][idx] + max(fun(pos + 1, 0, a, dp), fun(pos + 1, 1, a, dp));
    return dp[pos][idx] = mx;
}

void normalfun(vector<vector<int>>& a) {
    int x, y, z;
    vector<vector<int>> dp(n, vector<int>(3, -1));

    x = fun(0, 0, a, dp);
    y = fun(0, 1, a, dp);
    z = fun(0, 2, a, dp);
    cout << max({x, y, z}) << endl;
}

void dpfun(vector<vector<int>>& a) {
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0] = a[0];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            if(j == 0)
                dp[i][j] = a[i][j] + max(dp[i-1][1], dp[i-1][2]);
            if(j == 1)
                dp[i][j] = a[i][j] + max(dp[i-1][0], dp[i-1][2]);
            if(j == 2)
                dp[i][j] = a[i][j] + max(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}

void solve() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    f(i, n) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    };
    normalfun(a);
    dpfun(a);
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
