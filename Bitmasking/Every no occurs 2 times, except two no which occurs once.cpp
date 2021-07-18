// https://leetcode.com/problems/single-number-iii/description/

/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.

Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(int x: nums) {
            res = res ^ x;
        }

        // find the rightmost set bit position
        int temp = res, pos = 0;
        while (temp) {
            if (temp & 1) {
                break;
            }
            pos++;
            temp >>= 1;
        }

        int mask = (1 << pos);
        int firstNum = 0, secondNum = 0;
        for(int x: nums) {
            if (mask & x) {
                firstNum = firstNum ^ x;
            }
        }
        secondNum = res ^ firstNum;
        return {firstNum, secondNum};
    }
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(int x: nums) {
            res = res ^ x;
        }

        // find the rightmost set bit position
        int mask = 0;
        for(int i = 0; i < 31; i++) {
            if(res & (1 << i)) {
                mask = (1 << i);
                break;
            }
        }

        int firstNum = 0, secondNum = 0;
        for(int x: nums) {
            if (mask & x) {
                firstNum = firstNum ^ x;
            }
        }
        secondNum = res ^ firstNum;
        return {firstNum, secondNum};
    }
};









class Solution {
public:
    // this function is used to prevernt int overflow
    // rsb = x & -x
    int RSB(int x) {
        long long minusX = x;
        minusX = -minusX;
        return (int)(x & minusX);
    }
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for (int x : nums) {
            res = res ^ x;
        }

        // find the rightmost set bit value
        int mask = RSB(res);

        int firstNum = 0, secondNum = 0;
        for (int x : nums) {
            if (mask & x) {
                firstNum = firstNum ^ x;
            }
        }
        secondNum = res ^ firstNum;
        return {firstNum, secondNum};
    }
};
