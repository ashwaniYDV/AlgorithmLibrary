class NumMatrix {
public:
	vector<vector<int>> dp;
    	NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m = n>0 ? matrix[0].size() : 0;
    	// dp.resize(n+1, vector<int>(m+1));
        dp = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        for(int i=0; i<n+1; i++){
    		for(int j=0; j<m+1; j++){
    			if(i==0 || j==0){
    				dp[i][j]=0;
    			}else{
    				dp[i][j]=dp[i-1][j]+dp[i][j-1]+matrix[i-1][j-1]-dp[i-1][j-1];
    			}
    		}
    	}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
    	return dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
