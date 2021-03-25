/*
This is mainly an application of Catalan Numbers. 
Total possible valid expressions for input n is n/2’th Catalan Number if n is even and 0 if n is odd.
*/


#include <bits/stdc++.h>
using namespace std;

unsigned long int catalanDP(unsigned int n) { 
    // Table to store results of subproblems 
    unsigned long int catalan[n+1]; 

    // Initialize first two values in table 
    catalan[0] = catalan[1] = 1; 

    // Fill entries in catalan[] using recursive formula 
    for (int i=2; i<=n; i++) { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-1-j]; 
    } 

    // Return last entry 
    return catalan[n]; 
} 

// Function to find possible ways to put balanced parenthesis in an expression of length n
unsigned long int findWays(unsigned n) {
	// If n is odd, not possible to
	// create any valid parentheses
	if (n & 1)
		return 0;

	// Otherwise return n/2'th Catalan Numer
	return catalan(n / 2);
}

// Driver program to test above functions
int main()
{
	int n = 6;
	cout << "Total possible expressions of length " << n << " is " << findWays(6);
	return 0;
}
