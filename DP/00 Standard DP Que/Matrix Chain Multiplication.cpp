// https://youtu.be/pEYwLmGJcvs
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
public:
    int matrixMultiplication(int n, int a[]) {
        int m = n - 1;
        int dp[m][m];
        
        for(int gap = 0; gap < m; gap++) {
            for(int i=0, j=gap;  j < m;  i++, j++) {
                if(gap == 0) {
                    dp[i][j] = 0;
                } else if(gap == 1) {
                    dp[i][j] = a[i] * a[j] * a[j+1];
                } else {
                	dp[i][j] = INT_MAX;
                    for(int k = i; k < j; k++) {
                    	int leftCost = dp[i][k];
                    	int rightCost = dp[k+1][j];
                    	int multiplyCost = a[i] * a[k+1] * a[j+1];
    
                    	dp[i][j] = min(dp[i][j], leftCost + rightCost + multiplyCost);
                    }
                }
            }
        }
    
        return dp[0][m-1];
    }
};
