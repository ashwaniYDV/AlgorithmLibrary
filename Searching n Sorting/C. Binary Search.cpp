https://codeforces.com/contest/1436/problem/C


const int MAXN = 1e3+5;
const int N = 1e3+5;
int n, m;

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

int nPrMod(int n, int r, int mod) {
	if (n < r) return 0;
	if (r == 0) return 1;
	int num = fact[n], den = (fact[n-r]) % mod;
	int inv = modInverse(den, mod);
	return (num * inv) % mod;
}

void solve() {
	int x, y, z, pos;
	cin >> n >> x >> pos;
	initFactorials(MOD);
	int cntGreater = 0, cntLesser = 0, l = 0, r = n;
	
	while(l < r) {
		int m = (l+r)/2;

		if(m < pos) {
			cntLesser++;
			l = m + 1;
		} else if(m > pos) {
			cntGreater++;
			r = m;
		} else if(m == pos) {
			l = m + 1;
		}
	}

	int res = (nPrMod(x - 1, cntLesser, MOD) * nPrMod(n - x, cntGreater, MOD)) % MOD;
	res = (res * fact[n - cntGreater - cntLesser - 1]) % MOD;
	cout << res << endl;
}
