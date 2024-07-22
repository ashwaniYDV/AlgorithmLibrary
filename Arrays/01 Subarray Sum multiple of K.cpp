// https://leetcode.com/problems/continuous-subarray-sum/

/*
Given an integer array nums and an integer k, 
return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:
a) its length is at least two, and
b) the sum of the elements of the subarray is a multiple of k.

Note that:
* An integer x is a multiple of k if there exists an integer n such that x = n * k. 
* 0 is always a multiple of k.
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        mp[0] = -1;

        int prefSum = 0;
        for(int i = 0; i < n; i++) {
            prefSum += nums[i];
            int remainder = prefSum % k;

            if(mp.count(remainder)) {
                int len = i - mp[remainder];
                if(len > 1) return true;
            }

            if(!mp.count(remainder)) {
                mp[remainder] = i;
            }
        }

        return false;
    }
};