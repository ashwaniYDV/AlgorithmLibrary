// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

/*
dp[i][j] = max length of substring ending at indices i of s1 and j of s2
*/


// Method 1.1
class Solution {
public:
    int f(int pos1, int pos2, int count, string& s1, string& s2) {
        if(pos1 < 0 || pos2 < 0) return count;
    
        int res = count;
    
        if(s1[pos1] == s2[pos2]) {
            res = max(res, f(pos1 - 1, pos2 - 1, count + 1, s1, s2));
        } else {
            res = max({res, f(pos1 - 1, pos2, 0, s1, s2), f(pos1, pos2 - 1, 0, s1, s2)});
        }
    
        return res;
    }
    int longestCommonSubstr(string& s1, string& s2) {
        return f(s1.size() - 1, s2.size() - 1, 0, s1, s2);
    }
};

// Method 1.2
class Solution {
public:
    int f(int pos1, int pos2, string& s1, string& s2, int& maxLen, vector<vector<int>>& dp) {
        if (pos1 < 0 || pos2 < 0) return 0;
        
        if (dp[pos1][pos2] != -1) return dp[pos1][pos2];
        
        int res = 0;
        if (s1[pos1] == s2[pos2]) {
            res = 1 + f(pos1 - 1, pos2 - 1, s1, s2, maxLen, dp);
            maxLen = max(maxLen, res);
        }
        
        f(pos1 - 1, pos2, s1, s2, maxLen, dp);
        f(pos1, pos2 - 1, s1, s2, maxLen, dp);
        
        return dp[pos1][pos2] = res;
    }
    
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0;
        f(n - 1, m - 1, s1, s2, maxLen, dp);
        return maxLen;
    }
};

// Method 1.3
class Solution {
public:
    int f(int pos1, int pos2, string& s1, string& s2, vector<vector<int>>& dp) {
        if (pos1 < 0 || pos2 < 0) return 0;
        
        if (dp[pos1][pos2] != -1) return dp[pos1][pos2];
        
        if (s1[pos1] == s2[pos2]) {
            dp[pos1][pos2] = 1 + f(pos1 - 1, pos2 - 1, s1, s2, dp);
        } else {
            dp[pos1][pos2] = 0;
        }
        
        return dp[pos1][pos2];
    }
    
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxLen = max(maxLen, f(i, j, s1, s2, dp));
            }
        }
        
        return maxLen;
    }
};





// Method 2
class Solution {
public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n1 = s1.size(), n2=s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        int res = 0, pos;
        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if(dp[i][j] > res) {
                        res = dp[i][j];
                        pos = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        // cout << s1.substr(pos - res, res) << endl;
        return res;
    }
};
