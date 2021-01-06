/*
Euler's Totient Function Algorithm
----------------------
Euler's totient function counts the positive integers up to a 
given integer n that are relatively prime to n. It is written
as φ(n) or ϕ(n). It can be defined more formally as the number 
of integers k in the range 1 ≤ k ≤ n for which the greatest 
common divisor gcd(n, k) is equal to 1. It plays a key role in 
the definition of the RSA encryption system.
----------------------
Time Complexity : O(n^0.5)
Space Complexity : O(1)
*/

#include <iostream>

using namespace std;

int phi(int n){          
	int result = n;          
	for (int i = 2; i * i <= n; i++){            
		if (n % i == 0){
            result -= result / i;            
		}
		while (n % i == 0){
            n /= i;          
		}
	}          
	if (n > 1){
        result -= result / n;          
	}
	return result;        
} 
