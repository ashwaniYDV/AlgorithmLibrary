/*
Given an integer array arr and an integer difference, 
return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
 
Constraints:
1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4
*/


// TLE solution [Time = O(n^2)]
class Solution {
public:
    int longestSubsequence(vector<int>& nums, int diff) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int res = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] == nums[j] + diff) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        
        int res = 1;
        for(int x: arr) {
            dp[x] = 1 + dp[x - difference];
            res = max(res, dp[x]);
        }
        return res;
    }
};