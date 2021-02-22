/*------------------------------------------------------*/

/*
__builtin_popcount(num)

// 1 if no of 1's is odd else 0
__builtin_parity(num)

// Number of leading zero's
__builtin_clz(num)

// It only works for unsigned values 
// Number of leading zero's
__builtin_clz(-num)

// Number of trailing zero's
__builtin_ctz(num)

*/

bool prime[N+5]; 
vector<int> primesVec;
void SieveOfEratosthenes(ll n) {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(ll p=2; p*p<=n; p++){ 
		if (prime[p] == true){
			for(ll i=p*p;i<=n;i+=p) 
			prime[i] = false; 
		} 
	} 
	for(ll p=2; p<=n; p++){
		if (prime[p]) {
			primesVec.push_back(p);
		}
	}
}

ll spf[N];
void SPF() { 
	spf[1] = 1; 
	// marking smallest prime factor for every number to be itself.
	for (ll i = 2; i < N; i++) spf[i] = i; 
  
	// separately marking spf for every even number as 2 
	for (ll i=4; i<N; i+=2) spf[i] = 2;
  
	for (ll i=3; i*i<N; i++) { 
		// checking if i is prime 
		if (spf[i] == i) { 
			// marking SPF for all numbers divisible by i 
			for (ll j=i*i; j<N; j+=i) 
				// marking spf[j] if it is not  
				// previously marked 
				if (spf[j]==j) spf[j] = i; 
		} 
	} 
}
vector<int> getFactorization(int x) { 
    vector<int> ret; 
    while (x != 1) { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

int binpow(int n, int p) {
	int res = 1;
	while (p > 0) {
		if (p & 1) res = res * n;
		n = n * n;
		p >>= 1;
	}
	return res;
}
int power(int n, int p, int mod) {
	int res = 1;
	n %= mod;
	while (p > 0) {
		if (p & 1) res = (res * n) % mod;
		n = (n * n) % mod;
		p >>= 1;
	}
	return res;
}
int modInverse(int n, int mod) { 
	return power(n, mod - 2, mod);
} 
 
int fact[MAXN] = {0};
void initFactorials(int mod) {
	fact[0] = fact[1] = 1;
	  for (int i = 2; i < MAXN; i++) {
		fact[i] = (fact[i - 1] * i * 1LL) % mod;
	}
}
 
int nCrMod(int n, int r, int mod) {
	if (n < r) return 0;
	if (r == 0) return 1;
	int num = fact[n], den = (fact[r] * fact[n-r]) % mod;
	int inv = modInverse(den, mod);
	return (num * inv) % mod;
}

int nPrMod(int n, int r, int mod) {
	if (n < r) return 0;
	if (r == 0) return 1;
	int num = fact[n], den = (fact[n-r]) % mod;
	int inv = modInverse(den, mod);
	return (num * inv) % mod;
}
/*------------------------------------------------------*/
