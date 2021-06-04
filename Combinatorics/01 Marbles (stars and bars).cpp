// https://www.spoj.com/problems/MARBLES/

/*
a1 + a2 + a3 + ... + ak = n
Non negative solutions = (n+k-1)C(k-1) = (n+k-1)C(n)


Non negative solutions non zero = (n-1)C(k-1) = (n-1)C(n)
Derivation:
a1+1 + a2+1 + a3+1 + ... + ak+1 = n
a1 + a2 + a3 + ... + ak = n - k
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
