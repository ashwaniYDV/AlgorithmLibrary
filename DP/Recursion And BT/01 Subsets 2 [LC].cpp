// https://leetcode.com/problems/subsets-ii

/*
Given an integer array nums that may contain duplicates, return all possible subsets (power set).
The solution set must not contain duplicate subsets. 
Return the solution in any order.

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Input: nums = [0]
Output: [[],[0]]
*/

class Solution {
public:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);

        for(int j = i; j < nums.size(); j++) {
            if(j == i || nums[j] != nums[j-1]) {
                sub.push_back(nums[j]);
                subsets(nums, j + 1, sub, subs);
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
};