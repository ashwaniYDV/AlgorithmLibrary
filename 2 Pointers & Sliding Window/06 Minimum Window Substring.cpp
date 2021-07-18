// https://leetcode.com/problems/minimum-window-substring/

/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t 
(including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.
 

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Example 2:
Input: s = "a", t = "a"
Output: "a"
*/


class Solution {
public:
    map<char, int> freqS, freqT;

    bool check() {
        for (char ch = 'A'; ch <= 'Z'; ch++) if (freqS[ch] < freqT[ch]) return false;
        for (char ch = 'a'; ch <= 'z'; ch++) if (freqS[ch] < freqT[ch]) return false;
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        for (char ch : t) freqT[ch]++;
        int res = INT_MAX;

        int l = 0, startIdx = 0;
        bool  flag = 0;
        for (int r = 0; r < n; r++) {
            freqS[s[r]]++;

            while (freqS[s[l]] > freqT[s[l]]) {
                freqS[s[l]]--;
                l++;
            }

            if (check() && (r - l + 1 < res)) {
                flag = 1;
                res = r - l + 1;
                startIdx = l;
            }
        }

        return flag ? s.substr(startIdx, res) : "";
    }
};
