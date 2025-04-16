// https://leetcode.com/problems/count-the-number-of-good-subarrays/

/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.

Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
 

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i], k <= 10^9
*/


/*
Hints:
1) For a fixed index l, try to find the minimum value of index r, such that the subarray is not good
2) When a number is added to a subarray, it increases the number of pairs by its previous appearances.
3) When a number is removed from the subarray, it decreases the number of pairs by its remaining appearances.
4) Maintain 2-pointers l and r such that we can keep in account the number of equal pairs.
*/


class Solution {
public:
    long long countGood(vector<int>& a, int k) {
        int n = a.size();

        unordered_map<int, int> counter;
        int l = 0;
        long long pairs = 0, res = 0;

        for (int r = 0; r < n; ++r) {
            pairs += counter[a[r]];
            counter[a[r]]++;

            while (pairs >= k) {
                res += n - r;
                counter[a[l]]--;
                pairs -= counter[a[l]];
                l++;
            }
        }

        return res;
    }
};
