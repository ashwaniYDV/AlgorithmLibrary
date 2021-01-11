/*
Find nth catalan number?

Applications
1) Count the number of possible BSTs with n keys
2) Count the number of FBTs with (n + 1) leaves
*/

#include<iostream> 
using namespace std; 

// RECURSIVE:-
unsigned long int catalanRecur(unsigned int n) 
{ 
    // Base case 
    if (n <= 1) return 1; 

    // catalan(n) is sum of catalan(i)*catalan(n-1-i) 
    unsigned long int res = 0; 
    for (int i=0; i<n; i++) 
        res += catalanRecur(i)*catalanRecur(n-1-i); 

    return res; 
} 


// DYNAMIC PROGRAMMING:-
unsigned long int catalanDP(unsigned int n) 
{ 
    // Table to store results of subproblems 
    unsigned long int catalan[n+1]; 

    // Initialize first two values in table 
    catalan[0] = catalan[1] = 1; 

    // Fill entries in catalan[] using recursive formula 
    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-1-j]; 
    } 

    // Return last entry 
    return catalan[n]; 
} 


// Returns value of Binomial Coefficient C(n, k) 
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
    unsigned long int res = 1; 

    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 

    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 

    return res; 
} 

// A Binomial coefficient based function to find nth catalan number in O(n) time 
unsigned long int catalanBinCof(unsigned int n) 
{ 
    // Calculate value of 2nCn 
    unsigned long int c = binomialCoeff(2*n, n); 

    // return 2nCn/(n+1) 
    return c/(n+1); 
} 

int main() 
{ 
    for (int i = 0; i < 10; i++) {
        cout << catalanBinCof(i) << " "; 
    }
    return 0; 
} 
