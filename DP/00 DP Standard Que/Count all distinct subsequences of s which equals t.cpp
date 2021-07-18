// https://leetcode.com/problems/distinct-subsequences/

/*
Given two strings s and t, 
return the number of distinct subsequences of s which equals t.

Concept of standard "Edit Distance" DP problem is used
*/


/*
dp[i][j] = no of subsequences of s[0...i] which are equal to substring t[0...j]
*/


// Bottom Up 1
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        
        vector<vector<long>> dp(n + 1, vector<long>(m + 1, 0));
        // dp[i][j] = no of subsequences of s[0...i] which are equal to substring t[0...j]
        
        // base case: when t is empty
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
};




// Bottom Up 2
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        
        vector<vector<uint32_t>> dp(n + 1, vector<uint32_t>(m + 1, 0));
        // dp[i][j] = no of subsequences of s[0...i] which are equal to substring t[0...j]
        
        // base case: when t is empty
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    // delete s[i-1] + no delete s[i-1]
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // must delete s[i-1]
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};








// Top Down
class Solution {
public:
    int n, m;
    string s, t;
    
    int go(int si, int ti, vector<vector<long>>& dp) {
        if(ti == m && si <= n) {
            return 1;
        }
        if(si >= n) {
            return 0;
        }
        
        if(dp[si][ti] != -1) return dp[si][ti];
        
        int res = 0;

        if(s[si] == t[ti]) {
            res += go(si+1, ti+1, dp);
        }
        res += go(si + 1, ti, dp);

        return dp[si][ti] = res;
    }
    int numDistinct(string s, string t) {
        this->s = s, this->t = t;
        n = s.size(), m = t.size();
        vector<vector<long>> dp(n + 1, vector<long>(m + 1, -1));
        return go(0, 0, dp);
    }
};











// TLE solution
class Solution {
public:
    struct node {
        int index;
        int size;
    };
    int numDistinct(string s, string t) {
        int n = s.size();

        queue<node> q;
        for(int i = 0; i < n; i++) {
            if(s[i] == t[0]) {
                q.push({i, 1});
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            node x = q.front();
            q.pop();

            int index = x.index;
            int size = x.size;

            if(size == t.size()) {
                cnt++;
            }

            for(int i = index + 1; i < n; i++) {
                if(s[i] == t[size]) {
                    q.push({i, size + 1});
                }
            }
        }

        return cnt;
    }
};
