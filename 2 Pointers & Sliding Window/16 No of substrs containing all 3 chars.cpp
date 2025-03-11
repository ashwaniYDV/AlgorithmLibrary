// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Input: s = "abc"
Output: 1
 

Constraints:
3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/


class Solution {
public:
    int atLeastK(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;

        int l = 0, res = 0;
        for(int r = 0; r < n; r++) {
            mp[s[r]]++;

            while(mp.size() == k) {
                // count all valid substrs starting at index l => [l, , , r], [l, , r+1], [l, , r+2], ..., [l, , n-1]
                res += n - r;

                mp[s[l]]--;
                if(mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
        }

        return res;
    }
    int numberOfSubstrings(string s) {
        return atLeastK(s, 3);
    }
};
