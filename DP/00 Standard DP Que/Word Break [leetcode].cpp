// https://leetcode.com/problems/word-break/

// Method: Top-down
class Solution {
public:
    int n;
    unordered_set<string> wordSet;
    
    bool go(int pos, string s, vector<int>& dp) {
        if (pos >= n)  return true;
        
        if (dp[pos] != -1) return dp[pos];
        
        for (int i = pos; i < n; i++) {
            if (wordSet.count(s.substr(pos, i - pos + 1)) && go(i + 1, s, dp)) {
                return dp[pos] = 1;
            }
        }
        return dp[pos] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(string s: wordDict) {
            wordSet.insert(s);
        }
        vector<int> dp(n, -1);
        return go(0, s, dp);
    }
};









// Method: Bottom-up
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        dp[0] = 1;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= i; j ++) {
                string tmp = s.substr(i - j, j);
                if(wordSet.find(tmp) != wordSet.end()) {
                    dp[i] = dp[i] || dp[i - j];
                    if(dp[i]) break;
                }
            }
        }
        
        return dp[n];
    }
};

