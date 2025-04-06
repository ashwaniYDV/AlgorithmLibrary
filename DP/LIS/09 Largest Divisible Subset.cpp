// https://leetcode.com/problems/largest-divisible-subset/

/*
Given a set of distinct positive integers nums, return the largest subset answer such that 
every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.


Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 
Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10^9
All the integers in nums are unique.
*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int> dp(n, 1);

        int lis = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(a[i] % a[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            lis = max(lis, dp[i]);
        }

        vector<int> res;
        int prev = -1;
        for(int i = n-1; i >= 0; i--) {
            if(dp[i] == lis && (prev == -1 || prev % a[i] == 0)) {
                res.push_back(a[i]);
                lis--;
                prev = a[i];
            }
        }

        return res;
    }
};
