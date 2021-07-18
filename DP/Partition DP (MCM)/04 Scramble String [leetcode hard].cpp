// https://leetcode.com/problems/scramble-string/
// https://github.com/joric/interviewbit/blob/master/programming/dynamic-programming/scramble-string.md

// https://youtu.be/MDmZm_aVDF8

/*
Problem:
We can scramble a string s to get a string t using the following algorithm:
1) If the length of the string is 1, stop.
2) If the length of the string is > 1, do the following:
   Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
   Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
   Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
*/




/*
Editorial:
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/


// Method 1
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
        return solve(s1,s2);
    }
};








// Method 2
/*
Instead of passing substring of s1 and s2, we are passing starting and ending indices of s1 and s2.
si1 = starting index of s1 
ei1 = ending index of s1
si2 = starting index of s2
ei2 = ending index of s2
*/
class Solution {
public:
    int dp[35][35][35][35];
    string s1, s2;
    
    bool solve(int si1, int ei1, int si2, int ei2) {
        if(si1 == ei1) return s1[si1] == s2[si2];
        int len = ei1 - si1 + 1;
        if(s1.substr(si1, len) == s2.substr(si2, len)) return true;
       
        if(dp[si1][ei1][si2][ei2] != -1) return dp[si1][ei1][si2][ei2];
        
        // Pruning: Avoid Unnecessary recursion calls
        vector<int> f1(26),f2(26);
        for(int i = si1, j = si2; i <= ei1; i++, j++) {
            f1[s1[i] - 'a']++;
            f2[s2[j] - 'a']++;
        }
        if(f1 != f2) return dp[si1][ei1][si2][ei2] = false;

        for(int i = 1; i < len; i++) {
            bool w = solve(si1, si1+i-1, si2, si2+i-1);
            bool x = solve(si1+i, ei1, si2+i, ei2);
            bool y = solve(si1, si1+i-1, ei2-i+1, ei2);
            bool z = solve(si1+i, ei1, si2, ei2-i);
            if((w and x) or (y and z)) return dp[si1][ei1][si2][ei2] = true;
        }
        return dp[si1][ei1][si2][ei2] = false;
    }
   
    bool isScramble(string s1, string s2) {
        this->s1 = s1, this->s2 = s2;
        int n = s1.size();
        memset(dp, -1, sizeof dp);
        return solve(0, n-1, 0, n-1);
    }
};








// Method 3
/*
Instead of passing (si1, ei1, si2, ei2) we can just pass (si1, ei1, len) to reduce from 4 state to 3 state dp
where len = length of current substrings
*/
class Solution {
public:
    int dp[35][35][35];
    string s1, s2;
    
    bool solve(int si1, int si2, int len) {
        int ei1 = si1 + len - 1;
        int ei2 = si2 + len - 1;
        if(len == 1) return s1[si1] == s2[si2];
        if(s1.substr(si1, len) == s2.substr(si2, len)) return true;
       
        if(dp[si1][si2][len] != -1) return dp[si1][si2][len];
        
        // Pruning: Avoid Unnecessary recursion calls
        vector<int> f1(26),f2(26);
        for(int i = si1, j = si2; i <= ei1; i++, j++) {
            f1[s1[i] - 'a']++;
            f2[s2[j] - 'a']++;
        }
        if(f1 != f2) return dp[si1][si2][len] = false;

        for(int i = 1; i < len; i++) {
            bool w = solve(si1, si2, i);
            bool x = solve(si1+i, si2+i, len - i);
            bool y = solve(si1, ei2-i+1, i);
            bool z = solve(si1+i, si2, len - i);
            if((w and x) or (y and z)) return dp[si1][si2][len] = true;
        }
        return dp[si1][si2][len] = false;
    }
   
    bool isScramble(string s1, string s2) {
        this->s1 = s1, this->s2 = s2;
        int n = s1.size();
        memset(dp, -1, sizeof dp);
        return solve(0, 0, n);
    }
};
