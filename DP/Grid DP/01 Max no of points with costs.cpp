// https://leetcode.com/problems/maximum-number-of-points-with-cost/
// https://leetcode.com/problems/maximum-number-of-points-with-cost/solutions/1344908/c-java-python-3-dp-explanation-with-pictures-o-mn-time-o-n-space/

/*
You are given an m x n integer matrix points (0-indexed). 
Starting with 0 points, you want to maximize the number of points you can get from the matrix.
To gain points, you must pick one cell in each row. 
Picking the cell at coordinates (r, c) will add points[r][c] to your score.
However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. 
For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
Return the maximum number of points you can achieve.

Input: points = [[1,2,3],
                [1,5,1],
                [3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
*/

// TLE solution [Time = O(n^3)]
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long long> dp(n, 0), dpPrev(n, 0);

        for(int j = 0; j < m; j++) {
            dpPrev[j] = points[0][j];
            dp[j] = dpPrev[j];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                long long mx = INT_MIN;
                for(int k = 0; k < m; k++) {
                    mx = max(mx, points[i][j] + dpPrev[k] - abs(j - k));
                }
                dp[j] = mx;
            }

            dpPrev = dp;
        }

        int res = dp[0];
        for(int x: dp) res = max(res, x);
        return res;
    }
};


// [Time = O(n^2)]
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long long> dp(m, 0), prevDp(m, 0);

        for(int j = 0; j < m; j++) {
            dp[j] = points[0][j];
        }
        prevDp = dp;

        for(int i = 1; i < n; i++) {
            vector<long long> prevDpLeftMax(m, 0), prevDpRightMax(m, 0);
            
            prevDpLeftMax[0] = prevDp[0];
            for(int j = 1; j < m; j++) {
                prevDpLeftMax[j] = max(prevDpLeftMax[j - 1] - 1, prevDp[j]);
            }

            prevDpRightMax[m - 1] = prevDp[m - 1];
            for(int j = m - 2; j >= 0; j--) {
                prevDpRightMax[j] = max(prevDpRightMax[j + 1] - 1, prevDp[j]);
            }

            for(int j = 0; j < m; j++) {
                dp[j] = points[i][j] + max(prevDpLeftMax[j], prevDpRightMax[j]);
            }
            
            prevDp = dp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};