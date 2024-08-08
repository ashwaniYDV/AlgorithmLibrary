// https://leetcode.com/problems/score-of-parentheses/

/*
Given a balanced parentheses string s, return the score of the string.
The score of a balanced parentheses string is based on the following rule:
1.) "()" has score 1.
2.) AB has score A + B, where A and B are balanced parentheses strings.
3.) (A) has score 2 * A, where A is a balanced parentheses string.

Input: s = "()"
Output: 1

Input: s = "(())"
Output: 2

Input: s = "()()"
Output: 2

Input: s = "(()(()))"
Output: 6
*/


// Time: O(n), Space: O(1)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int cnt = 0, res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') cnt++;
            if(s[i] == ')') cnt--;
            
            if(i > 0 && s[i-1] == '(' && s[i] == ')') {
                res += pow(2, cnt);
            }
        }
        return res;
    }
};






// Time: O(n), Space: O(n)
class Solution {
public:
    static const int N = 55;
    int closingBrac[N];
    
    int fun(int l, int r) {
        if(l + 1 == r) return 1;
        
        if(closingBrac[l] == r) return 2 * fun(l+1, r-1);
        
        return fun(l, closingBrac[l]) + fun(closingBrac[l] + 1, r);
    }
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                int x = st.top();
                closingBrac[x] = i;
                st.pop();
            }
        }
        return fun(0, n-1);
    }
};






// Time: O(n), Space: O(n)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int res = 0;
        stack<int> st;
        for(char x: s) {
            if(x == '(') {
                st.push(res);
                res = 0;
            } else {
                res = st.top() + max(2*res, 1);
                st.pop();
            }
        }
        return res;
    }
};
