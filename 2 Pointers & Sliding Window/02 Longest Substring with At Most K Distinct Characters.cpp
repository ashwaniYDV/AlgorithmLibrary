// https://www.lintcode.com/problem/386

/*
Given a string S, find the length of the longest substring T that contains at most k distinct characters.

Example 1:
Input: S = "eceba" and k = 3
Output: 4
Explanation: T = "eceb"

Example 2:
Input: S = "WORLD" and k = 4
Output: 4
Explanation: T = "WORL" or "ORLD"
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        int n = s.size();
        map<char, int> freq;
        int res = 0;
        
        int l = 0;
        for(int r = 0; r < n; r++) {
            freq[s[r]]++;
            while(freq.size() > k) {
                char ch = s[l];
                freq[ch]--;
                if(freq[ch] == 0) freq.erase(ch);
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
