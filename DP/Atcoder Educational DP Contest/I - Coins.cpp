// https://atcoder.jp/contests/dp/tasks/dp_i
// https://unacademy.com/class/dynamic-programming-in-probability/F1PY5UD2



const int N = 2e5+5;
int n, m;

ld prob[3000];

ld go(int i, int j, ld probability) {
    if(i >= n) {
        if(j >= (n+1)/2)
            return probability;
        return 0;
    }

    ld res = go(i+1, j+1, probability * prob[i]) + go(i+1, j, probability * (1.0 - prob[i]));

    return res;
}

/*
    dp[i][j] = probality of j heads when we have tossed first i coins

    dp[0][0] = probability of 0 heads when we have tossed 0 coins 
             = 1

    dp[0][j] (j >= 1 && j <= n) = probability of j heads when we have tossed 0 coins 
                                = 0

    dp[i][0] (i >= 1 && i <= n) = probability of 0 heads when we have tossed first i coins
                                = (1 - prob[0])*(1 - prob[1])*...(1 - prob[i-1])

    
    dp[i][j] = (dp[i-1][j-1] * prob[i-1]) + (dp[i-1][j] * (1.0 - prob[i-1]));
*/

void solve() {
    int u, v, x, y, z;
    cin >> n;
    f(i, n) cin >> prob[i];
    // cout << go(0, 0, 1.0) << endl;

    ld dp[n+1][n+1];

    dp[0][0] = 1.0;

    for(int j = 1; j <= n; j++)
        dp[0][j] = 0.0;

    for(int i = 1; i <= n; i++)
        dp[i][0] = dp[i-1][0] * (1 - prob[i - 1]);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j-1] * prob[i-1] + dp[i-1][j] * (1.0 - prob[i-1]);
        }
    }

    // calculating final result when j >= [n/2]
    ld res = 0.0;
    for(int j = (n+1)/2; j <= n; j++) 
        res += dp[n][j];

    cout << res << endl;
}

signed main() {
    IOS
    PRECISION(10)
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
