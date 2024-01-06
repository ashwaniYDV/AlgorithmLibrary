// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// https://leetcode.com/problems/remove-duplicate-letters/

/*
Given a string s, return lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

Input: s = "bcabc"
Output: "abc"

Input: s = "cbacdcbc"
Output: "acdb"
*/


/*
Intuition
=========
* Only put those characters in stack which form valid string.

Approach
========
1) Push in stack:
* only those characters are pushed which are not already there in the stack using visited map.
2) Pop from Stack:
* stack is not empty and current character in string s is smaller than the top stack character, as we  want to keep the smallest character at first
* While popping we need to keep a check if the character does not appear again we will not pop it, using lastIdx.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        map<char, int> lastIdx, vis;
        for(int i = 0; i < n; i++) {
            lastIdx[s[i]] = i;
            vis[s[i]] = 0;
        }

        stack<char> st;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(vis[ch]) continue;

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
