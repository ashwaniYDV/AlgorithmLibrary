// https://atcoder.jp/contests/dp/tasks/dp_h



void solve() {
    int u, v;
    cin >> n >> m;
    string s[n];
    f(i, n) cin >> s[i];

    int dp[n+1][m+1];

    dp[0][0] = 1;

    fa(i, 1, n) {
        if(s[i][0] == '#') {
            dp[i][0] = 0;
        } else {
            dp[i][0] = dp[i-1][0];
        }
    }
    fa(j, 1, m) {
        if(s[0][j] == '#') {
            dp[0][j] = 0;
        } else {
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(s[i][j] == '#') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
    
}
