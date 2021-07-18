// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    vector<vector<int>> dp;
	
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        dp = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        
		for(int i = 1; i <= n; i++) {
    		for(int j = 1; j <= m; j++) {
    			dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    		}
    	}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
    	return dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
    }
};
