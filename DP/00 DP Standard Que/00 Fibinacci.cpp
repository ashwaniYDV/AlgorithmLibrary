// https://leetcode.com/problems/fibonacci-number/

// top down
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        return fib(n - 1) + fib(n - 2);
    }
};


// bottom up
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;

        /*
        order of loop in bottom up is opposite of what we did in top down
        in top down -> index went from n to 0
        thus in bottom up -> index will move from 0 to n
        */
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};


// space optimized
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        
        int prev2 = 0, prev1 = 1;

        for(int i = 2; i <= n; i++) {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};



/*
Matrix Exponentiation
=====================
fib(n) = fib(n - 1) + fib(n - 2)

| F[x] |  =  | 1 1 | | F[x-1] |
|F[x-1]|     | 1 0 |.| F[x-2] |

|F[2]|  =  | 1 1 |.| F[1] |
|F[1]|     | 1 0 |.| F[0] |

|F[3]|  =  | 1 1 | | F[2] |  =  | 1 1 | | 1 1 | | F[1] |
|F[2]|     | 1 0 |.| F[1] |     | 1 0 |.| 1 0 |.| F[0] |

        =  | 1 1 | ^(2) | F[1] |
           | 1 0 |     .| F[0] |

| F[n] |  =  | 1 1 |^(n-1) | F[1] |
|F[n-1]|     | 1 0 |      .| F[0] |

| F[n] |  =  | 1 1 |^(n-1) | 1 |
|F[n-1]|     | 1 0 |      .| 0 |
*/

class Solution {
public:
    typedef vector<vector<int>> matrix;
    // matrix size
    int M = 2;

    matrix mul(matrix A, matrix B) {
        matrix C(M, vector<int>(M, 0));
        for(int i = 0; i < M; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k < M; k++)
                    C[i][j] += A[i][k] * B[k][j];
        return C;
    }

    // matrix pow(matrix A, int p) {
    //     if (p == 1) return A;
    //     if (p % 2) return mul(A, pow(A, p - 1));
        
    //     matrix X = pow(A, p / 2);
    //     return mul(X, X);
    // }

    matrix pow(matrix A, int p) {
        // identity matrix
        vector< vector<int> > result(M, vector<int>(M, 0));
        for(int i = 0; i < M; i++) {
            result[i][i] = 1;
        }
        
        while (p) {
            if (p & 1) result = mul(A, result);
            A = mul(A, A);
            p >>= 1;
        }
        return result;
    }

    int fib(int n) {
        if(n <= 1) return n;

        // create vector F1
        vector<int> F1 = {
            1,
            0
        };

        // create matrix T
        matrix T = {
            {1, 1},
            {1, 0}
        };

        // raise T to the (N-1)th power
        T = pow(T, n - 1);

        // the answer is the first row of T.F1
        int res = 0;
        for (int i = 0; i < M; i++) {
            res += T[0][i] * F1[i];
        }
        return res;
    }
};