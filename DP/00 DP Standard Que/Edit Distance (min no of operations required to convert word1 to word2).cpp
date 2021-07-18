// https://leetcode.com/problems/edit-distance/

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:
1) Insert a character
2) Delete a character
3) Replace a character
*/

// Method 1
class Solution {
public:
    const int N = 505;
    const int INF = 1e9;
    
    int n, m;
    string s, t;
    
    int go(int si, int ti, vector<vector<int>>& dp) {
        if(ti == m) {
            // since we have to delete the remaining (n-si) trailing letters of s
            return (n - si);
        }
    
        if(si == n) {
            // since we have to insert the remaining (m-ti) trailing letters of t after s
            return (m - ti);
        }
        
        if(dp[si][ti] != -1) return dp[si][ti];
    
        int res = INF;
        
        if(s[si] == t[ti]) {
            res = min(res, go(si+1, ti+1, dp));
        } else {
            // when s[si] is removed
            res = min(res, 1 + go(si + 1, ti, dp));
            // when t[ti] is inserted before s[si]
            res = min(res, 1 + go(si, ti + 1, dp));
            // when s[si] is replaced by t[ti]
            res = min(res, 1 + go(si + 1, ti + 1, dp));
        }

        return dp[si][ti] = res;
    }
    
    int minDistance(string word1, string word2) {
        s = word1, t = word2;
        n = s.size(), m = t.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        
        return go(0, 0, dp);
    }
};








// Method 2
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        int dp[n + 1][m + 1];
        
        // if word2 is empty we have to remove all characters from word1
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        
        // if word1 is empty we have to add all characters to word1
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        
        // we have three cases replace, delete, insert
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 1 + min(replace, delete, insert)
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};
