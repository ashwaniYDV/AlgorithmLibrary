// https://leetcode.com/problems/burst-balloons/

/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. 
You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:
Input: nums = [1,5]
Output: 10
*/



/*
dp[i][j]: coins obtained from bursting all the balloons between index i and j (including i or j)
dp[i][j] = max(nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j])

Note:
It is nums[i - 1] * nums[k] * nums[j + 1]
and not nums[i] * nums[k] * nums[j] since i'th and j'th ballons and all the ballons from i to j are already burst.




Transition explanation:
-> we are cuurently bursting the [k]'th position ballon.
-> [i,..., k-1] and [k+1, ..., j] ballons were already burst, thus (i - 1), (k), (j + 1) ballons will add to answer when k'th ballon is burst
-> nums[i - 1] * nums[k] * nums[j + 1]

int left  = (k == i) ? 0 : dp[i][k - 1];
int right = (k == j) ? 0 : dp[k + 1][j];

int curr = nums[k] * ((i == 0) ? 1 : nums[i - 1]) * ((j == n - 1) ? 1 : nums[j + 1]);

dp[i][j]  = max(dp[i][j], left + curr + right);
*/



class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap;  j < n;  i++, j++) {
                if (gap == 0) {
                    dp[i][j] = (i == 0 ? 1 : nums[i - 1]) * nums[i] * (j == n - 1 ? 1 : nums[j + 1]);
                } else {
                    dp[i][j] = 0;
                    for (int k = i; k <= j; k++) {
                        int left  = (k == i) ? 0 : dp[i][k - 1];
                        int right = (k == j) ? 0 : dp[k + 1][j];

                        int curr = nums[k] * ((i == 0) ? 1 : nums[i - 1]) * ((j == n - 1) ? 1 : nums[j + 1]);

                        dp[i][j]  = max(dp[i][j], left + curr + right);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
