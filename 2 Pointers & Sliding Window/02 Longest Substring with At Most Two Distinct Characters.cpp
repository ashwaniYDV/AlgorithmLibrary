// https://www.lintcode.com/problem/928/

/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

Example 1
Input: “eceba”
Output: 3
Explanation:
T is "ece" which its length is 3.

Example 2
Input: “aaa”
Output: 3
*/

/*
This question can be generalised for atmost k distinct characters.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        int n = s.size();
        int k = 2;
        map<char, int> freq;
        int res = 0;
        
        int l = 0, r = 0;
        while(r < n) {
            freq[s[r]]++;
            while(freq.size() > k) {
                char ch = s[l];
                freq[ch]--;
                if(freq[ch] == 0) freq.erase(ch);
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
