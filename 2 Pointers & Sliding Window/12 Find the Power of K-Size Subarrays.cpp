// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/

/*
You are given an array of integers nums of length n and a positive integer k.
The power of an array is defined as:
a) Its maximum element if all of its elements are consecutive and sorted in ascending order. 
b) -1 otherwise.
You need to find the power of all subarrays of nums of size k.
Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].


Input: nums = [1,2,3,4,3,2,5], k = 3
Output: [3,4,-1,-1,-1]
Explanation:
There are 5 subarrays of nums of size 3:
[1, 2, 3] with the maximum element 3.
[2, 3, 4] with the maximum element 4.
[3, 4, 3] whose elements are not consecutive.
[4, 3, 2] whose elements are not sorted.
[3, 2, 5] whose elements are not consecutive.

Input: nums = [2,2,2,2,2], k = 4
Output: [-1,-1]

Input: nums = [3,2,3,2,3,2], k = 2
Output: [-1,3,-1,3,-1]
*/


/*
Intuition
---------
* Find length of maximum increasing consecutive subarray ending at index r
* If this subarry length >= k, then add a[r] to answer
*/

class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        int n = a.size();
        vector<int> res;

        int l = 0;
        for(int r = 0; r < n; r++) {
            while(l < r && a[l] + (r - l) != a[r]) {
                l++;
            }

            if(r < k-1) {
                continue;
            }

            if(r - l + 1 >= k) {
                res.push_back(a[r]);
            } else {
                res.push_back(-1);
            }
        }

        return res;
    }
};