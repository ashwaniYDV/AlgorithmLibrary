// https://codeforces.com/problemset/problem/340/D

/*
Standard O(NlogN) LIS since N = 10^5
*/

void solve() {
    cin >> n;
    vi a(n);
    f(i, n) cin >> a[i];

    vector < int > seq;
    seq.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        if (a[i] > seq.back()) {
            seq.push_back(a[i]);
        } else {
            int idx = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
            seq[idx] = a[i];
        }
    }

    cout << seq.size() << endl;
}
