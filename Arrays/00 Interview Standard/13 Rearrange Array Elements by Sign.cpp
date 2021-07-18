// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// https://youtu.be/tMl-su7ALDo?si=Ka7yVin9CZQlOwHS

/*
Given an array nums of even length consisting of an equal number of positive and negative integers.
You should return the array of nums such that the the array follows the given conditions:
1) Every consecutive pair of integers have opposite signs.
2) For all integers with the same sign, the order in which they were present in nums is preserved.
3) The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
*/

// (For integers with same sign, original order is preserved)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posIdx = 0, negIdx = 1;

        for(auto i: nums) {
            if(i > 0) {
                ans[posIdx] = i;
                posIdx += 2;
            } else {
                ans[negIdx] = i;
                negIdx += 2;
            }
        }
        return ans;
    }
};




// Another variation of question
// (For integers with same sign, original order may not be preserved)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posIdx = 0, negIdx = 1;

        while (posIdx < n && negIdx < n) {
            if(nums[posIdx] > 0) {
                posIdx += 2;
            } else if(nums[negIdx] < 0) {
                negIdx += 2;
            } else {
                swap(nums[posIdx], nums[negIdx]);
            }
        }
        return nums;
    }
};