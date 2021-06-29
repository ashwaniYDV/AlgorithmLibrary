// https://leetcode.com/problems/scramble-string/


// https://youtu.be/MDmZm_aVDF8

class Solution {
public:
    unordered_map<string, bool> dp;
    bool solve(string s1, string s2) {
        if(s1.size() == 1) return s1 == s2;
        if(s1 == s2) return true;
        string key = s1 + s2;
        if(dp.find(key) != dp.end()) return dp[key];
        
        // Pruning: Avoid Unnecessary recursion calls
        int n = s1.size();
        vector<int> f1(26),f2(26);
        for(int i=0;i < n; i++) {
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }
        if(f1 != f2) return dp[key] = false;
        
        bool res = false;
        for(int i = 1; i < n; i++) {
            bool w = solve(s1.substr(0,i),s2.substr(0,i));
            bool x = solve(s1.substr(i),s2.substr(i));
            bool y = solve(s1.substr(0,i),s2.substr(n-i));
            bool z = solve(s1.substr(i),s2.substr(0,n-i));
            if((w and x) or (y and z)) return dp[key] = true;
        }
        return dp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        return solve(s1,s2);
    }
};
