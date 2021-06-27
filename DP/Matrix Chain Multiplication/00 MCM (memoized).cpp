// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

class Solution {
public:
    #define INF 1e9
    int dp[105][105];

    int go(int a[], int i, int j) {
        if (i == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        /*
        place parenthesis at different places between first and last matrix, 
        recursively calculate count of multiplications for each parenthesis placement 
        and return the minimum count
        */
        int res = INF;
        for (int k = i; k < j; k++) {
            int leftCost = go(a, i, k);
            int rightCost = go(a, k + 1, j);
            int multiplyCost = a[i] * a[k + 1] * a[j + 1];
            res = min(res, leftCost + rightCost + multiplyCost);

        }

        return dp[i][j] = res;
    }
    int matrixMultiplication(int n, int a[]) {
        int m = n - 1;
        memset(dp, -1, sizeof dp);
        return go(a, 0, m - 1);
    }
};
