class Solution{
  public:
    int cutRod(int price[], int n) {
        // dp[i] denotes the max price value of rod length i, so answer = dp[n]
        vector<int> dp(n+1, 0);
        
        dp[0] = 0; // when no element is included
        dp[1] = price[0]; // when only first element is included
        
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] = max(dp[i], dp[j] + price[i - j - 1]);
            }
        }
        
        return dp[n];
    }
};
