/*
================================================
https://leetcode.com/problems/decode-ways
================================================
*/


// Method 1.1 (Top down)
class Solution {
public:
    int n;
    bool isValid2DigitChar(string s) {
        // int x = stoi(s);
        // return (x >= 10 && x <= 26);
        return (s[0] == '1') || (s[0] == '2' && s[1] <= '6');
    }
    int f(int i, string& s, vector<int>& dp) {
        if(i == n) return 1;

        if(dp[i] != -1) return dp[i];

        int res = 0;

        // character cannot start with zero
        if(s[i] != '0') {
            // one digit character
            res += f(i+1, s, dp);

            // two digit character
            if(i+2 <= n && isValid2DigitChar(s.substr(i, 2))) {
                res += f(i+2, s, dp);
            }
        }

        return dp[i] = res;
    }
    int numDecodings(string s) {
        n = s.size();
        vector<int> dp(n+1, -1);
        return f(0, s, dp);
    }
};


// Method 1.2 (Bottom up)
class Solution {
public:
    int n;
    bool isValid2DigitChar(string s) {
        return (s[0] == '1') || (s[0] == '2' && s[1] <= '6');
    }

    int numDecodings(string s) {
        n = s.size();
        vector<int> dp(n+1, 0);

        dp[n] = 1;

        /*
        order of loop in bottom up is opposite of what we did in top down
        in top down -> index went from 0 to n
        thus in bottom up -> index will move from n to 0
        */
        for(int i = n-1; i >= 0; i--) {
            int res = 0;

            // character cannot start with zero
            if(s[i] != '0') {
                // one digit character
                res += dp[i+1];

                // two digit character
                if(i+2 <= n && isValid2DigitChar(s.substr(i, 2))) {
                    res += dp[i+2];
                }
            }

            dp[i] = res;
        }

        return dp[0];
    }
};

// Method 1.3 (space optimized)
class Solution {
public:
    int n;
    bool isValid2DigitChar(string s) {
        return (s[0] == '1') || (s[0] == '2' && s[1] <= '6');
    }

    int numDecodings(string s) {
        n = s.size();

        int next1 = 1;
        int next2 = 0;

        for(int i = n-1; i >= 0; i--) {
            int res = 0;

            // character cannot start with zero
            if(s[i] != '0') {
                // one digit character
                res += next1;

                // two digit character
                if(i+2 <= n && isValid2DigitChar(s.substr(i, 2))) {
                    res += next2;
                }
            }

            next2 = next1;
            next1 = res;
        }

        return next1;
    }
};








// Method 2.1 (Top down)
class Solution {
public:
    int n;
    bool isValid2DigitChar(string s) {
        return (s[0] == '1') || (s[0] == '2' && s[1] <= '6');
    }
    int f(int i, string& s, vector<int>& dp) {
        if(i == 0) return (s[0] != '0');

        if(dp[i] != -1) return dp[i];

        int res = 0;

        // one digit character
        if(s[i] != '0') {
            res += f(i - 1, s, dp);
        }
        // two digit character
        if(isValid2DigitChar(s.substr(i - 1, 2))) {
            if(i-2 >= 0)
                res += f(i - 2, s, dp);
            else
                res += 1;
        }

        return dp[i] = res;
    }
    int numDecodings(string s) {
        n = s.size();
        vector<int> dp(n+1, -1);
        return f(n - 1, s, dp);
    }
};


// Method 2.2 (Bottom up)
class Solution {
public:
    int n;
    bool isValid2DigitChar(string s) {
        return (s[0] == '1') || (s[0] == '2' && s[1] <= '6');
    }
    
