// https://leetcode.com/problems/delete-columns-to-make-sorted-iii/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<int> dp(m, 1);
        int ans = 0;
        for(int col = 1; col < m; col++){
            for(int i = 0; i < col; i++) {
                bool isGood = true;
                for(int row = 0; row < n; row++) {
                    if (A[row][i] > A[row][col]) {
                        isGood = false;
                        break;
                    }
                }
                if (!isGood) continue;
                dp[col] = max(dp[col], dp[i] + 1);
            }
        }
        int maxLen = 0;
        for (int len : dp) maxLen = max(maxLen, len);
        return m - maxLen;
    }
};
