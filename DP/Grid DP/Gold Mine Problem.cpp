// https://www.geeksforgeeks.org/gold-mine-problem
// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1

class Solution {
public:
    int maxGold(int n, int m, vector<vector<int>> mine) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            dp[i][0] = mine[i][0];
        }

        for(int j = 1; j < m; j++) {
            for(int i = 0; i < n; i++) {
                // basically
                // dp[i][j] = mine[i][j] + max({dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]})
                
                dp[i][j] = mine[i][j] + dp[i][j - 1];
                if(i - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], mine[i][j] + dp[i - 1][j - 1]);
                }
                if(i + 1 < n) {
                    dp[i][j] = max(dp[i][j], mine[i][j] + dp[i + 1][j - 1]);
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, dp[i][m - 1]);
        }

        return res;
    }
};
