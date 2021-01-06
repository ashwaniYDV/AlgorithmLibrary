/*
Sieve of Eratosthenes
---------------------
Finds all prime numbers upto n (inclusive) using the simple
Sieve of Eratosthenes method, which efficiently finds primes in the order of
10^7. (The efficiency limit is due to poor cache utilisation.)
---------------------
Time Complexity : O(n*log(log(n)))
Space complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieve(const size_t &limit){
	vector<bool> primes(limit + 1, true);
	primes[0] = primes[1] = false;
	size_t multiple;
	for (size_t num = 2; num <= sqrt(limit); num++){
		if (primes[num]){
			for (multiple = num * num; multiple <= limit; multiple += num){
				primes[multiple] = false;
			}
		}
	}
	return primes;
}