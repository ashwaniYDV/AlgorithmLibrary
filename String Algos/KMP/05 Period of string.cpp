// https://leetcode.com/problems/repeated-substring-pattern/

/*
Check if given string is periodic.

Condition of periodicity:
(pi[n - 1] > 0) && (n % period == 0);      where period = (n - pi[n - 1])
*/


/*
Note:
s1 = abcdabcd
This is periodic

s2 = abcdabcdab
This is non periodic

But in both cases period = (n - pi[n - 1]) = 4
*/




/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:
Input: s = "aba"
Output: false
*/

class Solution {
public:
    bool prefix_function(string &s) {
        int n = (int)s.length();
        vector<int> pi(n);
        pi[0] = 0;
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j-1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }
        int period = n - pi[n - 1];
        return pi[n - 1] && (n % period == 0);
    }
    
    bool repeatedSubstringPattern(string s) {
        return prefix_function(s);
    }
};
