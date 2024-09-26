// https://leetcode.com/problems/longest-increasing-subsequence/

/*
You are given an integer array nums and an integer k.
Find the longest subsequence of nums that meets the following requirements:
    The subsequence is strictly increasing and
    The difference between adjacent elements in the subsequence is at most k.
Return the length of the longest subsequence that meets the requirements.

Input: nums = [4,2,1,4,3,4,5,8,15], k = 3
Output: 5
Explanation:
The longest subsequence that meets the requirements is [1,3,4,5,8].
The subsequence has a length of 5, so we return 5.
Note that the subsequence [1,3,4,5,8,15] does not meet the requirements because 15 - 8 = 7 is larger than 3.

Input: nums = [7,4,5,1,8,12,4,7], k = 5
Output: 4
Explanation:
The longest subsequence that meets the requirements is [4,5,8,12].
The subsequence has a length of 4, so we return 4.

Input: nums = [1,5], k = 1
Output: 1
Explanation:
The longest subsequence that meets the requirements is [1].
The subsequence has a length of 1, so we return 1.
 
Constraints:
1 <= nums.length <= 10^5
1 <= nums[i], k <= 10^5
*/


// TLE
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int res = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && nums[i] - nums[j] <= k) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};


// Segment Tree solution
// https://leetcode.com/problems/longest-increasing-subsequence-ii/solutions/2560010/c-segment-tree-with-illustration-explanation/