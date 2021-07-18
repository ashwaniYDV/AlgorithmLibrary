// https://leetcode.com/problems/wildcard-matching/

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
a) '?' Matches any single character.
b) '*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).


Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input: s = "acdcb", p = "a*c?b"
Output: false
*/

class Solution {
public:
    string str, pat;

    bool go(int s, int p, vector<vector<int>>& dp) {
        if (p == pat.length()) {
            return dp[s][p] = (s == str.length());
        }
        if (s == str.length()) {
            for (int i = p; i < pat.length(); i++) {
                if (pat[i] != '*') {
                    return (dp[s][p] = 0);
                }
            }
            return dp[s][p] = 1;
        }

        if (dp[s][p] != -1) return dp[s][p];

        bool res;
        
        // ? -> match one
        if (pat[p] == '?' or pat[p] == str[s]) {
            res = go(s + 1, p + 1, dp);
        }
        // * -> match all or match none
        else if (pat[p] == '*') {
            res = go(s + 1, p, dp) || go(s, p + 1, dp);
        }
        // characters don't match
        else {
            res = false;
        }
        
        return dp[s][p] = res;
    }

    bool isMatch(string str, string pattern) {
        this->str = str, this->pat = pattern;
        int n = str.size(), m = pattern.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return go(0, 0, dp);
    }
};













class Solution {
public:
    bool isMatch(string str, string pat) {
        int n = str.size(), m = pat.size();

        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);

        // empty pattern can match with empty string
        dp[0][0] = 1;

        // Only '*' can match with empty string
        for (int j = 1; j <= m; j++) {
            if (pat[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        // fill the table in bottom-up fashion
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Two cases if we see a '*'
                // a) We ignore ‘*’ character and move to next character in pattern,
                // i.e., ‘*’ indicates an empty sequence.
                // b) '*' character matches with ith character in input
                if (pat[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }

                // Current characters are considered as matching in two cases
                // (a) current character of pattern is '?'
                // (b) characters actually match
                else if (pat[j - 1] == '?' || str[i - 1] == pat[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // If characters don't match
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};
