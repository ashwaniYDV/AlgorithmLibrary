// https://www.codechef.com/problems/COWA19C
// https://unacademy.com/class/sieve-of-eratosthenes/GVMRBBT5

/*
Let array = [a1, a2, a3]
We want sum of product of all numbers
i.e Res = (a1) + (a2) + (a3) + (a1*a2) + (a1*a3) + (a2*a3) + (a1*a2*a3)
        = (1 + a1) * (1 + a2) * (1 + a3)

A beautiful concept
Res = (1 + a1) * (1 + a2) * (1 + a3)

(1 + ax) means we have included 2 cases: 
Case 1 - we take ax in multiplication 
Case 2: we dont take ax in multiplication

TLE approach is also given at last.
*/

/*
Thus if divisors of n = [d1, d2, d3, ...]
them 
res = (d1) + (d2) + (d3) + (d1*d2) + (d1*d3) + (d2*d3) + ...
    = (1 + d1) * (1 + d2) * (1 + d3) * ...
*/

// Method 1
// O(n*log(n))
vector<int> factors[N + 5];
void factorOfAllNumbers() {
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            factors[j].pb(i);
        }
    }
}

void solve() {
    int x, y, z, l, r;
    cin >> n;
    int res = 1;
    for(int x: factors[n]) {
        res = ((res % MOD) * ((x + 1) % MOD)) % MOD;
    }

    res -= 1;

    cout << res << endl;
}

signed main() {
    IOS
    factorOfAllNumbers();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}





























// Method 2
// O(n*log(n))
int res[N + 5];
void precompute() {
    for(int i = 1; i <= N; i++) {
        res[i] = 1;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            res[j] *= (i + 1);
            res[j] = (res[j] + MOD) % MOD;
        }
    }
}

void solve() {
    int x, y, z, l, r;
    cin >> n;
    cout << res[n] - 1 << endl;
}

signed main() {
    IOS
    precompute();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}

























// TLE Solution
vector<int> factors[N + 5];
void factorOfAllNumbers() {
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            factors[j].pb(i);
        }
    }
}

int _mod(int x) {
    return (x + MOD) % MOD;
}

void solve() {
    int x, y, z, l, r;
    cin >> n;
    int res = 0;
    vi a;
    for(int x: factors[n]) {
        vi temp;
        temp.pb(x);
        res += x;
        _mod(res);
        for(int y: a) {
            z = (x * y) % MOD;
            temp.pb(z);
            res += z;

            _mod(res);
        }

        for(int x: temp) {
            a.pb(x);
        }
    }

    cout << _mod(res) << endl;
}

signed main() {
    IOS
    factorOfAllNumbers();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
