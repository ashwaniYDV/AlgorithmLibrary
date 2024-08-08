// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

/*
Example 1:
Input: s = "())"
Output: 1

Example 2:
Input: s = "((("
Output: 3

Example 3:
Input: s = "()"
Output: 0

Example 4:
Input: s = "()))(("
Output: 4
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, res = 0;
        for (char x : s) {
            if (x == '(') {
                cnt++;
            } 
            if(x == ')') {
                cnt--;
                if (cnt < 0) {
                    cnt = 0;
                    res++;
                }
            }
        }
        return res + cnt;
    }
};
