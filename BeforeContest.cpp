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


// O(n*log(log(n))) 
int spf[N+5];
bool isPrime[N+5];
void SieveAndSPF() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	// marking smallest prime factor for every number to be itself.
	for (int i = 1; i < N; i++) spf[i] = i;
	
	for(int i = 2; i * i <= N; i++) { 
		if (isPrime[i]) {
			for(int j = i * i; j <= N; j += i) {
				isPrime[j] = false; 
				spf[j] = min(spf[j], i);
			}
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
/*------------------------------------------------------*/





struct Sieve {
    vector<bool> isprime;
    vector<int> spf;

    Sieve(int n) {
        isprime.resize(n+1, true);
        spf.resize(n+1);

        for(int i = 0; i <= n; i++) {
            isprime[i] = true;
            spf[i] = i;
        }
        
        isprime[0] = isprime[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if(isprime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isprime[j] = false;
                    spf[j] = min(spf[j], i);
                }
            }
        }
    }

    vector<int> getFactors(int x) {
        vector<int> v;
        while(x > 1) {
            v.push_back(spf[x]);
            x /= spf[x];
        }
        return v;
    }
};






























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
/*------------------------------------------------------*/
