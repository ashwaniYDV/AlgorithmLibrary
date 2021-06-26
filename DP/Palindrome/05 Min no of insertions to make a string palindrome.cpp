// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

/*
Same solution of [04 Min no of deletions to make a string palindrome.cpp]
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) { 
        int n = s.size();
        int dp[n][n];

        for(int gap = 0; gap < n; gap++) {
            for(int i=0, j=gap;  j<n;  i++, j++) {
                dp[i][j] = 0;
                if(gap == 0) {
                    dp[i][j] = 1;
                } else if(gap == 1) {
                    if(s[i] == s[j]) dp[i][j] = 2;
                    else dp[i][j] = 1;
                } else {
                    if(s[i] == s[j]) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    } else {
                        dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                    }
                }
            }
        }
        return dp[0][n-1];   
    }
    int minInsertions(string s) { 
        int n = s.size();
        return n - longestPalindromeSubseq(s);
    } 
};
