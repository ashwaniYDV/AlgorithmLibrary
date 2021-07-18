// https://www.scaler.com/problems/maximum-submatrix-sum-row-wise-and-column-wise-sorted-matrix

/*
Given a row-wise and column-wise sorted matrix A of size N * M.
Return the maximum non-empty submatrix sum of this matrix.
Problem Constraints
1 <= N, M <= 1000
-109 <= A[i][j] <= 109
*/


/*
Imagine you had the same problem but with a 1D array. That is if the array was sorted and find the maximum subarray.
What would be the answer? The answer will be the sum of one of the suffixes right? So we could check over all suffix arrays
and return the maximum sum. The sum of all suffix arrays can be computed in O(N).
Now apply the same logic on a 2D matrix.
What is a suffix matrix? A matrix whose right lower corner is always the N*M th element. 
Now we can have iterate over all the possible top left corners which is N*M. So N*M matrices.
The sum of each of these matrices can be computed in O(1) with a precomputation of O(N*M).
Return the maximum sum of all these matrices. 
Time Complexity - O(N * M)
Space Complexity - O(N * M)
*/


public class Solution {
    public long solve(int[][] A) {
        int n = A.length;
        int m = A[0].length;
        long dp[][] = new long[n][m];
        dp[n-1][m-1] = A[n-1][m-1];
        long ans = dp[n-1][m-1];
        for(int j=m-2 ; j>=0 ; j--){
            dp[n-1][j] = dp[n-1][j+1] + A[n-1][j];
            ans = Math.max(ans, dp[n-1][j]);
        }
        for(int i=n-2 ; i>=0 ; i--){
            dp[i][m-1] = dp[i+1][m-1] + A[i][m-1];
            ans = Math.max(ans, dp[i][m-1]);
        }
        for(int i=n-2 ; i>=0 ; i--){
            for(int j=m-2 ; j>=0 ; j--){
                dp[i][j] = A[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
                ans = Math.max(ans, dp[i][j]);
            }
        }
        return ans;
    }
}
