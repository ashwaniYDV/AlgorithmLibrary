// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1


// O(n*m) memory
class Solution {
public:
    int knapSack(int n, int W, int value[], int weight[]) {
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
       return dp[n][W]; 
    }
};




// O(m) memory
class Solution {
public:
    int knapSack(int n, int W, int value[], int weight[]) {
        int dp[W + 1] = {0};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= W; j++) {
                if(j >= weight[i]) {
                    dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                }
            }
        }
        return dp[W];
    }
};
