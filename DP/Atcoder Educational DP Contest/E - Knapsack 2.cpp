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
const int N = 1e5+5;
int n, m, k;


void dpfun(int n, int W, vector<int>& weight, vector<int>& value) {
    int totalValue = 0;
    
    f(i, n) {
        totalValue += value[i];
    }

    // dp[i][j] denotes the least weight to get a value of j from the first i objects
    ll dp[n+1][totalValue+1];

    // It takes 0 weight here
    for(int i = 0; i <= n; i++) { 
        dp[i][0] = 0;
    }
    // Just set it arbitrarily large because we want to calculate min value of weight
    for(int i = 1; i <= totalValue; i++) {   
        dp[0][i] = 1e18;
    }

    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= totalValue; j++) {
            // If I choose this object the value will go over j
            if(j < value[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Either don't choose this object(dp[i][j]) or choose this object
                dp[i][j] = min(dp[i - 1][j], weight[i - 1] + dp[i - 1][j - value[i - 1]]);
            }

           // Is it possible to get value of j in less than w weight
            if(dp[i][j] <= W) {
                // Find maximum such j
                ans = max(ans, j);
            }
        }
    }

    cout << ans << endl;
}

void solve() {
    int x, y, p, q, W;
    cin >> n >> W;
    vector<int> value(n), weight(n);
    f(i, n) {
        cin >> weight[i] >> value[i];
    }
    dpfun(n, W, weight, value);
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
