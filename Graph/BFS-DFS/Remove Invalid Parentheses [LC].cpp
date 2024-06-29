// https://leetcode.com/problems/remove-invalid-parentheses/
// https://youtu.be/EE_9U798nvQ

/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
Return all the possible results. You may return the answer in any order.
*/

/*
The idea is to classify the solution into levels, like
level 0 - no character removed
level 1 - 1 character removed
level 2 - 2 characters removed
.
Also each level is traversed completely in one go so that, 
if solution is obtained there, we need not go to further levels, because we want minimum number of removals.
*/






// Method 1: RachitIITR
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

    vector<string> removeInvalidParentheses(string s) {
        map<string, bool> vis;
        queue<string> q;
        q.push(s);
        vis[s] = 1;
        bool found = 0;
        
        vector<string> res;
        
        while(!q.empty()){
            string u = q.front(); 
            q.pop();
		
            if(isBalanced(u)) {
                // marks the flag whether the solution is found at this level
                found = 1;
                res.push_back(u);
            }
		
            // if we found solution in this level, no need to go further down
            if(found) continue;
            
            for(int i = 0; i < u.size(); i++) {
                if(u[i] == '(' || u[i] == ')') {
                    string v = u.substr(0,i) + u.substr(i+1,u.size());
                    if(vis[v]) continue;
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        
        return res;
    }
};





// Method 2: Full concept of layer
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

    vector<string> removeInvalidParentheses(string s) {
        map<string, bool> vis;
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
            
            // no need to go to next level
            if(flag) break;
        }
        
        return res;
    }
};
