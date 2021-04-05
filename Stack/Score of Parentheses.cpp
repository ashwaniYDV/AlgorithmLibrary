// https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                bal++;
            } else {
                bal--;
                if (S[i-1] == '(') {
                    ans += (1 << bal);
                }
            }
        }

        return ans;
    }
};


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
