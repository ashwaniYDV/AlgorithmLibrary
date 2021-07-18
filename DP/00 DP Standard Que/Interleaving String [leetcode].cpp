// https://leetcode.com/problems/interleaving-string/

/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Input: s1 = "", s2 = "", s3 = ""
Output: true
*/


// Method 1 O(n^3)
class Solution {
public:
    int n1, n2, n3;
    string s1, s2, s3;
    int dp[205][205][205];
    
    bool go(int i1, int i2, int i3) {
        if(i3 == n3) {
            return (i1 == n1 && i2 == n2);
        }
        
        if(dp[i1][i2][i3] != -1) return dp[i1][i2][i3];
        
        bool res = false;
        
        if(s1[i1] == s3[i3]) {
            res |= go(i1+1, i2, i3 + 1);
        }
        if(s2[i2] == s3[i3]) {
            res |= go(i1, i2 + 1, i3 + 1);
        }
        
        return dp[i1][i2][i3] = res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        this->s1 = s1, this->s2 = s2, this->s3 = s3;
        memset(dp, -1, sizeof dp);
        return go(0, 0, 0);
    }
};









// Method 2 O(n^2)
/*
i3 is redundant since i3 = i1 + i2
*/
class Solution {
public:
    int n1, n2, n3;
    string s1, s2, s3;
    int dp[205][205];
    
    bool go(int i1, int i2) {
        int i3 = i1 + i2;
        if(i1 + i2 == n3) {
            return (i1 == n1 && i2 == n2);
        }
        
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        bool res = false;
        
        if(s1[i1] == s3[i3]) {
            res |= go(i1 + 1, i2);
        }
        if(s2[i2] == s3[i3]) {
            res |= go(i1, i2 + 1);
        }
        
        return dp[i1][i2] = res;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        this->s1 = s1, this->s2 = s2, this->s3 = s3;
        memset(dp, -1, sizeof dp);
        return go(0, 0);
    }
};
