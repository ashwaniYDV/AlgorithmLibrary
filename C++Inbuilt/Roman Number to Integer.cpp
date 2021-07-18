// https://leetcode.com/problems/roman-to-integer/

/*
Input: s = "III"
Output: 3
Explanation: III = 3.

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/


class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n = s.size();

        int i = 0, num = 0;
        while(i < n) {
            if (i+1 < n && mp[s[i]] < mp[s[i+1]]) {
                num += mp[s[i+1]] - mp[s[i]];
                i += 2;
            } else {
                num += mp[s[i]];
                i += 1;
            }
        }
        return num;
    }
};