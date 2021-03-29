// https://youtu.be/DJvw8jCmxUU
// https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string str, string pat) {
        int n = str.size(), m = pat.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // empty pattern can match with empty string 
        dp[0][0] = 1;

        // 
        for (int j = 1; j <= m; j++) {
            // assuming (j-2 >= 0) since pat will not start with '*'
            if (pat[j - 1] == '*' && (j-2 >= 0)) {
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
                    dp[i][j] = dp[i][j - 2];
                    if(pat[j - 2] == '.' || pat[j - 2] == str[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
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
