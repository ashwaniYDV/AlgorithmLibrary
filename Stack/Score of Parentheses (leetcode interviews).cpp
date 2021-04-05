// https://leetcode.com/problems/score-of-parentheses/

// Time: O(n), Space: O(1)
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
