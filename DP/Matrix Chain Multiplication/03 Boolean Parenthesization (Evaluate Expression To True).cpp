// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
// https://www.interviewbit.com/problems/evaluate-expression-to-true/

// https://youtu.be/JbRsM2X2_pg

/*
& operator
T & T = T
T & F = F
F & T = F
F & F = F

| operator
T | T = T
T | F = T
F | T = T
F | F = F

^ operator
T ^ T = F
T ^ F = T
F ^ T = T
F ^ F = F
*/

class Solution {
public:
    const int mod = 1003;
    int countWays(int n, string s) {
        vector < char > expr;
        vector < char > oper;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'T' || s[i] == 'F') {
                expr.push_back(s[i]);
            } else {
                oper.push_back(s[i]);
            }
        }

        n = expr.size();
        vector < vector < int >> T(n, vector < int > (n, 0));
        vector < vector < int >> F(n, vector < int > (n, 0));

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (gap == 0) {
                    if (expr[i] == 'T') {
                        T[i][i] = 1;
                        F[i][i] = 0;
                    }
                    if (expr[i] == 'F') {
                        T[i][i] = 0;
                        F[i][i] = 1;
                    }
                } else {
                    for (int k = i; k < j; k++) {
                        int tik = T[i][k] + F[i][k];
                        int tkj = T[k + 1][j] + F[k + 1][j];

                        if (oper[k] == '&') {
                            T[i][j] += T[i][k] * T[k + 1][j];
                            F[i][j] += tik * tkj - T[i][k] * T[k + 1][j];
                        }
                        if (oper[k] == '|') {
                            F[i][j] += F[i][k] * F[k + 1][j];
                            T[i][j] += tik * tkj - F[i][k] * F[k + 1][j];
                        }
                        if (oper[k] == '^') {
                            T[i][j] += F[i][k] * T[k + 1][j] + T[i][k] * F[k + 1][j];
                            F[i][j] += T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j];
                        }

                        T[i][j] = (T[i][j] + mod) % mod;
                        F[i][j] = (F[i][j] + mod) % mod;
                    }
                }
            }
        }

        return (T[0][n - 1] + mod) % mod;
    }
};
