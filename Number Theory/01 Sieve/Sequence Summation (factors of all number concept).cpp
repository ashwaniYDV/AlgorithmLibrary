// https://www.codechef.com/problems/GEEK05
// https://unacademy.com/class/sieve-of-eratosthenes/GVMRBBT5

/*
For a sequence a_1, a_2, a_3 ..... a_N

Consider we have calculated series upto a_n-1, i.e (a_1, a_2, ... , a_n-1)
and we want to calculate a_n.

Let divisors of a_n = 1, d1, d2, ..., a_dm, a_n   (sice 1, n are also divisors of n)
Then a_1 + a_d1 + ... + a_dm + a_n = 2^n
a_n = 2^n - (a_1 + a_d1 + ... + a_dm)

This arr[n] = 2^n - Summation{arr[divisors of n excluding n]}
*/


const int N = 1e5+5;
int n, m;


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

// O(n*log(n))
vector<int> factors[N + 5];
void factorOfAllNumbers() {
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            factors[j].pb(i);
        }
    }
}

int arr[N + 5];
int res[N + 5];
void precompute() {
    factorOfAllNumbers();

    arr[1] = 2;
    loop(i, 2, N) {
        arr[i] = power(2, i);
        // neglecting factor = number i itself (therefore running loop from 0 to n-2)
        n = factors[i].size();
        f(j, n - 1) {
            int idx = factors[i][j];
            arr[i] -= arr[idx];
            arr[i] = (arr[i] + MOD) % MOD;
        }
    }

    loop(i, 1, N) {
        res[i] = arr[i] + res[i - 1];
        res[i] %= MOD;
    }
}

void solve() {
    int x, y, z, l, r;
    cin >> l >> r;
    x = res[r] - res[l - 1];
    x = (x + MOD) % MOD;
    cout << x << endl;
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
