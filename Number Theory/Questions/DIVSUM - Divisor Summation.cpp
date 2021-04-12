// https://www.spoj.com/problems/DIVSUM/

const int N = 5e5+5;
int n, m;

int binpow(int n, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) res = res * n;
        n = n * n;
        p >>= 1;
    }
    return res;
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

void solve() {
	int x, y, z;
	cin >> n;
	m = n;
	unordered_map<int, int> mp;

	while(m != 1) {
		x = spf[m];
		mp[x]++;
		m /= x;
	}

	int res = 1;
	for(auto it: mp) {
		x = it.F, y = it.S;
		res *= (binpow(x, y+1) - 1) / (x - 1);
	}

	res -= n;
	cout << res << endl;
}

signed main() {
	IOS
	SieveAndSPF();
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
}
