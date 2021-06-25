// https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1

/*
Answer = s.size() - LongestPalindromicSubsequenceLength 
*/

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        int n = s.size();
        int dp[n][n];

        for(int gap = 0; gap < n; gap++) {
            for(int i=0, j=gap;  j<n;  i++, j++) {
                dp[i][j] = 0;
                if(gap == 0) {
                    dp[i][j] = 1;
                } else if(gap == 1) {
                    if(s[i] == s[j]) dp[i][j] = 2;
                    else dp[i][j] = 1;
                } else {
                    if(s[i] == s[j]) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    } else {
                        dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                    }
                }
            }
        }

        return n - dp[0][n-1];
        
    } 
};
