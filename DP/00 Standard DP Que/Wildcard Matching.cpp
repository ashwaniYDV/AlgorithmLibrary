class Solution {
public:
    string str, pat;
    int n, m;
    
    bool go(int s, int p, vector<vector<int>>& dp) {
        if(p == pat.length()) {
            return dp[s][p] = (s == str.length());
        }
        if(s == str.length()) {
            for(int i = p; i < pat.length(); i++) {
                if(pat[i] != '*') {
                    return (dp[s][p] = 0);
                }
            }
            return (dp[s][p] = 1);
        }

        if(dp[s][p] != -1) return dp[s][p];

        // ? -> match one
        if(pat[p] == '?' or pat[p] == str[s]) {
            return dp[s][p] = go(s+1, p+1, dp);
        }

        // * -> match all or match none
        if(pat[p] == '*') {
            return dp[s][p] = go(s+1, p, dp) or go(s, p+1, dp);
        }

        return dp[s][p] = 0;
    }
    
    bool isMatch(string str, string pattern) {
        this->str = str, this->pat = pattern;
        n = str.size(), m = pattern.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return go(0, 0, dp);
    }
};





















class Solution {
public:
    int dp_sol(string str, string pat, int n, int m){
        int dp[n + 1][m + 1];

        // empty pattern can only match with empty string 
        if (m == 0) return (n == 0); 

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
    
    bool isMatch(string str, string pattern) {
        return dp_sol(str, pattern, str.size(), pattern.size());
    }
};
