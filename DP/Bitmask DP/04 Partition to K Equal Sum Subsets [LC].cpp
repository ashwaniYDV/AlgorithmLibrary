// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

/*
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 10^4
The frequency of each element is in the range [1, 4].
*/

class Solution {
public:
    int n, totalMask, target;
    
    bool canPartitionKSubsets(int mask, int curSum, vector<int>& nums, vector<int>& dp) {
        if(mask == totalMask) return true;

        if (dp[mask] != -1) return dp[mask];
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            if (curSum + nums[i] > target) continue;
            
            if (curSum + nums[i] == target) {
                if (canPartitionKSubsets(mask | (1 << i), 0, nums, dp)) {
                    return dp[mask] = true;
                }
            } else {
                if (canPartitionKSubsets(mask | (1 << i), curSum + nums[i], nums, dp)) {
                    return dp[mask] = true;
                }
            }
        }

        return dp[mask] = false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        totalMask = (1 << n) - 1;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        
        target = sum / k;

        vector<int> dp(totalMask + 1, -1);
        return canPartitionKSubsets(0, 0, nums, dp);
    }
};
