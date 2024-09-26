// https://www.naukri.com/code360/library/lexicographically-smallest-k-length-subsequence-from-a-given-string

/*
You have been provided with a string S, of length N, and an integer K. 
Your task is to determine the lexicographically smallest subsequence of length K from this string S. 
Also, it has been stated that K < N.

S = SIRNCZJHWF
K = 5
The lexicographically smallest subsequence of length 5 is CJHWF.
*/


/*
Algorithm
---------
* In this approach, we will use a stack data structure to keep track of the characters in increasing order. At any string index, this stack will contain the smallest K-length subsequence up to that index.
* As you traverse the string, push the current character into the stack if it is empty.
* If not, iterate the string till the current element of the string, S[i], becomes smaller than the topmost element of the stack. Also, since the maximum size of the stack is K, you need to continuously pop off elements from the stack as well. 
* If the stack size after the previous step is less than K, then push the current character into the stack.
* After this, the characters stored in the stack are printed in reverse order to obtain the required K-length subsequence. 
*/


#include <bits/stdc++.h>
using namespace std;

string lexicographicallySmallestSubsequence(string &s, int k) {
    int n = (int)s.size();
 
    // Initialising a variable to store the lexicographically smallest substring.
    stack<char> ans;
 
    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // Iterating till the current character is less than the character at the top of the stack and 
        // checking if at least K characters remain in stack + rest of the string.
        while (!ans.empty() && ans.top() > ch && (ans.size() - 1 + n - i >= k)) {
            ans.pop();
        }

        // If the size of the stack is less than k, the character is pushed into it.
        if (ans.size() < k) {
            ans.push(s[i]);
        }
    }
 
    string result;
    while (!ans.empty()) {
        result.push_back(ans.top());
        ans.pop();
    }
 
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s = "SIRNCZJHWF";
    cout << lexicographicallySmallestSubsequence(s, 5);
}