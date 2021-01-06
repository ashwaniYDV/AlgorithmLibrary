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

int fun(int i, int k, vector<int>& h, vector<int>& dp){
    if(i == n - 1){
        return 0;
    }
    if(i >= n){
        return INT_MAX;
    }
    if (dp[i] != -1) return dp[i];

    dp[i] = INT_MAX;
    for(int j = 1; j <= k && (i+j) < n; j++) {
        dp[i] = min(dp[i], abs(h[i] - h[i+j]) + fun(i + j, k, h, dp));
    }
    return dp[i];
}

void normalfun(vector<int>& h, int k) {
    vector<int> dp(n+5, -1);
    cout << fun(0, k, h, dp) << endl;
}

void dpfun(vector<int>& h, int k) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);

    for(int i = 2; i < n; i++) {
        dp[i] = INT_MAX;
        for(int j = 1; j <= k && (i-j) >= 0; j++) {
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout << dp[n-1] << endl;
}

void solve() {
    int k;
    cin >> n >> k;
    vector<int> h(n);
    f(i, n) cin >> h[i];
    normalfun(h, k);
    dpfun(h, k);
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
