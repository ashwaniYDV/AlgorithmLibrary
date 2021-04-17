// https://codeforces.com/problemset/problem/855/B


 vi a, p;
// int dp[100005][5];
 
// int go(int i, int j) {
// 	if(j == p.size()) return 0;
// 	if(i == n) return -3*INF;
 
// 	if(dp[i][j] != -1) return dp[i][j];
 
// 	return dp[i][j] = max(a[i]*p[j] + go(i, j+1), go(i+1, j));
// }
 
void solve() {
	int x, y, z;
	p.resize(3);
	cin >> n;
	f(i, 3) cin >> p[i];
	a.resize(n);
	f(i, n) cin >> a[i];
 
	vector<vector<int>> dp(n, vector<int>(3));
 
	dp[0][0] = a[0]*p[0];
	dp[0][1] = a[0]*p[0] + a[0]*p[1];
	dp[0][2] = a[0]*p[0] + a[0]*p[1] + a[0]*p[2];
 
	fa(i, 1, n) {
		dp[i][0] = max(dp[i-1][0], a[i] * p[0]);
		dp[i][1] = max(dp[i-1][1], dp[i][0] + a[i] * p[1]);
		dp[i][2] = max(dp[i-1][2], dp[i][1] + a[i] * p[2]);
	}
	cout << dp[n-1][2] << endl;
}
