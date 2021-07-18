// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

/*
Given a m x n matrix and an integer threshold.
Return the maximum side-length of a square with a sum less than or equal to threshold 
or return 0 if there is no such square.
*/


class Solution {
public:
    int n, m, k;

    void initDp(vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }

    int getSubmatrixSum(int r1, int c1, int r2, int c2, vector<vector<int>>& dp) {
        r1++, c1++, r2++, c2++;
        return dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1];
    }

    bool check(int mid, vector<vector<int>>& dp) {
        for(int i = 0; i <= n-mid; i++) {
            for(int j = 0; j <= m-mid; j++) {
                int r1 = i, c1 = j, r2 = i+mid-1, c2 = j+mid-1;
                if(getSubmatrixSum(r1, c1, r2, c2, dp) <= k) return true;
            }
        }

        return false;
    }

    // TTTTTTTFFFFFFF
    int maxSideLength(vector<vector<int>>& matrix, int threshold) {
        n = matrix.size(), m = matrix[0].size();
        k = threshold;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        initDp(matrix, dp);

        int lo = 0, hi = min(n, m);

        while(lo < hi) {
            // int mid = (lo + hi + 1) / 2;
            int mid = lo + (hi - lo + 1) / 2;
            
            if(check(mid, dp)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};





class Solution {
public:
    int n, m, k;

    void initDp(vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }

    int getSubmatrixSum(int r1, int c1, int r2, int c2, vector<vector<int>>& dp) {
        r1++, c1++, r2++, c2++;
        return dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1];
    }

    bool check(int mid, vector<vector<int>>& dp) {
        for(int i = 0; i <= n-mid; i++) {
            for(int j = 0; j <= m-mid; j++) {
                int r1 = i, c1 = j, r2 = i+mid-1, c2 = j+mid-1;
                if(getSubmatrixSum(r1, c1, r2, c2, dp) <= k) return true;
            }
        }

        return false;
    }

    // TTTTTTTFFFFFFF
    int maxSideLength(vector<vector<int>>& matrix, int threshold) {
        n = matrix.size(), m = matrix[0].size();
        k = threshold;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        initDp(matrix, dp);

        int lo = 0, hi = min(n, m);

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(check(mid, dp)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return hi;
    }
};