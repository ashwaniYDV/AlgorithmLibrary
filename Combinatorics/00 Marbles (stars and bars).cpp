// https://www.spoj.com/problems/MARBLES/

// https://cp-algorithms.com/combinatorics/stars_and_bars.html

/*
x1 + x2 + x3 + ... + xk = n
Stars = n
Bars = k-1
Non negative solutions = (n+k-1)C(k-1) = (n+k-1)C(n)


Non negative non zero solutions = (n-1)C(k-1) = (n-1)C(n)
Derivation:
x1+1 + x2+1 + x3+1 + ... + xk+1 = n
x1 + x2 + x3 + ... + xk = n - k

Stars = n-k
Bars = k-1

Thus ((n-k) + k-1)C(k-1) = (n-1)C(k-1)
*/

int ncr(int n, int r) {
    if(r > n-r) {
        r = n-r;
    }
    int ans = 1;
    for(int i = 1; i <= r; i++) {
        ans *= (n - i + 1), ans /= i;
    }
    return ans;
}

void solve() {
    int x, y, z, k;
    cin >> n >> k;

    cout << ncr(n-1, k-1) << endl;
}
 
signed main() {
    IOS
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
}
