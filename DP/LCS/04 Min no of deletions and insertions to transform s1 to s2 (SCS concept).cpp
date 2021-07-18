// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
// https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/

/*
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. 
The task is to remove/insert the minimum number of characters from/in str1 to transform it into str2. 
It could be possible that the same character needs to be removed from one point of str1 and inserted to some another point.
*/

// Method 1
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

    int minOperations(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        int LCS = lcs(s1, s2);
        int deletion = n1 - LCS, insertion = n2 - LCS;

        return insertion + deletion;
    }
};





// Method 2
class Solution {
    public:
        string lcs(string s1, string s2) {
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

            int maxLength = dp[n1][n2];
            string ans = "";
            int i = n1, j = n2;
            while (i > 0 && j > 0) {
                if (s1[i - 1] == s2[j - 1]) {
                    ans = s1[i - 1] + ans;
                    i--, j--;
                } else if (dp[i - 1][j] > dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
            return ans;
        }

    int minOperations(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 == 0) return n2;
        if (n2 == 0) return n1;

        int insertion = 0, deletion = 0;

        int i = 0, j = 0;
        for (char c: lcs(s1, s2)) {
            while (s1[i] != c) {
                i++;
                deletion++;
            }
            while (s2[j] != c) {
                j++;
                insertion++;
            }
            i++, j++;
        }

        deletion += (n1 - i);
        insertion += (n2 - j);

        return insertion + deletion;

    }
};
