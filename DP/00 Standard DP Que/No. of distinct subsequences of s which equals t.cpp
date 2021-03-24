/*
Given two strings s and t, 
return the number of distinct subsequences of s which equals t.

Concept of standard "Edit Distance" DP problem is used
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        
        vector<vector<long>> dp(n + 1, vector<long>(m + 1, 0));
        
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





class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<uint32_t>> dp(n + 1, vector<uint32_t>(m + 1, 0));
        
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
