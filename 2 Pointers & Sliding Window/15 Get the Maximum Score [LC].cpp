// https://leetcode.com/problems/get-the-maximum-score/description/

/*
You are given two sorted arrays of distinct integers nums1 and nums2.
A valid path is defined as follows:
* Choose array nums1 or nums2 to traverse (from index-0).
* Traverse the current array from left to right.
* If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. 
  (Only one repeated value is considered in the valid path).
The score is defined as the sum of unique values in a valid path.
Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo 109 + 7.

Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
Output: 30
Explanation: Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
The maximum is obtained with the path in green [2,4,6,8,10].

Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
Output: 109
Explanation: Maximum sum is obtained with the path [1,3,5,100].

Constraints:
1 <= nums1.length, nums2.length <= 10^5
1 <= nums1[i], nums2[i] <= 10^7
*/

class Solution {
public:
    const int M = 1e9+7;

    int maxSum(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        long long sum1 = 0, sum2 = 0, res = 0;
        int i = 0, j = 0;

        while(i < n && j < m) {
            if(a[i] < b[j]) {
                sum1 += a[i++];
            } else if(a[i] > b[j]) {
                sum2 += b[j++];
            } else {
                res += max(sum1, sum2) + a[i];
                sum1 = 0, sum2 = 0;
                i++, j++;
            }
        }

        while(i < n) {
            sum1 += a[i++];
        }
        while(j < m) {
            sum2 += b[j++];
        }

        res += max(sum1, sum2);
        return res % M;
    }
};