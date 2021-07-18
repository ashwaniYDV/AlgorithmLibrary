// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

/*
Given a m * n matrix of ones and zeros, 
return how many square submatrices have all ones.
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
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof dp);
        
        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= m; j++){
        		if(matrix[i - 1][j - 1] == 1)
        			dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        	}
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= m; j++){
        		ans += dp[i][j];
        	}
        }
        return ans;
    }
};
