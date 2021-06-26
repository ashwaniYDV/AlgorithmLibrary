// https://leetcode.com/problems/delete-operation-for-two-strings/

/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.
*/

class Solution {
public:
    int lcs(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int dp[n1 + 1][n2 + 1];
        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
    
    int minDistance(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int LCS = lcs(s1, s2);
        return n1 + n2 - 2 * LCS;
    }
};
