// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

/*
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum 
and find the minimum difference
*/

class Solution {
    public:
        int minDifference(int a[], int n) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += a[i];

            bool dp[n + 1][sum + 1];
            for (int i = 0; i <= n; i++) dp[i][0] = 1;
            for (int j = 1; j <= sum; j++) dp[0][j] = 0;

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= sum; j++) {
                    if (j < a[i - 1]) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j] or dp[i - 1][j - a[i - 1]];
                    }
                }
            }

            int diff = INT_MAX;
            for (int j = sum / 2; j >= 0; j--) {
                if (dp[n][j]) {
                    diff = (sum - j) - j;
                    break;
                }
            }

            // method 2
            /*
            for (int j = 0; j <= sum; j++) {
                if (dp[n][j]) {
            	diff = min(diff, abs(sum - 2*j));
                }
            }
            */

            return diff;
        }
};
