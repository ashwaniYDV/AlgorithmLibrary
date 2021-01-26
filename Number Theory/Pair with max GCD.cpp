// O(N.sqrt(N))
/*
Mark all divisors of each element, in O(n.sqrt(n)). 
Then find maximum element of mark array that is marked more than twice, in O(n).
*/
vi cnt;
void getDivisors(int n) {
    for (int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            cnt[i] += 1;
            if(i != n/i) cnt[n / i] += 1;
        }
    }
}

void solve() {
    ll x, y, z, k, sum = 0, d;
    vi a = { 1, 2, 4, 8, 8, 12 };
    n = a.size();

    int mx = 0;
    f(i, n) mx = max(mx, a[i]);

    cnt.resize(mx + 1, 0);

    f(i, n) getDivisors(a[i]);

    for (int i = mx; i >= 1; i--) {
        if(cnt[i] >= 2) {
            cout << i << endl;
            return;
        }
    } 
    
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
