// My Amazon Bar Raiser Round DSA question

/*
Q1. Given an algebraic string of '+', '-', operands and parentheses, 
you have to simplify the expression and output the simplified string without parentheses. 

Ex: a-(b+c) 
Ans: a-b-c

Ex: a+(b-(c+d)) 
Ans: a + b - c - d
*/



// https://medium.com/@sanjaysoni_48818/simplifying-algebric-expression-problem-dsa-914d1ca25755


#include <bits/stdc++.h>
using namespace std;

string simplifyExpression(string exp) {
    stack<char> st;

    for (char ch : exp) {
        if (ch != ')') {
            st.push(ch);
            continue;
        }

        string temp;
        while (st.top() != '(') {
            temp = st.top() + temp;
            st.pop();
        }

        st.pop(); // pop the '('

        if (st.top() == '-') {
            st.pop(); // pop the '-'
            
            // since it does not have a '+' or '-' in begining, so adding a '+'
            if(isalpha(temp[0])) {
                temp = '+' + temp;
            }
            
            for (char t : temp) {
                if (t == '+') {
                    st.push('-');
                } else if (t == '-') {
                    st.push('+');
                } else {
                    st.push(t);
                }
            }
        } else {
            for (char t : temp) {
                st.push(t);
            }
        }
    }

    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}

int main() {
    string expr1 = "a-(b+c)";
    string expr2 = "a-((-b+c))";
    string expr3 = "a+(b-(c+d))";
    string expr4 = "x-(y-z+(a-b))";

    cout << simplifyExpression(expr1) << endl; // a-b-c
    cout << simplifyExpression(expr2) << endl; // a+b-c
    cout << simplifyExpression(expr3) << endl; // a+b-c-d
    cout << simplifyExpression(expr4) << endl; // x-y+z-a+b
}







#include <bits/stdc++.h>
using namespace std;

string simplifyExpression(string expression) {
    stack<bool> signStack;
    signStack.push(true); // true means '+', false means '-'
    string result;
    bool sign = true; // true for '+', false for '-'

    for (int i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        if (ch == '+') {
            sign = true;
        } else if (ch == '-') {
            sign = false;
        } else if (ch == '(') {
            bool top = signStack.top();
            signStack.push(sign ? top : !top);
            sign = true; // reset
        } else if (ch == ')') {
            signStack.pop();
        } else if (isalpha(ch)) {
            bool currentSign = signStack.top();
            bool effectiveSign = sign ? currentSign : !currentSign;
            if (!result.empty()) {
                result += (effectiveSign ? '+' : '-');
            } else if (!effectiveSign) {
                result += '-';
            }
            result += ch;
            sign = true; // reset
        }
    }

    return result;
}

int main() {
    string expr1 = "a-(b+c)";
    string expr2 = "a-((-b+c))";
    string expr3 = "a+(b-(c+d))";
    string expr4 = "x-(y-z+(a-b))";

    cout << simplifyExpression(expr1) << endl; // a-b-c
    cout << simplifyExpression(expr2) << endl; // a+b-c
    cout << simplifyExpression(expr3) << endl; // a+b-c-d
    cout << simplifyExpression(expr4) << endl; // x-y+z-a+b
}
