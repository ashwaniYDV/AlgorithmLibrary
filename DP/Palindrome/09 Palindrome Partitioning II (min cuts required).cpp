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
    
    bool isPalindrome(int start, int end, string& s) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    // min no of palin sub-strings
    int fun(int i, string& s, vector<int>& dp) {
        if(i == n) {
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int res = 1e9;
        for(int j = i; j < n; j++) {
            if(isPalindrome(i, j, s)) {
                res = min(res, 1 + fun(j + 1, s, dp));
            }
        }
        
        return dp[i] = res;
    }
    int minCut(string s) {
        n = s.size();
        vector<int> dp(n+1, -1);
        // no of cuts = no of palin strings - 1
        return fun(0, s, dp) - 1;
    }
};









// Method 2.1 (O(n^2))
class Solution {
public:
    int n;
    vector<vector<bool>> isPalindrome;
    
    void precomputeIsPalindrome(string& s) {
        int n = s.size();
        isPalindrome.resize(n, vector<bool>(n, false));

        for(int gap = 0; gap < n; gap++) {
            for(int i = 0, j = gap;  j < n;  i++, j++) {
                if(gap == 0) {
                    isPalindrome[i][j] = true;
                } else if(gap == 1) {
                    if(s[i] == s[j]) isPalindrome[i][j] = true;
                } else {
                    if(s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }
    }
    
    // min no of palin sub-strings
    int fun(int i, string& s, vector<int>& dp) {
        if(i == n) {
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int res = 1e9;
        for(int j = i; j < n; j++) {
            if(isPalindrome[i][j]) {
                res = min(res, 1 + fun(j + 1, s, dp));
            }
        }
        
        return dp[i] = res;
    }
    int minCut(string s) {
        n = s.size();
        vector<int> dp(n+1, -1);

        precomputeIsPalindrome(s);

        // no of cuts = no of palin strings - 1
        return fun(0, s, dp) - 1;
    }
};

















// Method 2.2 (O(n^2))
/*
dp[i] = min no of palindromic strings in length i
res = dp[n] - 1
*/
class Solution {
public:
    int n;
    vector<vector<bool>> isPalindrome;
    
    void precomputeIsPalindrome(string& s) {
        int n = s.size();
        isPalindrome.resize(n, vector<bool>(n, false));

        for(int gap = 0; gap < n; gap++) {
            for(int i = 0, j = gap;  j < n;  i++, j++) {
                if(gap == 0) {
                    isPalindrome[i][j] = true;
                } else if(gap == 1) {
                    if(s[i] == s[j]) isPalindrome[i][j] = true;
                } else {
                    if(s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                    }
                }
            }
        }
    }
    
    int minCut(string s) {
        n = s.size();
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