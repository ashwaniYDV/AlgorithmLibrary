/*
The idea is to classify the solution into levels, like
level 0 - no character removed
level 1 - 1 character removed
level 2 - 2 characters removed
.
Also each level is traversed completely in one go so that, 
if solution is obtained there, we need not go to further levels, because we want minimum number of removals.
*/

// Method 1
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

        vector<string> res;
        int flag = 0;
        
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
            // if we found solution in this level, no need to go further down.
            if(flag) break;
        }
        return res;
    }
};




















// Method 2
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

        vector<string> res;
        int flag = 0;
        
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                string u = q.front();
                q.pop();
                
                if(vis[u]) continue;
                vis[u] = 1;

                if(isBalanced(u)) {
                    // marks the flag whether the solution is found at this level
                    flag = 1;
                    res.push_back(u);
                }

                if(flag) continue;

                for(int i = 0; i < u.size(); i++) {
                    if(s[i] == '(' or s[i] == ')') {
                        string v = u.substr(0, i) + u.substr(i+1);
                        q.push(v);
                    }
                }
            }
            // if we found solution in this level, no need to go further down.
            if(flag) break;
        }
        return res;
    }
};
