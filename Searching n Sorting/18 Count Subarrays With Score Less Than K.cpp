// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/

/*
The score of an array is defined as the product of its sum and its length.
For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.

Input: nums = [1,1,1], k = 5
Output: 5
Explanation:
Every subarray except [1,1,1] has a score less than 5.
[1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
Thus, there are 5 subarrays having scores less than 5.
 
Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
1 <= k <= 10^15
*/


class Solution {
public:
    // FFFFTTTTT
    int get(int idx, vector<long long>& prefSum, int n, long long k) {
        int l = 0, r = idx;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            int cnt = idx - mid + 1; // we are considering a[mid, mid+1, ..., idx] subarray as valid
            
            // cnt * pref_sum of a[mid, mid+1, , , idx]
            long long sum = cnt * (prefSum[idx] - (mid - 1 >= 0 ? prefSum[mid - 1] : 0));
            if(sum < k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    long long countSubarrays(vector<int>& a, long long k) {
        int n = a.size();

        vector<long long> prefSum(n, 0);
        prefSum[0] = a[0];
        for(int i = 1; i < n; i++) {
            prefSum[i] += prefSum[i - 1] + a[i];
        }

        long long res = 0;
        for(int r = 0; r < n; r++) {
            int l = get(r, prefSum, n, k);
            
            // cnt all subarrays ending at idx r ->> [l, ..., r], [l+1, ..., r], ..., [r]
            res += r - l + 1;
        }

        return res;
    }
};
