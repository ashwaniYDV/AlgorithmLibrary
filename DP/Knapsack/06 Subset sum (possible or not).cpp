// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// method 1
// DP with bitmasking

// method 2
int fun(int i, int sum, int a[], ){
    if(i < 0 || sum < 0) return 0;
    if(sum == 0) return 1;

    return fun(i - 1, sum - a[i], a) || fun(i - 1, sum, a);
}

// Method 3
class Solution {
public:
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = target;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum+1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};