// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/

/*
You are given a 0-indexed m x n matrix grid consisting of positive integers.
You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
    From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) 
    such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.
*/

class Solution {
public:
    int n, m;

    int f(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp) {
        if (j == m) return m - 1;

        if (dp[i][j] != -1) return dp[i][j];

        int res = j;

        if (i - 1 >= 0 && j + 1 < m && a[i][j] < a[i - 1][j + 1]) 
            res = max(res, f(i - 1, j + 1, a, dp));
        if (j + 1 < m && a[i][j] < a[i][j + 1]) 
            res = max(res, f(i, j + 1, a, dp));
        if (i + 1 < n && j + 1 < m && a[i][j] < a[i + 1][j + 1]) 
            res = max(res, f(i + 1, j + 1, a, dp));

        return dp[i][j] = res;
    }

    int maxMoves(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, f(i, 0, a, dp));
        }
        return res;
    }
};



class Solution {
public:
    int maxMoves(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = m - 2; j >= 0; j--) {
            for (int i = n - 1; i >= 0; i--) {
                int res = 0;

                if (i - 1 >= 0 && a[i][j] < a[i - 1][j + 1])
                    res = max(res, dp[i - 1][j + 1] + 1);

                if (a[i][j] < a[i][j + 1])
                    res = max(res, dp[i][j + 1] + 1);

                if (i + 1 < n && a[i][j] < a[i + 1][j + 1])
                    res = max(res, dp[i + 1][j + 1] + 1);

                dp[i][j] = res;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i][0]);
        }
        return res;
    }
};
