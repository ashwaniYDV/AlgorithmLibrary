// https://youtu.be/4pIc9UBHJtk?si=yd7PpWe4EGUawY44
// https://takeuforward.org/data-structure/infix-to-postfix/

/*
Convert the given infix expression to a postfix expression.

Input: a+b*(c^d-e)^(f+g*h)-i
Output: abcd^e-fgh*+^*+i-

Input: (p+q)*(m-n)
Output: pq+mn-*
*/

/*
Approach: To convert Infix expression to Postfix
---------
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, Print it. 
3. Else, 
    If the precedence of the scanned operator is greater than the precedence of the operator in the stack or the stack is empty or the stack contains a ‘(‘, push the character into the stack. 
    Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. 
4. If the scanned character is an ‘(‘, push it into the stack. 
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-5 until the entire infix expression is scanned. 
7. Print the output.
8. Pop and print the output from the stack until it is not empty.
*/


#include<bits/stdc++.h>
using namespace std;

//Function to return precedence of operators
int precedence(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s) {

  stack < char > st; //For stack operations, we are using C++ built in stack
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    // If the scanned character is
    // an operand, add it to output string.
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    // If the scanned character is an
    // ‘(‘, push it to the stack.
    else if (c == '(')
      st.push('(');

    // If the scanned character is an ‘)’,
    // pop and to output string from the stack
    // until an ‘(‘ is encountered.
    else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    //If an operator is scanned
    else {
      while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  cout << "Postfix expression: " << result << endl;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
  return 0;
}
