// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// https://www.geeksforgeeks.org/longest-repeating-subsequence/

/*
Problem: 
Given a string, find the length of the longest repeating subsequence such that the two subsequences don’t have same string character at the same position, 
i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string. 

Example:
Input = AABEBCDD
Output = 3
Since the longest repeating subsequence is "ABD"

*/

/*
This problem is just the modification of Longest Common Subsequence problem. 
The idea is to find the LCS(str, str) where str is the input string with the restriction that when both the characters are same, 
they shouldn’t be on the same index in the two strings. 
*/


class Solution {
    public:
        int LongestRepeatingSubsequence(string s) {
            int n = s.size();
            int dp[n + 1][n + 1];

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 0;
                    } else if (s[i - 1] == s[j - 1] && i != j) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }

            return dp[n][n];
        }
};







class Solution {
    public:
        int LongestRepeatingSubsequence(string s) {
            string s1 = s, s2 = s;
            int n1 = s1.size(), n2 = s2.size();

            int dp[n1 + 1][n2 + 1];
            for (int i = 0; i <= n1; i++) {
                for (int j = 0; j <= n2; j++) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 0;
                    } else if (s1[i - 1] == s2[j - 1] && i != j) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }

            return dp[n1][n2];
        }
};
