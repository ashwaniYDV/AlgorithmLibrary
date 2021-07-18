// https://leetcode.com/problems/arithmetic-slices/
// https://youtu.be/rSi4MpGEz1M

/*
An integer array is called arithmetic if it consists of at least 3 elements 
and if the difference between any two consecutive elements is the same.
For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

Input: nums = [1]
Output: 0
*/



/*
dp[i] = count of all AP subarrays ending at index i

base case:
dp[0] = dp[1] = 0
*/


// top down
class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp) {
        if(i < 2) return 0;

        if(dp[i] != -1) return dp[i];

        if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2])) {
            return dp[i] = 1 + f(i - 1, nums, dp);
        } else { 
            return dp[i] = 0;
        }
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> dp(n+1, -1);

        int res = 0;
        for (int i = 0; i < n; i++) res += f(i, nums, dp);
        return res;
    }
};



// bottom up
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> dp(n, 0);

        dp[0] = dp[1] = 0;

        for (int i = 2; i < n; i++) {
            if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2])) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 0;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) res += dp[i];
        return res;
    }
};



// space optimized
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        int prev = 0;
        int res = 0;

        for (int i = 2; i < n; i++) {
            int cur = 0;
            if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2])) {
                cur = prev + 1;
            } else {
                cur = 0;
            }
            
            prev = cur;

            res += prev;
        }

        return res;
    }
};