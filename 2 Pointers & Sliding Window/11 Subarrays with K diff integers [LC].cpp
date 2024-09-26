/*
Given an integer array nums and an integer k, 
return the number of good subarrays of nums.
A good array is an array where the number of diff integers in that array is exactly k.

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:
1 <= nums.length <= 2 * 10^4
1 <= nums[i], k <= nums.length
*/


// Method 1: (2 Pass sliding window)
class Solution {
public:
    // Helper function to count the number of subarrays with at most k distinct elements
    int slidingWindowAtMost(vector<int>& A, int k) {
        int n = A.size();
        unordered_map<int, int> mp;

        int l = 0, res = 0;
        for(int r = 0; r < n; r++) {
            mp[A[r]]++;

            while(mp.size() > k) {
                mp[A[l]]--;
                if(mp[A[l]] == 0) mp.erase(A[l]);
                l++;
            }

            // count all subarrays with <= k distinct integers ending at r'th index
            res += r - l + 1;
        }

        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k - 1);
    }
};


// Method 2: (Sliding Window in One Pass)
// https://leetcode.com/problems/subarrays-with-k-different-integers/editorial/