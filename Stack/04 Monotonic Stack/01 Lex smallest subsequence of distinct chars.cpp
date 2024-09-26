// https://leetcode.com/problems/remove-duplicate-letters/
/*
Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Input: s = "bcabc"
Output: "abc"

Input: s = "cbacdcbc"
Output: "acdb"
*/


// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
/*
Given a string s, return lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

Input: s = "bcabc"
Output: "abc"

Input: s = "cbacdcbc"
Output: "acdb"
*/



/*
Intuition for both the problems
-------------------------------
* Only put those characters in stack which form valid string.
* We try to put the character's only once & maintain the lexicographicall smallest one

Approach
1) Push in stack:
* only those characters are pushed which are not already there in the stack using visited map.
2) Pop from Stack (to keep the stack monotonic increasing so that smallest character is first):
* while stack is not empty and current character of s is smaller than stack.top()
* while popping we need to keep a check using lastIdx that if the character does not appear again we will not pop it.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        unordered_map<char, int> lastIdx, vis;
        for(int i = 0; i < n; i++) {
            lastIdx[s[i]] = i;
            vis[s[i]] = 0; // mark each character as not visited
        }

        stack<char> st; // monotonic increasing stack [a, b, c, ...]
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(vis[ch]) continue; // already included in stack

            // keep the stack monotonic increasing
            // since we are removing chars, we need to check that they should appear later
            while(!st.empty() && st.top() > ch && lastIdx[st.top()] > i) {
                vis[st.top()] = 0;
                st.pop();
            }

            st.push(s[i]);
            vis[s[i]] = 1;
        }

        string res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
