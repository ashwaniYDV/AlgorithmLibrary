// https://youtu.be/4pIc9UBHJtk?si=yd7PpWe4EGUawY44
// https://takeuforward.org/data-structure/infix-to-postfix/

/*
Convert the given infix expression to a prefix expression.

Input: x+y*z/w+u
Output: ++x/*yzwu

Input: a+b
Output: +ab
*/

/*
Approach: To convert Infix expression to Prefix
---------
First, reverse the infix expression given in the problem.
Scan the expression from left to right.
Whenever the operands arrive, print them.
If the operator arrives and the stack is found to be empty, then simply push the operator into the stack.
If the incoming operator has higher precedence than the TOP of the stack, push the incoming operator into the stack.
If the incoming operator has the same precedence with a TOP of the stack, push the incoming operator into the stack.
If the incoming operator has lower precedence than the TOP of the stack, pop, and print the top of the stack. Test the incoming operator against the top of the stack again and pop the operator from the stack till it finds the operator of lower precedence or same precedence.
If the incoming operator has the same precedence with the top of the stack and the incoming operator is ^, then pop the top of the stack till the condition is true. If the condition is not true, push the ^ operator.
When we reach the end of the expression, pop, and print all the operators from the top of the stack.
If the operator is ')', then push it into the stack.
If the operator is '(', then pop all the operators from the stack till it finds the ‘)’ bracket in the stack.
If the top of the stack is ')', push the operator on the stack.
In the end, reverse the output. And print it.
*/

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
  return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) {
  if (C == '^') return 3;
  if (C == '*' || C == '/') return 2;
  if (C == '-' || C == '+') return 1;
  return 0;
}

string infixToPostfix(string infix) {
  infix = '(' + infix + ')';
  int l = (int) infix.size();

  stack < char > char_stack;
  string output;

  for (int i = 0; i < l; i++) {

    // If the scanned character is an operand, add it to output.
    if (isalpha(infix[i]) || isdigit(infix[i]))
      output += infix[i];

    // If the scanned character is ‘(‘, push it to the stack.
    else if (infix[i] == '(')
      char_stack.push('(');

    // If the scanned character is ‘)’, pop and output from the stack until a ‘(‘ is encountered.
    else if (infix[i] == ')') {
      while (char_stack.top() != '(') {
        output += char_stack.top();
        char_stack.pop();
      }

      // Remove '(' from the stack
      char_stack.pop();
    }

    // Operator found
    else if (isOperator(char_stack.top())) {
      if (infix[i] == '^') {
        while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
          output += char_stack.top();
          char_stack.pop();
        }
      } else {
        while (getPriority(infix[i]) < getPriority(char_stack.top())) {
          output += char_stack.top();
          char_stack.pop();
        }
      }

      // Push current Operator on stack
      char_stack.push(infix[i]);
    }
  }

  while (!char_stack.empty()) {
    output += char_stack.top();
    char_stack.pop();
  }

  return output;
}

/* 
Steps:
-----
Reverse String
Replace ( with ) and vice versa
Get Postfix
Reverse Postfix
*/
string infixToPrefix(string infix) {
  int l = (int) infix.size();

  // Reverse infix
  reverse(infix.begin(), infix.end());

  // Replace ( with ) and vice versa
  for (int i = 0; i < l; i++) {
    if (infix[i] == '(') {
      infix[i] = ')';
      i++;
    } else if (infix[i] == ')') {
      infix[i] = '(';
      i++;
    }
  }

  string prefix = infixToPostfix(infix);

  // Reverse postfix
  reverse(prefix.begin(), prefix.end());

  return prefix;
}

int main() {
  string s = ("(p+q)*(c-d)");
  cout << "Infix expression: " << s << endl;
  cout << "Prefix Expression: " << infixToPrefix(s) << endl;
}