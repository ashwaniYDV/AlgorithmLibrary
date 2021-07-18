/*
Utkarsh Gupta => Watch from 29:00
https://unacademy.com/class/matrix-exponentiation-and-matrix-operations/VOM2NSM6

CodeNCode
https://youtu.be/Y-slDsjyxmY?si=hkpST9ku-bBXQgfv
https://youtu.be/X-91JW7u_iw?si=ayDcsrpZZ6sTCP5R
*/

/*
calculates fib(n) in O(logn) time

fib(n) = fib(n - 1) + fib(n - 2)
fib(0) = 0
fib(1) = 1
*/

/*
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



Time Complexity = O(M^3 * log(N))
M = size of transformation matrix
*/



#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> matrix;
const int M = 2;
const int MOD = 1e9+7;

matrix mul(matrix A, matrix B) {
    matrix C(M, vector<int>(M, 0));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            for(int k = 0; k < M; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, int p) {
    if (p == 1) return A;

    matrix res = A;
    p--;

    while(p > 0) {
        if(p & 1) res = mul(res, A);
        A = mul(A, A);
        p = p >> 1;
    }

    return res;
}

// returns the N-th term of Fibonacci sequence
int fib(int N) {
    if (N <= 1) return N;

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
    T = pow(T, N-1);

    // the answer is the first row of T.F1
    int res = 0;
    for(int i = 0; i < M; i++) {
        res = (res + T[0][i] * F1[i]) % MOD;
    }
    return res;
}

int32_t main() {
    int n = 6;
    cout << fib(n) << endl;
}











typedef vector<vector<int>> matrix;
const int M = 2;
const int MOD = 1e9+7;

matrix mul(matrix A, matrix B) {
    matrix C(M, vector<int>(M, 0));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            for(int k = 0; k < M; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, int p) {
    // identity matrix
    vector< vector<int> > result(M, vector<int>(M, 0));
    for(int i = 0; i < M; i++) {
        result[i][i] = 1;
    }
    
    while (p > 0) {
        if (p & 1) result = mul(A, result);
        A = mul(A, A);
        p >>= 1;
    }
    return result;
}

// returns the N-th term of Fibonacci sequence
int fib(int N) {
    if (N <= 1) return N;

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
    T = pow(T, N-1);

    // the answer is the first row of T.F1
    int res = 0;
    for(int i = 0; i < M; i++) {
        res = (res + T[0][i] * F1[i]) % MOD;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
}














const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;

const long long _MOD = static_cast<long long>(MOD) * MOD;

struct Matrix {
    vector< vector<int> > mat;
    int n_rows, n_cols;
 
    Matrix() {}
 
    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()), n_cols(values[0].size()) {}
 
    static Matrix identity_matrix(int n) {
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            values[i][i] = 1;
        }
        return values;
    }
 
    Matrix operator*(const Matrix &other) const {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                long long tmp = 0;
                for(int k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while(tmp >= _MOD)
                        tmp -= _MOD;
                }
                result[i][j] = tmp % MOD;
            }
 
        return move(Matrix(move(result)));
    }
 
    inline bool is_square() const {
        return n_rows == n_cols;
    }
};
Matrix pw(Matrix a, int p){
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0) {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}
 
void solve(){
    cin >> n;
    if(n <= 1) {
        cout << n << endl;
        return;
    }
    
    vector<vector<int>> T = {
        {1,1},
        {1,0}
    };
    
    vector<vector<int>> col = 
    {
        {1},
        {0}
    };
    
    int ans = (pw(T,n-1) * col).mat[0][0];
    cout << ans << endl;
}
