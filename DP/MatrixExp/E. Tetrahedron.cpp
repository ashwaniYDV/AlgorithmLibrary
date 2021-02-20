
// MLE on test 13
const int N = 1e7+5;
int n, m;
 
int dp[N][2];
 
int fun(int n, int state) {
	if(n == 0) {
		if(state == 1) return 1;
		else return 0;
	}
 
	if(dp[n][state] != -1) return dp[n][state];
 
	int res = 0;
	if(state == 1) {
		res += 3 * fun(n - 1, 0);
		res %= MOD;
	} else {
		res += 2 * fun(n - 1, 0);
		res += fun(n - 1, 1);
		res %= MOD;
	}
	return dp[n][state] = res % MOD;
}
 
void solve() {
	memset(dp, -1, sizeof dp);
	cin >> n;
	cout << fun(n, 1) << endl;
}
