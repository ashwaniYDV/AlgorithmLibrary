// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

/*
You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.

Input: s = "(abcd)"
Output: "dcba"

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 
Constraints:
1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.
*/


// Method 1 (Brute Force): O(n^2)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char c: s) {
            if(c == ')') {
                string tmp = "";
                while(st.top() != '(') tmp += st.top(), st.pop();
                st.pop();

                for(char x: tmp) st.push(x);
            } else {
                st.push(c);
            }
        }

        string res = "";
        while(!st.empty()) res += st.top(), st.pop();

        reverse(res.begin(), res.end());
        return res;
    }
};


// Method 2 (Brute Force): O(n^2)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParenthesesIdx;
        string res;

        for (char ch: s) {
            if (ch == '(') {
                // Store current length of res as start index for future reversal
                openParenthesesIdx.push(res.length());
            } else if (ch == ')') {
                int start = openParenthesesIdx.top();
                openParenthesesIdx.pop();
                // Reverse the substring between the matching parentheses
                reverse(res.begin() + start, res.end());
            } else {
                // Append non-parenthesis characters to the processed string
                res += ch;
            }
        }
        return res;
    }
};