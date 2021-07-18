// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Example 1:
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Example 2:
Input: nums = [1,1,1], k = 2
Output: 0

Example 3:
Input: nums = [1,6,1], k = 3
Output: 5
 
Constraints:
n == nums.length
2 <= n <= 10^4
0 <= nums[i] <= 10^6
1 <= k <= n * (n - 1) / 2
*/


/*
Binary search for the answer and heck how many pairs have distance <= X.

FFFFFTTTTTTTT
*/


class Solution {
public:
    bool check(int mid, vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= mid) j++;
            cnt += j - i - 1;
        }
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int lo = 0, hi = nums[n - 1] - nums[0];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, nums, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
