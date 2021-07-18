// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// https://youtu.be/vRVfmbCFW7Y?si=pOEztrKnieJ7CLT_

/*
Given a sequence of matrices, 
find most efficient way to multiply these matrices together.
Problem is not actually to perform multiplications, 
but merely to decide in which order to perform the multiplications.

We have many ways to multiply a chain of matrices because matrix multiplication is associative. 
Eg: if we had 4 matrices A, B, C, D => we would have: (ABC)D = (AB)(CD) = A(BCD) = ....
                     ABCD
                  /   |   \
                 /    |    \
                /     |     \
          (A)(BCD) (AB)(CD)  (ABC)(D)


However, order in which we parenthesize product,
affects no of simple arithmetic operations needed to compute the product.

Eg: suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then, 
(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.

Clearly the first parenthesization requires less number of operations.
Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i]. 
Write a function that should return min no of multiplications needed to multiply the chain.
*/


// Method 1 (Memoized)
class Solution {
public:
    #define INF 1e9
    int dp[105][105];

    int go(int a[], int i, int j) {
        // i = j = starting index of same matrix
        if (i == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        /*
        place parenthesis at different places between first and last matrix, 
        recursively calculate count of multiplications for each parenthesis placement 
        and return the minimum count

        A * B * C * D
        i           j

        k = i
        (A) * (B * C * D)

        k = i+1
        (A * B) * C * D)

        and so on...

        k = j-1
        (A * B * C) * (D)
        


        */
        int res = INF;
        for (int k = i; k < j; k++) {
            int leftCost = go(a, i, k);
            int rightCost = go(a, k + 1, j);
            /*
            left matrix size = a[i] * a[k+1]
            right matrix size = a[k+1] * a[j+1]
            multiply cost of left and right matrices = a[i] * a[k+1] * a[j+1]
            */
            int multiplyCost = a[i] * a[k + 1] * a[j + 1];
            res = min(res, leftCost + rightCost + multiplyCost);
        }

        return dp[i][j] = res;
    }

    int matrixMultiplication(int n, int a[]) {
        // no of matrices = n - 1
        int m = n - 1;
        memset(dp, -1, sizeof dp);

        /*
        arr[] = A*B*C*D = [x0, x1, x2, x3, x4]
                            i           j 
        A = x0 * x1
        B = x1 * x2
        C = x2 * x3
        D = x3 * x4

        i = starting index of matrix A = index of x0 = 0
        j = starting index of matrix D = index of x3 = n-2 = m-1
        */

        return go(a, 0, m - 1);
    }
};










// Method 2.1 (Gap method)
class Solution {
public:
    int matrixMultiplication(int n, int a[]) {
        int m = n - 1;
        int dp[m][m];

        for (int gap = 0; gap < m; gap++) {
            for (int i = 0, j = gap; j < m; i++, j++) {
                // single matrix
                if (gap == 0) {
                    dp[i][j] = 0;
                } 
                // two matrices
                else if (gap == 1) {
                    dp[i][j] = a[i] * a[j] * a[j + 1];
                } 
                else {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k < j; k++) {
                        int leftCost = dp[i][k];
                        int rightCost = dp[k + 1][j];
                        int multiplyCost = a[i] * a[k + 1] * a[j + 1];

                        dp[i][j] = min(dp[i][j], leftCost + rightCost + multiplyCost);
                    }
                }
            }
        }

        // Note: it is not dp[m-1][m-1]
        return dp[0][m - 1];
    }
};



// Method 2.2 (Gap method)
class Solution {
public:
    int matrixMultiplication(int n, int a[]) {
        int m = n - 1;
        int dp[m][m];

        for (int gap = 0; gap < m; gap++) {
            for (int i = 0, j = gap; j < m; i++, j++) {
                // single matrix
                if (gap == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k < j; k++) {
                        int leftCost = dp[i][k];
                        int rightCost = dp[k + 1][j];
                        int multiplyCost = a[i] * a[k + 1] * a[j + 1];

                        dp[i][j] = min(dp[i][j], leftCost + rightCost + multiplyCost);
                    }
                }
            }
        }

        return dp[0][m - 1];
    }
};
