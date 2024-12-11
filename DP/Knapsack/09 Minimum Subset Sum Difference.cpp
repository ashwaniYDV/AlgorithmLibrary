// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

/*
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 
such that the absolute difference between their sums is minimum and find the minimum difference
*/


class Solution {
public:
    int minDifference(vector<int>& a) {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base case
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        
        // DP transition
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j >= a[i - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        /*
        for(int j = sum/2; j >= 0; j--) {
            int sum1 = j;
            int sum2 = sum - j;
            if(dp[n][j]) {
                return abs(sum1 - sum2);   
            }
        }
            
        return -1;
        */

        // Find the minimum possible absolute difference
        int res = sum;
        for (int j = 0; j <= sum; j++) {
            if (dp[n][j]) {
                res = min(res, abs((sum - j) - j));
            }
        }
        
        return res;
    }
};
