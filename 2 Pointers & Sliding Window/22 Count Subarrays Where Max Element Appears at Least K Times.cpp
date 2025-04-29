// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

/*
You are given an integer array nums and a positive integer k.
Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 
Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
1 <= k <= 10^5
*/

class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int n = a.size();
        int mx = *max_element(a.begin(), a.end());
        
        int l = 0, cnt = 0;
        long long res = 0;

        for(int r = 0; r < n; r++) {
            if(a[r] == mx) cnt++;

            while(cnt == k) {
                if(a[l] == mx) cnt--;
                l++;
            }

            res += l;
        }

        return res;
    }
};
