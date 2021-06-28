class Solution {
public:
    //Function to find minimum number of attempts needed in order to find the critical floor.
    int eggDrop(int n, int k) {
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof dp);

        // i = egg, j = floor
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                // only 1 egg
                if (i == 1) {
                    dp[i][j] = j;
                }
                // only 1 floor
                else if (j == 1) {
                    dp[i][j] = 1;
                } else {
                    int mn = INT_MAX;
                    for (int mj = j - 1, pj = 0; mj >= 0; mj--, pj++) {
                        // egg survives
                        int v1 = dp[i][mj];
                        // egg breaks
                        int v2 = dp[i - 1][pj];

                        int val = max(v1, v2);
                        mn = min(mn, val);
                    }

                    dp[i][j] = mn + 1;
                }
            }
        }

        return dp[n][k];
    }
};
