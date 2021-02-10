// https://www.codechef.com/ZCOPRAC/problems/ZCO14004
// https://unacademy.com/class/learn-dp-through-problem-solving-3/URYJEHRL


const int N = 2e5+5;
int n, m;

int goDp[N][3];

int go(int pos, int state, vi& a) {
	if(pos >= n) return 0;

	if(goDp[pos][state] != -1) return goDp[pos][state]; 

	int x = 0, y = 0;
	if(state < 2) {
		x = a[pos] + go(pos+1, state+1, a);
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

	if(n == 1) {
		cout << a[0] << endl;
		return;
	}
	if(n == 2) {
		cout << a[0] + a[1] << endl;
		return;
	}
	
	int dp[n+1] = {0};
	dp[0] = a[0];
	dp[1] = a[0] + a[1];
	dp[2] = max({a[0]+a[1], a[0]+a[2], a[1]+a[2]});
	
	fa(i, 3, n) {
		dp[i] = max({dp[i-1], a[i] + dp[i-2], a[i] + a[i-1] + dp[i-3]});
	}

	cout << dp[n-1] << endl;
}
