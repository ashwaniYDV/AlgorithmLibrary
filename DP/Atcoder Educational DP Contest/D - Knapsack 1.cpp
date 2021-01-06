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

int fun(int pos, int W, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp){
    if(pos >= n || W == 0) return 0;
 
    if(dp[pos][W] != -1) return dp[pos][W];
 
    if(weight[pos] > W) return dp[pos][W] = fun(pos+1, W, weight, value, dp);
 
    return dp[pos][W] = max(fun(pos + 1, W, weight, value, dp), value[pos] + fun(pos+1, W - weight[pos], weight, value, dp));
}

void normalfun(vector<int>& weight, vector<int>& value, int W) {
    vector<vector<int>> dp(105, vector<int>(100005, -1));
    cout << fun(0, W, weight, value, dp) << endl;
}

void dpfun(vector<int>& weight, vector<int>& value, int W) {
    int dp[n+1][W+1];
    for (ll i = 0; i <= n; i++) { 
        for (ll w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) {
                dp[i][w] = 0; 
            } else if (weight[i-1] > w) {
                dp[i][w] = dp[i-1][w]; 
            } else {
                dp[i][w] = max(dp[i-1][w], value[i-1] + dp[i-1][w-weight[i-1]]);
            }
       } 
   } 
   cout << dp[n][W] << endl;
}

void solve() {
    int W;
    cin >> n >> W;
    vector<int> weight(n), value(n);
    f(i,n) cin >> weight[i] >> value[i];
    normalfun(weight, value, W);
    dpfun(weight, value, W);
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
