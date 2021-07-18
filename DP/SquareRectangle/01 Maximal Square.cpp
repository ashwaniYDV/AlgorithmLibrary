// https://leetcode.com/problems/maximal-square/
// https://www.youtube.com/watch?v=RElcqtFYTm0&feature=emb_logo

/*
Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.
*/

/*
dp[i][j] = size of biggest square with A[i][j] as bottom-right corner.
dp[i][j] = also means no of squares with A[i][j] as bottom-right corner.

2 cases:
* If A[i][j] == 0, 
    no possible square.
* If A[i][j] == 1,
    we compare the size of square dp[i-1][j-1], dp[i-1][j] and dp[i][j-1].
    min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 is the maximum size of square that we can find.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        
        int side = 0;
        
        for(int i = 1; i <= n; i++) {
        	for(int j = 1; j <= m; j++) {
        		if(matrix[i - 1][j - 1] == '1') {
        			dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                    side = max(side, dp[i][j]);
                }
        	}
        }
        return side * side;
    }
};




class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int dp[n][m];
        memset(dp, 0, sizeof dp);
        
        int side = 0;
        
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else if(matrix[i][j] == '1') {
        			dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }
                side = max(side, dp[i][j]);
        	}
        }
        return side * side;
    }
};