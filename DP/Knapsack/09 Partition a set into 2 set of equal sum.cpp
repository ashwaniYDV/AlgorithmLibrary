// https://www.geeksforgeeks.org/partition-problem-dp-18/
// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

/*
Given an array arr[], return true if it can be partitioned into two subsets 
such that the sum of elements in both parts is the same, otherwise, false.
Note: Each element is present in either the first subset or the second subset, but not in both.

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].

Input: arr = [1, 3, 5]
Output: false
Explanation: This array can never be partitioned into two such parts.

Constraints:
1 ≤ arr.size ≤ 100
1 ≤ arr[i] ≤ 1000
*/

class Solution {
public:
    bool equalPartition(vector<int>& a) {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        if(sum % 2) return 0;
        
        sum /= 2;
        
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true; // Sum 0 is always possible
        }
        
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
        
        return dp[n][sum];
    }
};