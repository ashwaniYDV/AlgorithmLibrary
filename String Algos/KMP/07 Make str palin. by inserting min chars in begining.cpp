// https://leetcode.com/problems/shortest-palindrome/

/*
You are given a string s. You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.

Input: s = "aacecaaa"
Output: "aaacecaaa"

Input: s = "abcd"
Output: "dcbabcd"
*/


/*
Approach:
=========
- we can make a palindrome from a string S in this way:  S = S + reverse(S)
- but we have to make the shortest palindrome here which can be done by following the given below steps :
    - first make a string in this manner : palStr= S + "#" + reverse(S)
    - find suffix string of reverse(S) which is longest prefix string of S. It can be found in this manner:
           Use kmp algorithm to Build lps (longest prefix Suffix ) array 
           create a lps array for the palStr string
           last element of lps array is the longest suffix of reverse(S) which is also a prefix of S
- remove the longest suffix from the reverse(S)
- then append reverse(S) to the beginning of S and return that string

Example:
-S : "abcd"  
-revStr = "dcba"
-palStr = "abcd#dcba"
-lps array for palStr : [0,0,0,0,0,0,0,0,1] . so length of longest suffix is 1 (last element of lps array)
-after removing the longest suffix from revStr : revStr = "dcb"
-append revStr to the beginning of S :  ans ="dcbabcd"
-return ans
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
