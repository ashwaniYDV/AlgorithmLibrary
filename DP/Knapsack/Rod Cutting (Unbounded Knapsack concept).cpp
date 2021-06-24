/*
This problem is very similar to the Unbounded Knapsack Problem, where there are multiple occurrences of the same item. Here the pieces of the rod.

An analogy between Unbounded Knapsack and the Rod Cutting Problem:

______________________________________________________________________________________________________
Unbounded Knapsack Problem                    |       Rod Cutting Problem
______________________________________________________________________________________________________
Size of array (n)                             |       Length of rod (n)
Value of the item (value[])                   |       Price of the pieces of rod (price[])
Weight array (weitht[])                       |       Length of array (length[])
Max knapsack capacity (W)                     |       Length of main rod (n == mxLength)
______________________________________________________________________________________________________
*/


// Method 1: Unbounded Knapsack concept O(n*m) memory
class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> length(n);
        for(int i = 0; i < n; i++) length[i] = i + 1;
    
        int mxLength = n;
    
        int dp[n + 1][mxLength + 1];
    
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= mxLength; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if(j < length[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - length[i - 1]] + price[i - 1]);
                }
            }
        }
        return dp[n][mxLength];
    }
};










// Method 2: Unbounded Knapsack concept O(m) memory
class Solution{
  public:
    int cutRod(int price[], int n) {
        int length[n];
        for(int i = 0; i < n; i++) length[i] = i + 1;
        
        int mxLength = n;
        int dp[mxLength + 1] = {0};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= mxLength; j++) {
                if(j >= length[i]) {
                    dp[j] = max(dp[j], dp[j - length[i]] + price[i]);
                }
            }
        }
        return dp[mxLength];
    }
};












// Method 3: O(m) memory
class Solution{
  public:
    int cutRod(int price[], int n) {
        // dp[i] denotes the max value of rod length i, so answer = dp[n]
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














// Method 4: Memoised
class Solution{
  public:
    int go(int pos, int n, int price[], vector<int>& dp) {
    	if(pos == n) return 0;
    	if(pos > n) return INT_MIN;
    	
    	if(dp[pos] != -1) return dp[pos];
    
    	int res = 0;
    	for(int i = pos; i < n; i++) {
    		res = max(res, price[i - pos] + go(i + 1, n, price, dp));
    	}
    
    	return dp[pos] = res;
    }
    int cutRod(int price[], int n) {
        vector<int> dp(10000, -1);
        return go(0, n, price, dp);
    }
};