    int numDecodings(string s) {
        n = s.size();
        vector<int> dp(n+1, 0);

        dp[0] = (s[0] != '0');

        /*
        order of loop in bottom up is opposite of what we did in top down
        in top down -> index went from n to 0
        thus in bottom up -> index will move from 0 to n
        */
        for(int i = 1; i < n; i++) {
            int res = 0;
            
            // one digit character
            if(s[i] != '0') {
                res += dp[i - 1];
            }
            // two digit character
            if(isValid2DigitChar(s.substr(i - 1, 2))) {
                if(i-2 >= 0)
                    res += dp[i - 2];
                else
                    res += 1;
            }

            dp[i] = res;
        }

        return dp[n-1];
    }
};


// Method 2.3 (space optimized)
class Solution {
public:
    int n;
    bool isValid2DigitChar(string s) {
        return (s[0] == '1') || (s[0] == '2' && s[1] <= '6');
    }
    
    int numDecodings(string s) {
        n = s.size();

        int prev1 = (s[0] != '0');
        int prev2 = 0;

        for(int i = 1; i < n; i++) {
            int res = 0;
            
            // one digit character
            if(s[i] != '0') {
                res += prev1;
            }
            // two digit character
            if(isValid2DigitChar(s.substr(i - 1, 2))) {
                if(i-2 >= 0)
                    res += prev2;
                else
                    res += 1;
            }

            prev2 = prev1;
            prev1 = res;
        }

        return prev1;
    }
};

















/*
================================================
https://leetcode.com/problems/decode-ways-ii/
================================================
*/

class Solution {
public:
    int n;
    int mod = 1e9+7;

    // * can take values from 1 to 9 only (not 0)
    int getValid2DigitChar(string s) {
        if(s[0] == '*' && s[1] == '*') return 15;
        if(s[0] == '*') {
            if(s[1] <= '6') return 2;
            return 1;
        }
        if(s[1] == '*') {
            if (s[0] == '1') return 9;
            if (s[0] == '2') return 6;
            return 0;
        }
        return (s[0] == '1') || (s[0] == '2' && s[1] <= '6');
    }

    long long f(int i, string& s, vector<long long>& dp) {
        if(i == n) return 1;

        if(dp[i] != -1) return dp[i];

        long long res = 0;

        // character cannot start with zero
        if(s[i] != '0') {
            // one digit character
            if(s[i] == '*') {
                res = (res + 9 * f(i+1, s, dp)) % mod;
            } else {
                res = (res + 1 * f(i+1, s, dp)) % mod;
            }

            // two digit character
            if(i+2 <= n) {
                res = (res + getValid2DigitChar(s.substr(i, 2)) * f(i+2, s, dp)) % mod;
            }
        }

        if (res < 0) res += mod;
        return dp[i] = res;
    }
    
    int numDecodings(string s) {
        n = s.size();
        vector<long long> dp(n+1, -1);
        return f(0, s, dp);
    }
};


class Solution {
public:
    int n;
    int mod = 1e9+7;

    // * can take values from 1 to 9 only (not 0)
    int getValid2DigitChar(string s) {
        if(s[0] == '*' && s[1] == '*') return 15;
        if(s[0] == '*') {
            if(s[1] <= '6') return 2;
            return 1;
        }
        if(s[1] == '*') {
            if (s[0] == '1') return 9;
            if (s[0] == '2') return 6;
            return 0;
        }
        return (s[0] == '1') || (s[0] == '2' && s[1] <= '6');
    }

    int numDecodings(string s) {
        n = s.size();
        vector<long long> dp(n+1, 0);

        dp[n] = 1;

        for(int i = n-1; i >= 0; i--) {
            long long res = 0;

            // character cannot start with zero
            if(s[i] != '0') {
                // one digit character
                if(s[i] == '*') {
                    res = (res + 9 * dp[i+1]) % mod;
                } else {
                    res = (res + 1 * dp[i+1]) % mod;
                }

                // two digit character
                if(i+2 <= n) {
                    res = (res + getValid2DigitChar(s.substr(i, 2)) * dp[i+2]) % mod;
                }
            }

            dp[i] = res;
        }

        return dp[0];
    }
};