// https://leetcode.com/problems/asteroid-collision/description/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        for(int y: a) {
            if(st.empty()) {
                st.push(y);
                continue;
            }
            
            if(y < 0) {
                while(!st.empty() && st.top() > 0 && st.top() < abs(y)) {
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(y)) {
                    st.pop();
                    continue;
                }
                if(!st.empty() && st.top() > 0) {
                    continue;
                }
            }
            st.push(y);
            
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
