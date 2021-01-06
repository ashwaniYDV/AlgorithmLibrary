/*
Karatsuba Multiplication Algorithm
----------------------------------
The Karatsuba algorithm is a fast multiplication algorithm. It reduces the multiplication 
of two n-digit numbers to at most single-digit multiplications in general. It is 
therefore faster than the classical algorithm. The Karatsuba algorithm was the first 
multiplication algorithm asymptotically faster than the quadratic "grade school" algorithm.
----------------------------------
Time Complexity : O(n^1.59)
*/

#include <iostream>
#include <cmath>

using namespace std;

int equalize(string &num1, string &num2){
	int len1 = num1.length();
	int len2 = num2.length();
	if (len1 < len2){
		for (int i = 0; i < len2 - len1; i++){
			num1 = '0' + num1;
		}
		return len2;
	} else{
		for (int i = 0; i < len1 - len2; i++){
			num2 = '0' + num2;
		}
		return len1;
	}
}

string add(string num1, string num2){
	string result = "";
	int length = equalize(num1, num2);
	int carryover = 0;
	for (int i = length - 1; i >= 0; i--){
		int a = num1[i] - '0';
		int b = num2[i] - '0';
		int sum = a + b + carryover;
		carryover = sum / 10;
		sum = sum % 10;
		result = to_string(sum) + result;
	}
	if (carryover){
		result = to_string(carryover) + result;
	}
	return result;
}

long karatsuba(string num1, string num2){
	int n = equalize(num1, num2);
	if (n == 0){
		return 0;
	} else if (n == 1){
		return (num1[0] - '0') * (num2[0] - '0');
	} else{
		int primary = n / 2;
		int secondary = n - primary;
		string A = num1.substr(0, primary);
		string B = num1.substr(primary, secondary);
		string C = num2.substr(0, primary);
		string D = num2.substr(primary, secondary);
		long AC = karatsuba(A, C);
		long BD = karatsuba(B, D);
		long ABCD = karatsuba(add(A, B), add(C, D));
		return ((AC * pow(10, 2 * primary)) + ((ABCD - AC - BD) * pow(10, primary)) + (BD));
	}
}