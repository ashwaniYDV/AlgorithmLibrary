// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/editorial/

/*
You are given an integer array nums with the following properties:
nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.

Example 1:
Input: nums = [1,2,3,3]
Output: 3

Example 2:
Input: nums = [2,1,2,5,3,2]
Output: 2

Example 3:
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
 
Constraints:
2 <= n <= 5000
nums.length == 2 * n
0 <= nums[i] <= 10^4
nums contains n + 1 unique elements and one of them is repeated exactly n times.
*/


/*
Because the repeated element appears n times in a 2n array, 
it must occur at least twice within a distance of 3

Example: 1 2 3 1
*/

class Solution {
public:
    bool check(vector<int>& a, int i, int j, int n) {
        return j < n && a[i] == a[j];
    }

    int repeatedNTimes(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            if(check(a, i, i+1, n)) return a[i];
            if(check(a, i, i+2, n)) return a[i];
            if(check(a, i, i+3, n)) return a[i];
        }


        return -1;
    }
};
