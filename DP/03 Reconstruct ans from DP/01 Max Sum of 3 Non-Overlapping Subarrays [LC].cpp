// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

/*
Given an integer array nums and an integer k, 
find 3 non-overlapping subarrays of length k with maximum sum and return them.
Return the result as a list of indices representing the starting position of each interval (0-indexed). 
If there are multiple answers, return the lexicographically smallest one.

Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]
 

Constraints:
1 <= nums.length <= 2 * 10^4
1 <= nums[i] < 2^16
1 <= k <= floor(nums.length / 3)
*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
        // Number of possible subarray starting positions
        int n = a.size() - k + 1;

        // Calculate sum of all possible k-length subarrays
        vector<int> sums;
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += a[i];
        }
        sums.push_back(windowSum);

        // Sliding window to calculate remaining sums
        for (int i = k; i < a.size(); i++) {
            windowSum = windowSum - a[i - k] + a[i];
            sums.push_back(windowSum);
        }

        // Step 1: Find optimal sum using DP
        // dp[i][j]: max sum possible starting from index i with j subarrays remaining
        vector<vector<int>> dp(n, vector<int>(4, -1));
        dpFun(0, 3, sums, k, dp);

        // Step 2: Reconstruct the path to find indices
        vector<int> indices;
        dfs(0, 3, sums, k, dp, indices);

        return indices;
    }

private:
    // DP function to find maximum possible sum
    int dpFun(int i, int rem, vector<int>& sums, int k, vector<vector<int>>& dp) {
        if (rem == 0) return 0;
        if (i >= sums.size()) {
            return rem > 0 ? INT_MIN : 0;
        }

        if (dp[i][rem] != -1) {
            return dp[i][rem];
        }

        // Try taking current subarray vs skipping it
        int withCurrent = sums[i] + dpFun(i + k, rem - 1, sums, k, dp);
        int skipCurrent = dpFun(i + 1, rem, sums, k, dp);

        return dp[i][rem] = max(withCurrent, skipCurrent);
    }

    // DFS to reconstruct the solution path (lexicographically smallest)
    void dfs(int i, int rem, vector<int>& sums, int k, vector<vector<int>>& dp, vector<int>& indices) {
        if (rem == 0) return;
        if (i >= sums.size()) return;

        int withCurrent = sums[i] + dpFun(i + k, rem - 1, sums, k, dp);
        int skipCurrent = dpFun(i + 1, rem, sums, k, dp);

        // Choose path that gave optimal result in DP
        if (withCurrent >= skipCurrent) {  // Take current subarray
            indices.push_back(i);
            dfs(i + k, rem - 1, sums, k, dp, indices);
        } else {  // Skip current subarray
            dfs(i + 1, rem, sums, k, dp, indices);
        }
    }
};