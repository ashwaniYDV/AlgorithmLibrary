/*
Euclid's GCD Algorithm
----------------------
Basic Euclidean Algorithm is used to find GCD of two numbers say a and b. 
The Euclidean algorithm is based on the principle that the greatest common divisor
of two numbers does not change if the larger number is replaced by its difference with
the smaller number.
----------------------
Time Complexity : O(log(min(A, B)))
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

int gcd(int a, int b){
	if (b == 0){
		return a;
	} else{
		return gcd(b, a % b);
	}
}
