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
    int n, all, target;
    
    bool canPartitionKSubsets(int mask, int k, int curSum, vector<int>& nums) {
        if(mask == all) {
            return k == 0 && curSum == 0;
        }
        
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) continue;
            
            if(curSum + nums[i] > target) return false;
            
            int tempSum = curSum + nums[i];
            int tempK = k;
            if(tempSum == target) {
                tempSum = 0;
                tempK--;
            }
            if(canPartitionKSubsets((mask | (1 << i)), tempK, tempSum, nums)) {
                return true;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        all = (1 << n) - 1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;
        
        target = sum / k;
        
        sort(nums.rbegin(), nums.rend());
        return canPartitionKSubsets(0, k, 0, nums);
    }
};
