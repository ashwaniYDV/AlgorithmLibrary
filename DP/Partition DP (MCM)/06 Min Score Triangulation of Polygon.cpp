// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// https://youtu.be/tmIhmeL8WRo
// tags = { gap strategy, catalan number, Ways of Polygon Triangulation }


/*
You have a convex n-sided polygon where each vertex has an integer value.
You are given an integer array values where values[i] is value of ith vertex (i.e., clockwise order).
You will triangulate the polygon into n - 2 triangles. 
For each triangle, value of that triangle is product of values of its vertices, 
and total score of triangulation is sum of these values over all n - 2 triangles.
Return smallest possible total score that you can achieve with some triangulation of polygon.

Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.
*/


/*
See this for solution insights:
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/C%2B%2B-with-picture

A convex polygon with n sides (n >= 3) can be cut into triangles by connecting vertices with non-crossing line segments (a form of polygon triangulation). 
No of triangles formed is (n - 2) and no of different ways that this can be achieved is Catalan(n - 2).
*/


class Solution {
public:
    const int INF = 1e9;
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if (n < 3) return 0;

        vector<vector<int>> dp(n, vector<int>(n, INF));

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap;  j < n;  i++, j++) {
                if (gap == 0) {
                    dp[i][j] = 0;
                } else if (gap == 1) {
                    dp[i][j] = 0;
                } else if (gap == 2) {
                    dp[i][j] = values[i] * values[i + 1] * values[i + 2];
                } else {
                    dp[i][j] = INF;
                    for (int k = i + 1; k <= j - 1; k++) {
                        int curTriangle = values[i] * values[k] * values[j];
                        int left = dp[i][k];
                        int right = dp[k][j];

                        dp[i][j] = min(dp[i][j], curTriangle + left + right);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};








class Solution {
public:
    const int INF = 1e9;
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if (n < 3) return 0;

        vector<vector<int>> dp(n, vector<int>(n, INF));

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap;  j < n;  i++, j++) {
                if (gap == 0) {
                    dp[i][j] = 0;
                } else if (gap == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INF;
                    for (int k = i + 1; k <= j - 1; k++) {
                        int curTriangle = values[i] * values[k] * values[j];
                        int left = dp[i][k];
                        int right = dp[k][j];

                        dp[i][j] = min(dp[i][j], curTriangle + left + right);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
