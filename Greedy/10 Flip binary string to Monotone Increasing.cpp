// https://leetcode.com/problems/flip-string-to-monotone-increasing/

/*
A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
You are given a binary string s. 
You can flip s[i] changing it from 0 to 1 or from 1 to 0.
Return the minimum number of flips to make s monotone increasing.

Example 1:
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Example 2:
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

Example 3:
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
*/


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int totalZeros = 0;
        for (char x : s) if (x == '0') totalZeros++;

        // convert all 0s to 1s or all 1s to 0s
        int res = min(totalZeros, n - totalZeros);

        int zerosLeft = 0, zerosRight = 0, onesLeft = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zerosLeft++;
            onesLeft = (i + 1) - zerosLeft;
            zerosRight = totalZeros - zerosLeft;

            // convert onesLeft to 0s and zerosRight to 1s
            res = min({res, onesLeft + zerosRight});
        }
        return res;
    }
};
