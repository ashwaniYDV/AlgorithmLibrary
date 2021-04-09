// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        
        for(char x: s) {
            if(x != '(' and x != ')') {
                st.push(x);
            }
            else if(x == '(') {
                cnt++;
                st.push(x);
            }
            else if(x == ')' && cnt > 0) {
                cnt--;
                st.push(x);
            }
        }
        
        int n = st.size() - cnt;
        string res(n, '\0');
        int idx = 0;
        while(!st.empty()) {
            char x = st.top();
            st.pop();
            if(cnt > 0 && x == '(') {
                cnt--;
            } else {
                res[n-1-idx] = x;
                idx++;
            }
        }
        
        return res;
    }
};
