// https://leetcode.com/problems/basic-calculator-ii/
// https://youtu.be/b_vCkD-rhiU?si=J6RwcSo12XjqQ-oa
// https://youtu.be/-x1mBBPxQh4?si=8AOlRSnnN3lzt3lA
/*
Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. 
All intermediate results will be in the range of [-231, 231 - 1].

Input: s = "3+2*2"
Output: 7

Input: s = " 3/2 "
Output: 1

Input: s = " 3+5 / 2 "
Output: 5
 
Constraints:
1 <= s.length <= 3 * 10^5
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 2^31 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/



class Solution {
public:
    int calculate(string& s) {
        stack<int> st;
        char sign = '+';
        int num = 0;

        // Helper function to update stack based on operator
        auto update = [&](char op, int v) {
            if (op == '+') {
                st.push(v);
            }
            if (op == '-') {
                st.push(-v);
            }
            if (op == '*') {
                int stTop = st.top();
                st.pop();
                st.push(stTop * v);
            }
            if (op == '/') {
                int stTop = st.top();
                st.pop();
                st.push(stTop / v);
            }
        };

        for (int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') continue;

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } 
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                update(sign, num);
                num = 0;
                sign = s[i];
            } 
        }

        // Final update with the last number
        update(sign, num);

        // Sum up the values in the stack
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};






// https://leetcode.com/problems/basic-calculator-iii/
// https://youtu.be/-x1mBBPxQh4?si=8AOlRSnnN3lzt3lA
/*
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. 
All intermediate results will be in the range of [-231, 231 - 1].

Input: s = "1+1"
Output: 2

Input: s = "6-4/2"
Output: 4

Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21
 
Constraints:
1 <= s <= 10^4
s consists of digits, '+', '-', '*', '/', '(', and ')'.
s is a valid expression.
*/

class Solution {
public:
    int accumulateSt(stack<int>& st) {
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
    
    int fun(int& i, string s) {
        stack<int> st;
        char sign = '+';
        int num = 0;

        // Helper function to update stack based on operator
        auto update = [&](char op, int v) {
            if (op == '+') {
                st.push(v);
            }
            if (op == '-') {
                st.push(-v);
            }
            if (op == '*') {
                int stTop = st.top();
                st.pop();
                st.push(stTop * v);
            }
            if (op == '/') {
                int stTop = st.top();
                st.pop();
                st.push(stTop / v);
            }
        };

        for (; i < s.size(); i++) {
            if(s[i] == ' ') continue;

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } 
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                update(sign, num);
                num = 0;
                sign = s[i];
            } 
            // Handle parentheses
            else if (s[i] == '(') {
                i++;

                // Recursively calculate within parentheses
                num = fun(i, s);
            } 
            // Handle closing parentheses
            else if (s[i] == ')') {
                update(sign, num);
                return accumulateSt(st);
            }
        }

        // Final update with the last number
        update(sign, num);

        // Sum up the values in the stack
        return accumulateSt(st);
    }

    int calculate(string& s) {
        int i = 0;
        return fun(i, s);
    }
};