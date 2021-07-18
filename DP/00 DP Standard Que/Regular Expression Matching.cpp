// https://leetcode.com/problems/regular-expression-matching/
// https://youtu.be/DJvw8jCmxUU

/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
a) '.' Matches any single character.
b) '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
 

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:
Input: s = "mississippi", p = "mis*is*p*."
Output: false
 

Constraints:
1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/



/*
1) If p[j] == s[i]: dp[i][j] = dp[i-1][j-1];
2) If p[j] == '.' : dp[i][j] = dp[i-1][j-1];
3) If p[j] == '*':
    Two sub conditions:
    3.1) if p[j-1] == s[i] or p[i-1] == '.':
                  dp[i][j] = dp[i-1][j]  // in this case, a* counts as multiple a
               or dp[i][j] = dp[i][j-2]  // in this case, a* counts as empty
    3.2) if p[j-1] != s[i] and p[j-1] != '.': dp[i][j] = dp[i][j-2]  // in this case, a* only counts as empty
*/



class Solution {
public:
    int n, m;

    bool go(int i, int j, string& str, string &pat, vector<vector<int>>& dp) {
        if (j == m) return i == str.size();

        if (i < n && dp[i][j] != -1) return dp[i][j];

        if (pat[j + 1] == '*') {
            // if pattern repeats for 0 time
            if (go(i, j + 2, str, pat, dp)) return dp[i][j] = 1;

            // if pattern repeats for at least 1 time
            if (i < n && (pat[j] == str[i] || pat[j] == '.')) {
                if (go(i + 1, j, str, pat, dp)) return dp[i][j] = 1;
                i++;
            }
        }
        // Current characters are considered as matching in two cases
        // (a) current character of pattern is '.'
        // (b) characters actually match
        else if (i < n && (pat[j] == '.' || str[i] == pat[j])) {
            return dp[i][j] = go(i + 1, j + 1, str, pat, dp);
        }
        // no match
        return dp[i][j] = 0;
    }

    bool isMatch(string str, string pat) {
        n = str.size(), m = pat.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return go(0, 0, str, pat, dp);
    }
};










class Solution {
public:
    bool isMatch(string str, string pat) {
        int n = str.size(), m = pat.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // empty pattern can match with empty string
        dp[0][0] = 1;

        // empty str
        for (int j = 1; j <= m; j++) {
            // assuming (j-2 >= 0) since pat will not start with '*'
            // a* only counts as empty
            if (pat[j - 1] == '*' && (j - 2 >= 0)) {
                dp[0][j] = dp[0][j - 2];
            } else {
                // pat[j - 1] = '.' or 'character'
                dp[0][j] = 0;
            }
        }

        // String cannot match with empty pattern
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[j - 1] == '*') {
                    if (pat[j - 2] == '.' || pat[j - 2] == str[i - 1]) {
                        // a* counts as multiple a || counts as empty
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    } else {
                        // a* only counts as empty
                        dp[i][j] = dp[i][j - 2];
                    }
                }

                // Current characters are considered as matching in two cases
                // (a) current character of pattern is '.'
                // (b) characters actually match
                else if (pat[j - 1] == '.' || str[i - 1] == pat[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // If characters don't match (str[i-1] != pat[j-1])
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};



















/*
1) If p[j] == s[i]: dp[i][j] = dp[i-1][j-1];
2) If p[j] == '.' : dp[i][j] = dp[i-1][j-1];
3) If p[j] == '*':
    Two sub conditions:
    3.1) if p[j-1] == s[i] or p[i-1] == '.':
                  dp[i][j] = dp[i-1][j]  // in this case, a* counts as multiple a
               or dp[i][j] = dp[i][j-2]  // in this case, a* counts as empty
    3.2) if p[j-1] != s[i] and p[j-1] != '.': dp[i][j] = dp[i][j-2]  // in this case, a* only counts as empty
*/

class Solution {
public:
    bool isMatch(string str, string pat) {
        int n = str.size(), m = pat.size();
        if (n == 0 || m == 0) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

        // empty pattern can match with empty string
        dp[0][0] = true;

        // empty str
        for (int j = 1; j <= m; j++) {
            // assuming (j - 2 >= 0) since pat will not start with '*'
            // a* only counts as empty
            if (pat[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1 ; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (pat[j - 1] == str[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (pat[j - 1] == '*') {
                    if (pat[j - 2] == str[i - 1] || pat[j - 2] == '.') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[n][m];
    }
};
