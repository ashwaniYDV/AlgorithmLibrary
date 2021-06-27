// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. 
In other words, no matter how we parenthesize the product, the result will be the same. 
For example, if we had four matrices A, B, C, and D, we would have: 
(ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, 
or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,  
(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
Clearly the first parenthesization requires less number of operations.
Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i]. 
We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain. 
*/

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
