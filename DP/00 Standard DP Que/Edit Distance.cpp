// https://leetcode.com/problems/edit-distance/

// Method 1
class Solution {
public:
    const int N = 505;
    const int INF = 1e9;
    
    int n, m;
    string s, t;
    
    int go(int si, int ti, vector<vector<int>>& dp) {
        if(ti == m && si <= n) {
            // since we have to delete the remaining (n-si) trailing letters of s
            return (n - si);
        }
    
        if(ti < m && si == n) {
            // since we have to insert the remaining (m-ti) trailing letters of t after s
            return (m - ti);
        }
        
        if(dp[si][ti] != -1) return dp[si][ti];
    
        int res = INF;
        
        if(s[si] == t[ti]) {
            res = min(res, go(si+1, ti+1, dp));
        } else {
            // when s[si] is removed
            res = min(res, 1 + go(si + 1, ti, dp));
            // when t[ti] is inserted before s[si]
            res = min(res, 1 + go(si, ti + 1, dp));
            // when s[si] is replaced by t[ti]
            res = min(res, 1 + go(si + 1, ti + 1, dp));
        }

        return dp[si][ti] = res;
    }
    
    int minDistance(string s, string t) {
        this->s = s, this->t = t;
        n = s.size(), m = t.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        
        return go(0, 0, dp);
    }
};








// Method 2
