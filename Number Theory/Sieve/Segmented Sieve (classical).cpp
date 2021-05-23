// https://www.spoj.com/problems/PRIME1/
// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#toc-tgt-7


// Method 1
const int N = 1e5+5;
int n, m;

bool prime[N+5]; // N = 1e5 order 
vector<int> primes;
void sieve() {
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
            primes.push_back(p);
        }
    }
}

void segmentedSieve(int L, int R) {
    if(L < 2) L = 2;
 
    int n = R - L + 1;
    vector<int> isPrime(n , 0);
 
    for(int p : primes) {
        if(p*p <= R) {
            int i = (L / p) * p;
            if(i < L) 
                i += p;
     
            for(; i <= R; i += p) {
                if(i != p)
                    isPrime[i - L] = 1;
            }
        }
    }
 
    for(int i = 0; i < n; i++)
        if(isPrime[i] == 0)
            cout << i + L << endl;
}

void solve() {
    int x, y, z, l, r;
    cin >> l >> r;
    segmentedSieve(l, r);
    cout << endl;
}
 
signed main() {
    IOS
    sieve();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}































// Method 2
const int N = 1e5+5;
int n, m;

bool prime[N+5]; // N = 1e5 order 
vector<int> primes;
void sieve() {
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
            primes.push_back(p);
        }
    }
}


// Time = (R-L+1)loglog(R) + √R.loglog(√R)
vector<bool> segmentedSieve(int L, int R) {
    // generate all primes up to sqrt(R)
    int lim = sqrt(R);
    vector<bool> isPrime(R - L + 1, true);

    for (int i : primes) {
        // if( i*i <= R) {
        if( i <= lim) {
            for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
                isPrime[j - L] = false;
            }
        }
    }

    if (L == 1)
        isPrime[0] = false;

    return isPrime;
}

void solve() {
    int x, y, z, l, r;
    cin >> l >> r;
    vector<bool> isPrime = segmentedSieve(l, r);
    f(i, isPrime.size()) {
        if(isPrime[i])
            cout << i + l << endl;
    }
    cout << endl;
}
 
signed main() {
    IOS
    sieve();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
} 































// Method 3
int n, m;

// Time = (R-L+1)loglog(R) + √R.loglog(√R)
vector<bool> segmentedSieve(int L, int R) {
    // generate all primes up to sqrt(R)
    int lim = sqrt(R);
    vector<bool> mark(lim + 1, true);
    mark[0] = mark[1] = false;
    vector<int> primes;
    for (int i = 2; i <= lim; ++i) {
        if (mark[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= lim; j += i)
                mark[j] = false;
        }
    }

    vector<bool> isPrime(R - L + 1, true);

    for (int i : primes)
        for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;

    if (L == 1)
        isPrime[0] = false;

    return isPrime;
}

void solve() {
    int x, y, z, l, r;
    cin >> l >> r;
    vector<bool> isPrime = segmentedSieve(l, r);
    f(i, isPrime.size()) {
        if(isPrime[i])
            cout << i + l << endl;
    }
    cout << endl;
}
 
signed main() {
    IOS
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
} 
































// Method 4
int n, m;

// Time = (R-L+1)loglog(R) + √R.loglog(√R)
vector<bool> segmentedSieve(int L, int R) {
    // generate all primes up to sqrt(R)
    int lim = sqrt(R);
    vector<bool> mark(lim + 1, true);
    mark[0] = mark[1] = false;
    vector<int> primes;
    for (int i = 2; i*i <= lim; ++i) {
        if (mark[i]) {
            for (int j = i * i; j <= lim; j += i)
                mark[j] = false;
        }
    }
    for (int i = 2; i <= lim; ++i) {
        if(mark[i])
            primes.emplace_back(i);
    }

    vector<bool> isPrime(R - L + 1, true);

    for (int i : primes)
        for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;

    if (L == 1)
        isPrime[0] = false;

    return isPrime;
}
void solve() {
    int x, y, z, l, r;
    cin >> l >> r;
    vector<bool> isPrime = segmentedSieve(l, r);
    f(i, isPrime.size()) {
        if(isPrime[i])
            cout << i + l << endl;
    }
    cout << endl;
}
 
signed main() {
    IOS
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
