// https://www.geeksforgeeks.org/decode-string-recursively-encoded-count-followed-substring/
// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1


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


// Using 1 stack
class Solution {
public:
    string decodedString(string s) {
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




// Using 2 stacks
class Solution {
public:
    string decodedString(string s) {
        stack<int> numStack;
        stack<char> charStack;
        string res = "";
    
        // Traversing the string
        for (int i = 0; i < s.length(); i++) {
    
            // If number, convert it into number and push it into numStack.
            if (s[i] >= '0' && s[i] <='9') {
                int cnt = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + (s[i] - '0');
                    i++;
                }
                i--;
    
                numStack.push(cnt);
            }
    
            // If closing bracket ']', pop element until
            // '[' opening bracket is not found in the character stack.
            else if (s[i] == ']') {
                string temp = "";
                int cnt = 0;
    
                if (!numStack.empty()) {
                    cnt = numStack.top();
                    numStack.pop();
                }
    
                while (!charStack.empty() && charStack.top() != '[' ) {
                    temp = charStack.top() + temp;
                    charStack.pop();
                }
    
                if (!charStack.empty() && charStack.top() == '[')
                    charStack.pop();
    
                // Repeating the popped string 'temp' cnt number of times.
                for (int j = 0; j < cnt; j++) {
                    res = res + temp;
                }
    
                // Push it in the character stack.
                for (int j = 0; j < res.length(); j++)
                    charStack.push(res[j]);
    
                res = "";
            }
    
            // If '[' opening bracket, push it into character stack.
            else if (s[i] == '[') {
                if (s[i - 1] >= '0' && s[i - 1] <= '9') {
                    charStack.push(s[i]);
                } else {
                    numStack.push(1);
                    charStack.push(s[i]);
                }
            } else {
                charStack.push(s[i]);
            }
        }
    
        // Pop all the element, make a string and return.
        while (!charStack.empty()) {
            res = charStack.top() + res;
            charStack.pop();
        }
    
        return res;
    }
};
