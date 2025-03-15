// https://leetcode.com/problems/longest-common-subsequence/

/*
dp[i][j] = longest common subsequence ending at indices i of s1 and j of s2
*/


// Method 1
ll fun(int pos1, int pos2, string s1, string s2) {
    if(pos1 < 0 || pos2 < 0) return 0;

    if(s1[pos1] == s2[pos2]) {
        return 1 + fun(pos1 - 1, pos2 - 1, s1, s2);
    } else {
        return max(fun(pos1 - 1, pos2, s1, s2), fun(pos1, pos2 - 1, s1, s2));
    }
}


// Method 2
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, 0));

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

        string ans = "";
        int i = n1, j = n2;
        while(i > 0 && j > 0) {
            if(s1[i - 1] == s2[j - 1]) {
                ans += s1[i-1];
                i--, j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;

        int maxLength = dp[n1][n2];
        return maxLength;
    }
};

// Method 3
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> dpPrev(n2 + 1, 0), dpCur(n2 + 1, 0);

        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                if(i == 0 || j == 0) {
                    dpCur[j] = 0;
                } else if(s1[i - 1] == s2[j - 1]) {
                    dpCur[j] = dpPrev[j - 1] + 1;
                } else {
                    dpCur[j] = max(dpPrev[j], dpCur[j - 1]);
                }
            }

            dpPrev = dpCur;
        }

        int maxLength = dpPrev[n2];
        return maxLength;
    }
};


// Method 4
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<string>>dp(n1 + 1, vector<string>(n2 + 1, ""));

        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = "";
                } else if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                } else {
                    dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size() ?  dp[i - 1][j] : dp[i][j - 1];
                }
            }
        }

        cout << dp[n1][n2] << endl;

        return dp[n1][n2].size();
    }
};
