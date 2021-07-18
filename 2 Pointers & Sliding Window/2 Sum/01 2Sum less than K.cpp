// https://leetcode.com/problems/two-sum-less-than-k/submissions/1032827689/

/*
Given an array nums of integers and integer k, 
return max sum such that there exists i < j with nums[i] + nums[j] = sum and sum < k. 
If no i, j exist satisfying this equation, return -1.
*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0, r = n - 1;
        int ans = 0;

        while(l < r){
            if(nums[l] + nums[r] >= k) {
                r--;
            } else if(nums[l] + nums[r] < k){
                ans = max(nums[l] + nums[r], ans);
                l++;
            }
        }
        
        if(ans == 0) return -1;
        return ans;
    }
};