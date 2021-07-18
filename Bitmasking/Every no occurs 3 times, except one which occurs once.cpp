// https://leetcode.com/problems/single-number-ii/

/*
Given an array where every element occurs three times, except one element which occurs only once. 
Find the element that occurs once.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32] = {0};
        for (int x : nums) {
            for (int i = 0; i < 32; i++) {
                if (x & (1 << i)) cnt[i]++;
            }
        }
        int number = 0;
        for (int i = 0; i < 32; i++) {
            if (cnt[i] % 3 == 1) number += (1 << i);
        }
        return number;
    }
};
