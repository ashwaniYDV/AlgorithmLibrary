// https://leetcode.com/problems/missing-number/

/*
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 

Input: nums = [0,1]
Output: 2

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
*/


// This colution can overflow for large n
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n + 1)) / 2;
        for(int i = 0; i < n; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};


// Time = O(2*n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        for(int i = 0; i <= n; i++) mask ^= i;
        for(int x: nums) mask ^= x;
        return mask;
    }
};

// Time = O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        for(int i = 0; i < n; i++) {
            mask ^= nums[i];
            mask ^= i;
        }
        mask ^= n;
        return mask;
    }
};