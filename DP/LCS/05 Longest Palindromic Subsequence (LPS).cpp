// https://leetcode.com/problems/longest-palindromic-subsequence/

/*
LPS(s) = LCS(s, reverse(s))
*/

// Method 1 (LCS method)
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
};







// Method 2 (Gap method)
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
};
