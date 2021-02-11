
int goDp[N][2];

int go(int pos, int state, vi& a) {
	if(pos >= n) return 0;

	if(goDp[pos][state] != -1) return goDp[pos][state]; 

	int x = 0, y = 0;
	if(state == 0) {
		x = a[pos] + go(pos+1, 1, a);
	}
	y = go(pos+1, 0, a);

	return goDp[pos][state] = max(x, y);
}

void solve() {
	cin >> n;
	vi a(n);
	f(i, n) cin >> a[i];
	// memset(goDp, -1, sizeof goDp);
	// cout << go(0, 0, a) << endl;

  // DP soln
	if(n == 1) {
		cout << a[0] << endl;
		return;
	}
	if(n == 2) {
		cout << max(a[0], a[1]) << endl;
		return;
	}
	
	int dp[n+1] = {0};
	dp[0] = a[0];
	dp[1] = max(a[0], a[1]);
	
	fa(i, 2, n) {
		dp[i] = max({dp[i-1], a[i] + dp[i-2]});
	}

	cout << dp[n-1] << endl;
}
