// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387174
// https://youtu.be/jQjnQJ9NPOY


const int N = 2e5+5;
int n, m;

int a[N];
int dp[N][4];

// dp[i][j] = i elements processed and i'th position par number j rakhne ki minimum cost 

void solve(int testcase){
    cin >> n;
    
    f(i, n) cin >> a[i];

    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
    
    fa(i, 1, n) {
        f(j, 4) {
            dp[i][j] = INF;
        }
        f(j, 4) {
            f(k, 4) {
                int rule_broken = 0;
                if(a[i] == a[i-1] && j != k) rule_broken++;
                if(a[i] > a[i-1] && j <= k) rule_broken++;
                if(a[i] < a[i-1] && j >= k) rule_broken++;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + rule_broken);
            }
        }
    }
    
    int res = INF;
    
    f(j, 4) res = min(res, dp[n-1][j]);

    kickstart(testcase, res);
}
 
signed main() {
    IOS
    int t = 1;
    cin >> t;
    f(i, t) {
        solve(i+1);
    }
}
