// https://www.scaler.com/problems/distinct-subsequences/

/*
Given two sequences A and B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Input 1:
 A = "abc"
 B = "abc"

Output 1:
 1


Input 2:
 A = "rabbbit" 
 B = "rabbit" 

Output 2:
 3
*/



/**
 * Solution (DP):
 * We keep a m*n matrix and scanning through string A, while
 * n = A.length() + 1
 * m = B.length() + 1 
 * 
 * each cell in matrix dp[i][j] means the number of distinct subsequences of 
 * B.substr(1...j) in A(1...i)
 * 
 * dp[i][j] = dp[i - 1][j]                (discard A[i])
 *              +  (dp[i-1][j-1] or 0)    (A[i] == B[j] and we are going to use A[i])
 *                                        (A[i] != B[j] so we could not use A[i])
 * 
 * while dp[i][0] = 1 and dp[0][j] = 0.
 */

int Solution::numDistinct(string A, string B) {
    int n = A.length();
    int m = B.length();

    if (m > n) return 0; // impossible for subsequence

    vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + (A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] : 0);
        }
    }
    return dp[n][m];
}





public class Solution {
    private String S;
    private String T;
    int[][] dp;
    int n;
    int nT;

    public int numDistinct(String S, String T) {
        if (T.length() > S.length()) return 0;
        n = S.length();
        nT = T.length();
        this.S = S;
        this.T = T;
        dp = new int[n][nT];
        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);
        return rec(0, 0);
    }

    public int rec(int sIndex, int tIndex) {
        if (tIndex == nT) return 1;
        if (sIndex >= n) return 0;
        if (dp[sIndex][tIndex] != -1) return dp[sIndex][tIndex];
        
        int res = 0;
        if (S.charAt(sIndex) == T.charAt(tIndex))
            res = rec(sIndex + 1, tIndex + 1);
        
        res += rec(sIndex + 1, tIndex);
        
        return dp[sIndex][tIndex] = res;
    }
}
