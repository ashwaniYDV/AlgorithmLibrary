// https://leetcode.com/problems/house-robber-ii/
// https://youtu.be/3WaxQMELSkw?si=pBnihXAfO_UQYJVq

/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one. 
Adjacent houses have security systems connected and 
it will automatically contact police if two adjacent houses were broken in same night.
Given an integer array nums representing the amount of money of each house, 
return max amount of money you can rob tonight without alerting police.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), 
because they are adjacent houses.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: nums = [1,2,3]
Output: 3
*/


/*
Note:
=====
nums = [2, 3, 2]
In house robber 1 question, we could have taken (nums[0] + nums[2]) = (2 + 2) = 4
But in house robber 2 question, nums[0] and nums[2] are adjacent, so we cannot take them both.

Intuition
=========
I cannot rob both first and last house.
*/



// Space optimized solution
/*
Since we cannot rob both first and last house, 
We will create two temp arrays and call same function used in "house robber 1" problem
and return max answer of them.

Array 1 will not contain first house.
Array 2 will not contain last house.
*/
class Solution {
public:
    int maxSumOfNonAdjEle(vector<int>& nums) {
        int n = nums.size();

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            
            int cur = max(pick, notPick);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> temp1; // contains nums[1, , , n-1]
        vector<int> temp2; // contains nums[0, , , n-2]

        for(int i = 0; i < n; i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(maxSumOfNonAdjEle(temp1), maxSumOfNonAdjEle(temp2));
    }
};





class Solution {
public:
    int f(int i, int isLastEleTaken, vector<int>& nums, vector<vector<int>>& dp) {
        if(i < 0) return 0;

        if(dp[i][isLastEleTaken] != -1) return dp[i][isLastEleTaken];

        int pick = 0;
        // taking the last element
        if(i == nums.size() - 1) {
            pick = nums[i] + f(i - 2, 1, nums, dp);
        } else if(i != 0) {
            pick = nums[i] + f(i - 2, isLastEleTaken, nums, dp);
        }

        // if last element is not taken then only i can take first element
        if(i == 0 && !isLastEleTaken) {
            pick = nums[i];
        }

        int notPick = f(i - 1, isLastEleTaken, nums, dp);
        
        return dp[i][isLastEleTaken] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return f(n - 1, 0, nums, dp);
    }
};