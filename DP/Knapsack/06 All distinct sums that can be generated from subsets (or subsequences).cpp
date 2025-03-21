// https://practice.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums4424/1

/*
Given a set of integers, find all distinct sums that can be generated from the subsets of the given sets.
*/

class Solution {
public:
    vector < int > DistinctSum(vector < int > nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(sum+1, 0));

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

        vector < int > res;
        for (int j = 0; j <= sum; j++) {
            if (dp[n][j]) res.push_back(j);
        }
        return res;
    }
};
