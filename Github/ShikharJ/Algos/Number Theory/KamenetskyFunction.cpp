/*
Kamenetsky's Function Algorithm
----------------------
Kamenetsky's function is a common number theory function
for finding the number of digits in the factorial of any number.
----------------------
Time Complexity : O(1)
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

int kamenetsky(int n){
	int result;
	double pi = 3.141592653589793;
	double e = 2.7182818284590452353;
	if (n < 4){
		return 1;
	}
	result = (int)ceil(log10(2 * pi * n) / 2 + n * log10(n / e));
	return result;
}