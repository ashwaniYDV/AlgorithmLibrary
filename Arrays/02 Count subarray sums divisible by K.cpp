// https://leetcode.com/problems/subarray-sums-divisible-by-k/

/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
*/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mp(k + 1, 0);
        mp[0] = 1;

        int prefSumMod = 0, res = 0;

        for (int x : nums) {
            prefSumMod = (prefSumMod + x + k) % k;
            if (prefSumMod < 0) prefSumMod += k;

            res += mp[prefSumMod];
            mp[prefSumMod]++;
        }
        return res;
    }
};





class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;

        int prefSumMod = 0, res = 0;

        for (int x : nums) {
            prefSumMod = (prefSumMod + x + k) % k;
            if (prefSumMod < 0) prefSumMod += k;

            res += mp[prefSumMod];
            mp[prefSumMod]++;
        }
        return res;
    }
};


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;

        int prefSumMod = 0, res = 0;

        for (int x : nums) {
            prefSumMod = (prefSumMod + x + k) % k;
            if (prefSumMod < 0) prefSumMod += k;

            if (prefSumMod == 0) res++;

            res += mp[prefSumMod];
            mp[prefSumMod]++;
        }
        return res;
    }
};
