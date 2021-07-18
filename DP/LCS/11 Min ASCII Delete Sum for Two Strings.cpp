// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let", adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 

Constraints:
1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.
*/


// Method 1:
/*
If we find the maximum ASCII sum common subsequence, then the deletion part of s1 and s2 will give minimum value.
lcs = Maximum ASCII sum common subsequence
res = (ASCIIsumOfS1 - lcs) + (ASCIIsumOfS2 - lcs)
*/

class Solution {
public:
    int lcs(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int dp[n1 + 1][n2 + 1];
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 0;
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                    }
                    dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }

        return dp[n1][n2];
    }

    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        int sum1 = 0;
        for (int i = 0; i < n1; i++) {
            sum1 += s1[i];
        }
        int sum2 = 0;
        for (int i = 0; i < n2; i++) {
            sum2 += s2[i];
        }

        int LCS = lcs(s1, s2);
        return (sum1 - LCS) + (sum2 - LCS);
    }
};








// Method 2:
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1 , vector<int> (n2 + 1));
        dp[0][0] = 0;

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + s2[j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + s1[i - 1];
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1 , vector<int> (n2 + 1));
        dp[0][0] = 0;

        for (int i = 1 ; i <= n1; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        for (int j = 1; j <= n2; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
