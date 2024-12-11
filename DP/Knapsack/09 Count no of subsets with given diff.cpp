// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1


// Method 1
/*
Let there be two subsets with sum s1 and s2 respectively
s1 + s2 = arrSum
s1 - s2 = diff

So solving the above equations, we get:
s1 = (arr_sum + diff) / 2
s2 = (arr_sum - diff) / 2

Therefore, question reduces to:
find number of subsets with sum as s1
OR
find number of subsets with sum as s2

Prefer using s2 since s2 has (arr_sum - diff), so s2 will be smaller than s1 which uses (arr_sum + diff)
But make sure to check if s2 < 0, then no answer exists
*/
class Solution {
public:
    int countPartitions(vector<int>& a, int diff) {
        int n = a.size();
        int arrSum = accumulate(a.begin(), a.end(), 0);

        if ((arrSum - diff < 0) || (arrSum - diff) % 2) return 0;

        int sum = (arrSum - diff) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j < a[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};





// Method 2
class Solution {
public:
    int countPartitions(vector<int>& a, int diff) {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
    
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
    
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j < a[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
                }
            }
        }
    
        int res = 0;
        for (int j = 0; j <= sum; j++) {
            int sum1 = j;
            int sum2 = sum - j;
            if (sum1 >= sum2 && (sum1 - sum2 == diff)) {
                res += dp[n][sum1];
            }
        }
    
        return res;
    }
};