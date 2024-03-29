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

// O(n*log(log(n))) 
bool prime[N+5]; 
vector<int> primesVec;
void SieveOfEratosthenes(int N) {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int p = 2; p*p <= N; p++) { 
		if (prime[p] == true) {
			for(int i = p*p; i <= N; i+=p) 
			prime[i] = false; 
		} 
	} 
	for(int p=2; p <= N; p++) {
		if (prime[p]) {
			primesVec.push_back(p);
		}
	}
}

// O(n*log(log(n))) 
ll spf[N];
void SPF() { 
	// marking smallest prime factor for every number to be itself.
	for (ll i = 1; i < N; i++) spf[i] = i; 
  
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
// O(log(n)) 
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

int spf[N+5];
bool prime[N+5];
void SieveAndSPF() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;

	// marking smallest prime factor for every number to be itself.
	for (int i = 1; i < N; i++) spf[i] = i;
	
	for(int p=2; p*p<=N; p++) { 
		if (prime[p] == true) {
			for(int i=p*p;i<=N;i+=p) {
				prime[i] = false; 
				spf[i] = min(spf[i], p);
			}
		} 
	}
}
/*------------------------------------------------------*/

































/*********************************************************/
template <class A>
ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	for(int i = 0; i < v.size(); i++) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}
/*********************************************************/
 
/*------------------------------------------------------*/
int binpow(int n, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) res = res * n;
        n = n * n;
        p >>= 1;
    }
    return res;
}
int power(int n, int p) {
    int res = 1;
    n %= MOD;
    while (p > 0) {
        if (p & 1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        p >>= 1;
    }
    return res;
}
int modInverse(int n, int p) { 
    return power(n, p - 2);
} 
 
int fact[MAXN], inv[MAXN], invfact[MAXN];
void initFactorials() {
    fact[0] = 1;
      for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i * 1LL) % MOD;
    }

    //calculate inverses of [1,N] mod p
	inv[1]=1;
	for(int i=2;i<MAXN;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
 
	invfact[0]=1;
	for(int i=1;i<MAXN;i++)invfact[i]=(invfact[i-1]*inv[i])%MOD;
}
 
int nCrMod(int n, int r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    int num = fact[n], den = (fact[r] * fact[n-r]) % MOD;
    int inv = modInverse(den, MOD);
    return (num * inv) % MOD;
}

// bool prime[N+5]; 
// vector<int> primesVec;
// void SieveOfEratosthenes(int N) {
// 	memset(prime, true, sizeof(prime));
// 	prime[0] = prime[1] = false;
// 	for(int p = 2; p*p <= N; p++) { 
// 		if (prime[p] == true) {
// 			for(int i = p*p; i <= N; i+=p) 
// 			prime[i] = false; 
// 		} 
// 	} 
// 	for(int p=2; p <= N; p++) {
// 		if (prime[p]) {
// 			primesVec.push_back(p);
// 		}
// 	}
// }

// int spf[N+5];
// bool prime[N+5];
// void SieveAndSPF() {
// 	memset(prime, true, sizeof(prime));
// 	prime[0] = prime[1] = false;

// 	// marking smallest prime factor for every number to be itself.
// 	for (int i = 1; i < N; i++) spf[i] = i;
	
// 	for(int p=2; p*p<=N; p++) { 
// 		if (prime[p] == true) {
// 			for(int i=p*p;i<=N;i+=p) {
// 				prime[i] = false; 
// 				spf[i] = min(spf[i], p);
// 			}
// 		} 
// 	}
// }
/*------------------------------------------------------*/
