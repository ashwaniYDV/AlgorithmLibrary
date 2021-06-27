// https://leetcode.com/problems/palindrome-partitioning-ii/
// https://youtu.be/qmTtAbOTqcg

/*
Problem:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
*/


// Method 1 (O(n^3))  [can be made O(n^2) by precomputing isPalindrome using gap strategy as shown in the next method]
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




















// Method 2 (Method 1 optimized = O(n^2))
class Solution {
public:
    vector<vector<bool>> isPalindrome;
    int n;
    string s;
    
    void precomputeIsPalindrome(string s) {
        int n = s.size();
        isPalindrome.resize(n, vector<bool>(n));
        for(int gap = 0; gap < n; gap++) {
            for(int i=0, j=gap;  j<n;  i++, j++) {
                isPalindrome[i][j] = false;
                if(gap == 0) {
                    isPalindrome[i][j] = true;
                } else if(gap == 1) {
                    if(s[i] == s[j]) isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = false;
                } else {
                    if(s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = false;
                    }
                }
            }
        }
    }
    
    int fun(int pos, vector<int>& dp) {
        if(pos == n) {
            return 0;
        }
        
        if(dp[pos] != -1) return dp[pos];
        
        int res = 1e9;
        for(int i = pos; i < n; ++i) {
            if(isPalindrome[pos][i]) {
                res = min(res, 1 + fun(i+1, dp));
            }
        }
        
        return dp[pos] = res;
    }
    int minCut(string s) {
        n = s.size();
        this->s = s;
        precomputeIsPalindrome(s);
        
        vector<int> dp(n+1, -1);
        // no of cuts = no of palin strings - 1
        return fun(0, dp) - 1;
    }
};




















// Method 3 (O(n^2))
class Solution {
public:
    vector<vector<bool>> isPalindrome;
    
    void precomputeIsPalindrome(string s) {
        int n = s.size();
        isPalindrome.resize(n, vector<bool>(n));
        for(int gap = 0; gap < n; gap++) {
            for(int i=0, j=gap;  j<n;  i++, j++) {
                isPalindrome[i][j] = false;
                if(gap == 0) {
                    isPalindrome[i][j] = true;
                } else if(gap == 1) {
                    if(s[i] == s[j]) isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = false;
                } else {
                    if(s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = false;
                    }
                }
            }
        }
    }
    
    int minCut(string s) {
        int n = s.size();
        precomputeIsPalindrome(s);
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0; // dp[0] denotes empty string
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(isPalindrome[j][i - 1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        // no of cuts = no of palin strings - 1
        return dp[n] - 1;
    }
};
