// https://leetcode.com/problems/unique-paths/


class Solution {
public:
    long long nCr(int n, int r) {
        if (n < r) return 0;
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 0; i < r; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    int uniquePaths(int m, int n) {
        return nCr((m - 1) + (n - 1), m - 1);
    }
};



class Solution {
public:
    int fun(int m, int n, vector<vector<int>>& dp) {
        if (m == 1 || n == 1) return 1;

        if (dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = fun(m - 1, n, dp) + fun(m, n - 1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return fun(m, n, dp);
    }
};



class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;

        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m - 1][n - 1];
    }
};
