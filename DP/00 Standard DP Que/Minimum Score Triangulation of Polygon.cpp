// https://youtu.be/tmIhmeL8WRo
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// tags = { gap strategy, catalan number, Ways of Polygon Triangulation }

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if(n < 3) return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int gap = 0; gap < n; gap++) {
            for(int i = 0, j = gap;  j < n;  i++, j++) {
                if(gap == 0) {
                    dp[i][j] = 0;
                } else if(gap == 1) {
                    dp[i][j] = 0;
                } else if(gap == 2) {
                    dp[i][j] = values[i] * values[i+1] * values[i + 2];
                } else {
                    int mn = 1e9;
                    for (int k = i+1; k <= j-1; k++) {
                        int curTriangle = values[i] * values[k] * values[j];
                        int left = dp[i][k];
                        int right = dp[k][j];

                        mn = min(mn, curTriangle + left + right);
                    }
                    dp[i][j] = mn;
                }
            }
        }

        return dp[0][n - 1];
    }
};
