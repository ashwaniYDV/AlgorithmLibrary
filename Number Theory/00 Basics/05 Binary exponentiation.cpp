// https://youtu.be/lsdwBlk9YGI?si=JWr3NWXnVZw5kj75

// n ^ p
int binpow(int n, int p) {
	int res = 1;
	while (p > 0) {
		if (p & 1) res = res * n;
		n = n * n;
		p >>= 1;
	}
	return res;
}


// (n ^ p) % mod
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