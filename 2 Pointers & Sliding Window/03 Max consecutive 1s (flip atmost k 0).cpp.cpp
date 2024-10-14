// https://leetcode.com/problems/max-consecutive-ones-iii/

/*
Given a binary array nums and an integer k, 
return max number of consecutive 1's in the array if you can flip at most k 0's.

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        int zeroCount = 0, res = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (a[r] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (a[l] == 0) {
                    zeroCount--;
                }
                l++;
            }

            res = max(res, r - l + 1);
        }
        
        return res;
    }
};