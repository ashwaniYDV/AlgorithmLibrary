// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    int n;
    vector<vector<string> > res;
    
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void fun(int pos, string s, vector<string> path) {
        if(pos == n) {
            res.push_back(path);
            return;
        }
        for(int i = pos; i < n; ++i) {
            if(isPalindrome(s, pos, i)) {
                path.push_back(s.substr(pos, i - pos + 1));
                fun(i+1, s, path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> path;
        fun(0, s, path);
        return res;
    }
};
