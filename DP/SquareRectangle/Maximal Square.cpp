// https://leetcode.com/problems/maximal-square/
// https://www.youtube.com/watch?v=RElcqtFYTm0&feature=emb_logo

/*
dp[i][j] means the size of biggest square with A[i-1][j-1] as bottom-right corner.
dp[i][j] also means the number of squares with A[i-1][j-1] as bottom-right corner.

If A[i][j] == 0, no possible square.
If A[i][j] == 1,
we compare the size of square dp[i-1][j-1], dp[i-1][j] and dp[i][j-1].
min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 is the maximum size of square that we can find.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        int side=0;
        
        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= m; j++){
        		if(matrix[i - 1][j - 1] == '1'){
        			dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                    side = max(side, dp[i][j]);
                }
        	}
        }
        return side * side;
    }
};
