// https://leetcode.com/problems/remove-k-digits/

/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        
        // Store the final string in stack
        for(char c: num) {
            while(!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            
            // this is done to remove leading zeros from final answer
            if(st.empty() && c == '0') continue;

            st.push(c);
        }
        
        // Now remove the largest values from the top of the stack
        while(!st.empty() && k--) {
            st.pop();
        }
        
        if(st.empty()) return "0";
        
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
