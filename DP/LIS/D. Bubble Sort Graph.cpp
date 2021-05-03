// https://codeforces.com/problemset/problem/340/D

/*
Standard O(NlogN) LIS since N = 10^5
*/

int n, m;

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
























const int N = 1e5+5;
int n, m;
int BIT[N], a[N];

void update(int i, int val) {
    while(i <= N) {
        BIT[i] = max(BIT[i], val);
        i += (i&-i);
    }
}

int query(int i) {
	if(i == 0) return 0;

    int mx = 0;
    while(i > 0) {
        mx = max(mx, BIT[i]);
        i -= (i&-i);
    }
    return mx;
}

void solve() {
	int x, y, z;

	cin >> n;
	vi a(n);

	int LIS = 0;

	f(i, n) {
		cin >> a[i];
		x = query(a[i] - 1);
		update(a[i], x + 1);
		LIS = max(LIS, x + 1);
	}
    
    cout << LIS << endl;
}
