// https://leetcode.com/problems/remove-invalid-parentheses/

/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
Return all the possible results. You may return the answer in any order.

Example 1:
Input: s = "()())()"
Output: ["(())()","()()()"]
*/

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

    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        vis[s] = 1;
        int flag = 0;
        
        vector<string> res;
        
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                string u = q.front();
                q.pop();

                if(isBalanced(u)) {
                    // marks the flag whether the solution is found at this level
                    flag = 1;
                    res.push_back(u);
                }
                
                // if we found solution in this level, no need to go further down
                if(flag) continue;

                for(int i = 0; i < u.size(); i++) {
                    if(s[i] == '(' or s[i] == ')') {
                        string v = u.substr(0, i) + u.substr(i+1);
                        if(vis[v]) continue;
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
            
            // finally break from this level
            if(flag) break;
        }
        
        return res;
    }
};
