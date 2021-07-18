// https://leetcode.com/problems/majority-element-ii/

/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]
 

Constraints:
1 <= nums.length <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        vector<int> res;

        // num1, num2 can be initialized with any value
        int num1 = 0, num2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for (int val : nums) {
            if (val == num1) {
                cnt1++;
            } else if (val == num2) {
                cnt2++;
            } else if (cnt1 == 0) {
                num1 = val;
                cnt1++;
            } else if (cnt2 == 0) {
                num2 = val;
                cnt2++;
            } else  {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int val : nums) {
            if (val == num1)
                cnt1++;
            else if (val == num2)
                cnt2++;
        }
        if (cnt1 > n / 3) res.push_back(num1);
        if (cnt2 > n / 3) res.push_back(num2);
        return res;
    }
};
