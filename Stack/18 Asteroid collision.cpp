// https://leetcode.com/problems/asteroid-collision/description/

/*
We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet. 

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
*/

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
