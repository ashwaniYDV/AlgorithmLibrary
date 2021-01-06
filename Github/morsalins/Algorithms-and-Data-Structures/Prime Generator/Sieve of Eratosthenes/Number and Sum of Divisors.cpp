#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 1000000
#define I64 long long

I64 binPow (I64, I64);
void Sieve ();
I64 NumberOfDivisors (int);
I64 SumOfDivisors (int);

vector <int> primes;
int composite[MAX + 5];

int main ()
{
	int n;

	Sieve ();

	while (scanf("%d", &n) == 1) {
		printf("The number of Divisors of %d = %lld\n", n, NumberOfDivisors(n));
		printf("The sum of Divisors of %d = %lld\n", n, SumOfDivisors(n));
	}
	return 0;
}

I64 binPow (I64 b, I64 p)
{
    if (p == 0) return 1;
    if (p % 2 != 0) return binPow(b, p-1) * b;
    else {
        I64 t = binPow(b, p/2);
        return t * t;
    }
}

void Sieve ()
{
	int limit = sqrt(MAX) + 2;
	composite[1] = true;

	for (int i = 3; i <= limit; i += 2) {
		if (!composite[i]) {
			for (int j = i * i, k = i << 1; j <= MAX; j += k) {
				composite[j] = true;
			}
		}
	}

	primes.push_back(2);
	for (int i = 3; i <= MAX; i += 2) {
		if (!composite[i]) {
			primes.push_back(i);
		}
	}
	return;
}

I64 NumberOfDivisors (int n)
{
	I64 num = 1;

	for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
		int cnt = 0;
		if (n % primes[i] == 0) {
			while (n % primes[i] == 0) {
				n /= primes[i];
				cnt++;
			}
			num *= (cnt + 1);
		}
	}
	if (n > 1) {
		num *= 2;
	}
	return num;
}

I64 SumOfDivisors (int n)
{
	I64 sum = 1;

	for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
		int cnt = 0;
		if (n % primes[i] == 0) {
			while (n % primes[i] == 0) {
				n /= primes[i];
				cnt++;
			}
			sum *= (binPow(primes[i], cnt + 1) - 1) / (primes[i] - 1);
		}
	}
	if (n > 1) {
		sum *= (binPow(n, 2) - 1) / (n - 1);
	}
	return sum;
}