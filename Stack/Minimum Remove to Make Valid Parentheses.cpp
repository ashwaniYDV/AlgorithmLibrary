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






















// TLE solution
class Solution {
public:
    bool isBalanced(string s) {
        int cnt = 0;
        for(char x: s) {
            if(x == '(') cnt++;
            if(x == ')') cnt--;
            if(cnt < 0) return false;
        }
        return (cnt == 0);
    }
    
    map<string, bool> vis;
    
    string minRemoveToMakeValid(string s) {
        queue<string> q;
        q.push(s);
        
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                string u = q.front();
                q.pop();
                
                if(vis[u]) continue;
                vis[u] = 1;

                if(isBalanced(u)) {
                    return u;
                }

                for(int i = 0; i < u.size(); i++) {
                    if(s[i] == '(' or s[i] == ')') {
                        string v = u.substr(0, i) + u.substr(i+1);
                        q.push(v);
                    }
                }
            }
        }
        return "";
    }
};
