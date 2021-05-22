// https://www.codechef.com/problems/COWA19C

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
