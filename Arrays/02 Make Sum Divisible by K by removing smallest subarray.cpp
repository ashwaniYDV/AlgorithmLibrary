// https://leetcode.com/problems/make-sum-divisible-by-p/
// https://www.geeksforgeeks.org/length-of-smallest-subarray-to-be-removed-to-make-sum-of-remaining-elements-divisible-by-k/

/*
Given an array of positive integers nums, remove the smallest subarray (possibly empty) 
such that the sum of the remaining elements is divisible by p. 
It is not allowed to remove the whole array.
Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

Example 1:
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. 
We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
*/


/*
// https://leetcode.com/problems/make-sum-divisible-by-p/discuss/854166/JavaPython-3-O(n)-code-w-brief-explanation-analysis-and-similar-problems.

I think there are two parts to recognize in this question after thinking about for a long time. 
It helps to think about this question if P was just a target value to sum to.

1) After getting the sum of the entire array % p. This is the new target to find in a subarray. 
   You can now think of the question as regular subarray target finding problem. Maybe this is obvious, but took me a while...

2) Key calculation: key = (preSum - remainder + p) % p;
   The current sum - our target would be the target in a normal prefix sum problem. But we have modulus, so we need to offset by p.
   Let says P = 2000, target = 1000, and current sum = 600; This current sum could be 2600, 4600.....etc. Key = 600 - 1000 + 2000 = 1600. 
   If we found some prefix of 1600, then the rest of the array would sum to 1000, which is our target.
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int remainder = 0;

        for (int num : nums) {
            remainder = (remainder + num) % p;
        }

        map<int, int> prefixSumToIndex;
        prefixSumToIndex[0] = -1;

        int prefixSum = 0, res = n;

        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            prefixSumToIndex[prefixSum] = i;

            int key = (prefixSum - remainder + p) % p;

            if (prefixSumToIndex.count(key)) {
                res = min(res, i - prefixSumToIndex[key]);
            }
        }

        return res < n ? res : -1;
    }
};



class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int remainder = 0;

        for (int num : nums) {
            remainder = (remainder + num) % p;
        }
        if (remainder == 0) return 0;

        map<int, int> prefixSumToIndex;
        prefixSumToIndex[0] = -1;

        int prefixSum = 0, res = n;

        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            int key = (prefixSum - remainder + p) % p;

            if (prefixSumToIndex.count(key)) {
                res = min(res, i - prefixSumToIndex[key]);
            }

            prefixSumToIndex[prefixSum] = i;
        }

        return res < n ? res : -1;
    }
};



















class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Remainder when total_sum is divided by K
        int total_sum_rem = 0;
        for (int i = 0; i < n; i++) {
            total_sum_rem = (total_sum_rem + nums[i]) % k;
        }

        // If given array is already divisible by K
        if (total_sum_rem == 0) return 0;

        // Stores curr_remainder and the most recent index at which curr_remainder has occured
        unordered_map<int, int> mp;
        mp[0] = -1;

        int curr_remainder = 0;

        // Stores required answer
        int res = n;

        for (int i = 0; i < n; i++) {
            curr_remainder = (curr_remainder + nums[i]) % k;

            // Update current remainder index
            mp[curr_remainder] = i;

            int mod = (curr_remainder - total_sum_rem + k) % k;

            // If mod already exists in map the subarray exists
            if (mp.count(mod)) res = min(res, i - mp[mod]);
        }

        return res < n ? res : -1;
    }
};
