// https://www.codechef.com/ZCOPRAC/problems/ZCO16002
// https://unacademy.com/class/learn-dp-through-problem-solving-3/URYJEHRL

/*
Given an array of n distinct numbers. Select a max size subset from it which forms an arithmetic progression.  
*/

// AC Brute Force
void solve() {
	int x, y;
	cin >> n;
	vi a(n);
	f(i, n) cin >> a[i];

	if(n == 1) {
		cout << 1 << endl;
		return;
	}

	sort(all(a));
	int cnt[a[n-1] + 5] = {0};

	f(i, n) cnt[a[i]] = 1;

	int res = 0;
	f(i, n-1) {
		x = a[i];
		for(int j = i+1; j < n; j++) {
			y = a[j];
			int d = y - x;
			int c = 2;
			while(y + d <= a[n-1] && cnt[y+d] == 1) {
				c++;
				y += d;
			}

			res = max(res, c);
		}
	}

	cout << res << endl;
}












// DP O(n^2.log(n))
void solve() {
	int x, y, z, d;
	cin >> n;
	vi a(n);
	f(i, n) cin >> a[i];

	if(n <= 2) {
		cout << n << endl;
		return;
	}

	sort(all(a));

	vector<vector<int>> dp(n, vector<int>(n, 0));
	// dp[i][j] = longest AP which has a[i] and a[j] as second last and last ele respectively
	// hence common difference => d = a[j] - a[i]
	// if we find an element at position k (k < i) such that a[k] = a[i] - d  (i.e a[k], a[i], a[j] are in AP)
	// then dp[i][j] = dp[k][i] + 1
	// else dp[i][j] = 2

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			d = a[j] - a[i];
			x = a[i] - d;
			int k = lower_bound(all(a), x) - a.begin();
			if(k < n && a[k] == x) {
				dp[i][j] = dp[k][i] + 1;
			} else {
				dp[i][j] = 2;
			}
		}
	}

	int res = 0;
	f(i, n) {
		f(j, n) res = max(res, dp[i][j]);
	}
	cout << res << endl;
}













// DP O(n^2)
void solve() {
	int x, y, z, d;
	cin >> n;
	vi a(n);
	f(i, n) cin >> a[i];

	if(n <= 2) {
		cout << n << endl;
		return;
	}

	sort(all(a));

	vi pos(a[n-1] + 5, -1);
	f(i, n) pos[a[i]] = i;

	vector<vector<int>> dp(n, vector<int>(n, 0));
	// dp[i][j] = longest AP which has a[i] and a[j] as second last and last ele respectively
	// hence common difference => d = a[j] - a[i]
	// if we find an element at position k (k < i) such that a[k] = a[i] - d  (i.e a[k], a[i], a[j] are in AP)
	// then dp[i][j] = dp[k][i] + 1
	// else dp[i][j] = 2

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			d = a[j] - a[i];
			x = a[i] - d;
			if(x >= 0 && pos[x] != -1) {
				int k = pos[x];
				dp[i][j] = dp[k][i] + 1;
			} else {
				dp[i][j] = 2;
			}
		}
	}

	int res = 0;
	f(i, n) {
		f(j, n) res = max(res, dp[i][j]);
	}
	cout << res << endl;
}
