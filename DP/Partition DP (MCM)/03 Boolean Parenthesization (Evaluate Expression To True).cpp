// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
// https://www.interviewbit.com/problems/evaluate-expression-to-true/

// https://youtu.be/JbRsM2X2_pg


/*
Input: N = 7, S = T|T&F^T
Output: 4
Explaination: The expression evaluates to true in 4 ways 
((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
*/


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


// Method 1: memoized
class Solution{
public:
    const int mod = 1003;
    int dp[205][205][2];
    string expr, oper;
    int n;

    int go(int i, int j, int isTrue) {
        // Base Condition
        if (i == j) {
            if (isTrue == 1) {
                return expr[i] == 'T';
            } else {
                return expr[i] == 'F';
            }
        }
     
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int res = 0;
        for (int k = i; k < j; k++) {
            int leftT, leftF, rightT, rightF;

            // Count no. of T in left partition
            if (dp[i][k][1] == -1) {
                leftT = go(i, k, 1);
            } else {
                leftT = dp[i][k][1];
            }
     
            // Count no. of T in right partition
            if (dp[k + 1][j][1] == -1) {
                rightT = go(k + 1, j, 1);
            } else {
                rightT = dp[k + 1][j][1];
            }
     
            // Count no. of F in left partition
            if (dp[i][k][0] == -1) {
                leftF = go(i, k, 0);
            } else {
                leftF = dp[i][k][0];
            }
     
            // Count no. of F in right partition
            if (dp[k + 1][j][0] == -1) {
                rightF = go(k + 1, j, 0);
            } else {
                rightF = dp[k + 1][j][0];
            }

            if (oper[k] == '&') {
                if (isTrue == 1)
                    res += leftT * rightT;
                else
                    res += leftF * rightF + leftT * rightF + leftF * rightT;
            }
            
            if (oper[k] == '|') {
                if (isTrue == 1)
                    res += leftT * rightT + leftT * rightF + leftF * rightT;
                else
                    res += leftF * rightF;
            }
            
            if (oper[k] == '^') {
                if (isTrue == 1)
                    res += leftF * rightT + leftT * rightF;
                else
                    res += leftT * rightT + leftF * rightF;
            }

            res = (res + mod) % mod;
        }

        return dp[i][j][isTrue] = res % mod;
    }

    int countWays(int n, string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'T' || s[i] == 'F') {
                expr.push_back(s[i]);
            } else {
                oper.push_back(s[i]);
            }
        }

        n = expr.size();
        this->n = n;
        memset(dp, -1, sizeof dp);
        return go(0, expr.size() - 1, 1);
    }
};

















// Method 2: gap method
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
                        if (oper[k] == '&') {
                            T[i][j] += T[i][k] * T[k + 1][j];
                            F[i][j] += T[i][k] * F[k + 1][j]  + F[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j];
                        }
                        if (oper[k] == '|') {
                            F[i][j] += F[i][k] * F[k + 1][j];
                            T[i][j] += T[i][k] * F[k + 1][j]  + F[i][k] * T[k + 1][j] + T[i][k] * T[k + 1][j];
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
