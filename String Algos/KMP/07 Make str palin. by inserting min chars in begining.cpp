// https://leetcode.com/problems/shortest-palindrome/

/*
You are given a string s. You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.

Input: s = "aacecaaa"
Output: "aaacecaaa"

Input: s = "abcd"
Output: "dcbabcd"
*/

class Solution {
public:
    vector<int> prefix_function(string &s) {
        int n = (int)s.length();
        vector<int> pi(n);
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
        return pi;
    }

    string shortestPalindrome(string str) {
        int n = str.size();

        string revStr = str;
        reverse(revStr.begin(), revStr.end());
        
        string concat = str + "$" + revStr;
        vector < int > lps = prefix_function(concat);
        
        int noOfCharsToAddInfront = (n - lps.back());
        return revStr.substr(0, noOfCharsToAddInfront) + str;
    }
};






// https://www.scaler.com/problems/make-string-pallindrome/
/*
Given a string A of size N consisting only of lowercase alphabets. The only operation allowed is to insert characters in the beginning of the string.
Find and return how many minimum characters are needed to be inserted to make the string a palindrome string.

Problem Constraints
1 <= N <= 10^6

Input 1:
A = "abc"
Ans = 2

Input 2:
A = "bb"
Ans = 0
*/

vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
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
    return pi;
}

int Solution::solve(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    string concat = str + "$" + revStr;
    vector < int > lps = prefix_function(concat);
    return (str.length() - lps.back());
}
