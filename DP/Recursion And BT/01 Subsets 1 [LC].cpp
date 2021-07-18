// https://leetcode.com/problems/subsets/

/*
Given an integer array nums of unique elements, return all possible subsets (power set).
The solution set must not contain duplicate subsets. 
Return the solution in any order. 

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Input: nums = [0]
Output: [[],[0]]
*/


class Solution {
public:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        if(i == nums.size()) {
            subs.push_back(sub);
            return;
        }

        subsets(nums, i + 1, sub, subs);
        
        sub.push_back(nums[i]);
        subsets(nums, i + 1, sub, subs);
        sub.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
};



class Solution {
public:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);

        for(int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
};