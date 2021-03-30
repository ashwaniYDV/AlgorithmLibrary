// https://leetcode.com/problems/palindrome-partitioning-ii/

// Method 1 (accepted)
class Solution {
public:
    int n;
    string s;
    
    bool isPalindrome(int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    int fun(int pos, vector<int>& dp) {
        if(pos == n) {
            return 0;
        }
        
        if(dp[pos] != -1) return dp[pos];
        
        int res = 1e9;
        for(int i = pos; i < n; ++i) {
            if(isPalindrome(pos, i)) {
                res = min(res, 1 + fun(i+1, dp));
            }
        }
        
        return dp[pos] = res;
    }
    int minCut(string s) {
        n = s.size();
        this->s = s;
        vector<int> dp(n+1, -1);
        // no of cuts = no of palin strings - 1
        return fun(0, dp) - 1;
    }
};


// Method 2 (TLE)
class Solution {
public:
    bool isPalindrome(int start, int end, string s) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;  // dp[0] denotes empty string
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(isPalindrome(j, i - 1, s)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        // no of cuts = no of palin strings - 1
        return dp[n] - 1;
    }
};
