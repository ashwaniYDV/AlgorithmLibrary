// https://leetcode.com/problems/decode-string/


/*
Decode a string recursively encoded as count followed by substring.
Input : "1[b]"
Output : b

Input : "2[ab]"
Output : abab

Input : "2[a2[b]]"
Output : abbabb

Input : "3[b2[ca]]"
Output : bcacabcacabcaca

Input : 2[z2[ks]m2[nk]]
Output : zksksmnknkzksksmnknk
*/


class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            // When ']' is encountered, we need to start decoding
            if (s[i] == ']') {
                string temp;
                while (!st.empty() && st.top() != '[') {
                    temp = st.top() + temp;
                    st.pop();
                }
                
                // remove the '[' from the stack
                st.pop();

                string num;
                // remove the digits from the stack
                while (!st.empty() && isdigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }
                int number = stoi(num);

                string repeat;
                for (int j = 0; j < number; j++) {
                    repeat += temp;
                }

                for (char c : repeat) {
                    st.push(c);
                }
            }
            // if s[i] is not ']', simply push s[i] to the stack
            else {
                st.push(s[i]);
            }
        }
        
        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};