// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    int n;
    string s;
    vector<vector<string> > res;
    
    bool isPalindrome(int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void fun(int pos, vector<string> path) {
        if(pos == n) {
            res.push_back(path);
            return;
        }
        for(int i = pos; i < n; ++i) {
            if(isPalindrome(pos, i)) {
                path.push_back(s.substr(pos, i - pos + 1));
                fun(i+1, path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        n = s.size();
        this->s = s;
        vector<string> path;
        fun(0, path);
        return res;
    }
};
