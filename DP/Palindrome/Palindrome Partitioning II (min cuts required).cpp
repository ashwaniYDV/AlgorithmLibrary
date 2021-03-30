// https://leetcode.com/problems/palindrome-partitioning-ii/

// Method 1
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
        return fun(0, dp) - 1;
    }
};
