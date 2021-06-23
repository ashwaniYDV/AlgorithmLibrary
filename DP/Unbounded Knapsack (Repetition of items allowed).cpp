void solve() {
    vi value = {10, 40, 50, 70};
    vi weight = {1, 3, 4, 5};
    int W = 8;
    int n = value.size();

    int dp[n+1][W+1]; 
  
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= W; j++) { 
            if (i == 0 || j == 0) {
                dp[i][j] = 0; 
            } else if (weight[i - 1] > j) {
                dp[i][j] = dp[i - 1][j]; 
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i - 1]] + value[i - 1]); 
            }
       }
   } 
   cout << dp[n][W]; 
}
