// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

/*
You may recall that an array arr is a mountain array if and only if:
a) arr.length >= 3
b) There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return min no of elements to remove to make nums​​​ a mountain array.


Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
 
Constraints:
3 <= nums.length <= 1000
1 <= nums[i] <= 10^9
It is guaranteed that you can make a mountain array out of nums.
*/


/*
dp_lis[i] stores the value of longest increasing subsequence ending with nums[i]
dp_lds[i] stores the value of longest decreasing subsequence starting with nums[i]

                .
          .            .
     .                     .
.                               .

*/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        vector<int> dpLis(n, 1), dpLds(n, 1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(a[i] > a[j]) {
                    dpLis[i] = max(dpLis[i], dpLis[j] + 1);
                }
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j > i; j--) {
                if(a[i] > a[j]) {
                    dpLds[i] = max(dpLds[i], dpLds[j] + 1);
                }
            }
        }

        int res = n;
        for(int i = 1; i < n-1; i++) {
            // ignoring if ele does not forms a mountain
            if(dpLis[i] <= 1 || dpLds[i] <= 1) continue;

            int totalElements = dpLis[i] + dpLds[i] - 1; // current ele is counted twice so -1
            res = min(res, n - totalElements);
        }
        return res;
    }
};
