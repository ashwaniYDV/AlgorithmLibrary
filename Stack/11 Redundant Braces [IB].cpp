// https://www.interviewbit.com/problems/redundant-braces/

/*
Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
Chech whether A has redundant braces or not.
Return 1 if A has redundant braces, else return 0.
Note: A will be always a valid expression.

Input 1:
    A = "((a + b))"
Output 1:
    1
    Explanation 1: ((a + b)) has redundant braces so answer will be 1.

Input 2:
    A = "(a + (a + b))"
Output 2:
    0
    Explanation 2: (a + (a + b)) doesn't have have any redundant braces so answer will be 0.
*/

int Solution::braces(string A) {
    stack<char> st;
    for(char c: A) {
        if (c == '(' || c == '+' || c == '*' || c == '-' || c == '/') {
            st.push(c);
        } else if (c == ')') {
            if (st.top() == '(') return 1;
            else {
                while (!st.empty() && st.top() != '(') {
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return 0;
}
