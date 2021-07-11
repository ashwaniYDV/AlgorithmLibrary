// https://www.spoj.com/problems/AGGRCOW/
// https://youtu.be/SiE1XFhYoaA


// TTTTTFFFFF

void solve() {
    int x, y, c;
    cin >> n >> c;
    vector<int> a(n);
    f(i, n) cin >> a[i];

    sort(all(a));

    int lo = 0, hi = a[n-1];
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;

        int cnt = 1, left = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] - a[left] >= mid) {
                left = i, cnt++;
            }
        }

        if(cnt >= c) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
}

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}
