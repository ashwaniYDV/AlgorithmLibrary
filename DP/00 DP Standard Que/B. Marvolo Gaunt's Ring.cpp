// https://codeforces.com/problemset/problem/855/B

/*
Create a dynamic programming table of size n·3. 
In this, dp[i][0] stores maximum of value p·ax for x between 1 and i. 
Similarly dp[i][1] stores the maximum value of p·ax + q·ay such that x ≤ y ≤ i 
and dp[i][2] stores maximum value of p·ax + q·ay + r·az for x ≤ y ≤ z ≤ i.

To calculate the dp:

dp[i][0] = max(dp[i - 1][0], p·ai)

dp[i][1] = max(dp[i - 1][1], dp[i][0] + q·ai)

dp[i][2] = max(dp[i - 1][2], dp[i][1] + r·ai)

The answer will be stored in dp[n][2]
*/

 vi a, p; 
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





// TLE
vi a, p;
int dp[100005][5];
 
int go(int i, int j) {
	if(j == 3) return 0;
	if(i == n) return -3*INF;
 
	if(dp[i][j] != -1) return dp[i][j];
 
	return dp[i][j] = max(a[i]*p[j] + go(i, j+1), go(i+1, j));
}
 
void solve() {
	int x, y, z, k;
	p.resize(3);
	cin >> n >> p[0] >> p[1] >> p[2];
	a.resize(n);
	f(i, n) cin >> a[i];
 
	memset(dp, -1, sizeof dp);
	cout << go(0, 0) << endl;
}
