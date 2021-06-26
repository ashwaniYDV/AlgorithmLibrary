// Exact same code of [06 Min no of deletions to make a string palindrome.cpp]

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
// https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

class Solution {
public:
    int lcs(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int dp[n1 + 1][n2 + 1];
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return lcs(s, s2);
    }
    int minInsertions(string s) { 
        int n = s.size();
        return n - longestPalindromeSubseq(s);
    } 
};
