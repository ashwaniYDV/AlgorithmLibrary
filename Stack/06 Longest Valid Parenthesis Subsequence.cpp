// https://www.geeksforgeeks.org/length-longest-balanced-subsequence/

#include <bits/stdc++.h>
using namespace std;

int maxLength(char s[], int n) {
	int invalidOpenBraces = 0;

	// To count all the close brace that does not have the corresponding open brace.
	int invalidCloseBraces = 0;

	// Iterating over the String
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			// Number of open braces that hasn't been closed yet.
			invalidOpenBraces++;
		} else {
			if (invalidOpenBraces == 0) {
				// Number of close braces that cannot be mapped to any open brace.
				invalidCloseBraces++;
			} else {
				// Mapping the ith close brace to one of the open brace.
				invalidOpenBraces--;
			}
		}
	}
	return (n - (invalidOpenBraces + invalidCloseBraces));
}

int main() {
	char s[] = "()(((((()";
	int n = strlen(s);
	cout << maxLength(s, n) << endl;
	return 0;
}
