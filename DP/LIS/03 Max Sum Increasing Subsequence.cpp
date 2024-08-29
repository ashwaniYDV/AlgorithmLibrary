/*
Maximum Sum Increasing subsequence is a subsequence of a given list of integers, whose sum is maximum and in the subsequence, 
all elements are sorted in increasing order.

Input: 1 4 3 8 8
Output: 13

Input: 1 2 4 3 2 5 4 6 8 
Output: 26
*/


/*
dp[i] stores the max sum of increasing subsequence when nums[i] is included
*/ 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1, 0);
        for(int i = 0; i < n; i++) dp[i] = nums[i];
        
        int mx = dp[0];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + nums[i]);
                }
            }
            mx = max(mx, dp[i]);
        }

        return mx;
    }
};
