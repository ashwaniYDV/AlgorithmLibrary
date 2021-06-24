// Method 1
void solve() {
    int diff;
    cin >> n >> diff;
    int a[n];
    f(i, n) cin >> a[i];

    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];

    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int j = 1; j <= sum; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < a[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            }
        }
    }

    int res = 0;
    for (int j = 0; j <= sum; j++) {
        if (dp[n][j]) {
            if(abs((sum - j) - j) == diff) {
                res += dp[n][j];
            }
        }
    }

    cout << res / 2 << endl;
}







// Method 2

/*
Let there be two subsets with sum s1 and s2 respectively
s1 + s2 = arrSum
s1 - s2 = diff
so solving the above equations, we get:
s1 = (diff + arr_sum) / 2
Therefore, question reduces to find number of subsets with sum as s1
*/

void solve() {
    int diff;
    cin >> n >> diff;
    int a[n];
    f(i, n) cin >> a[i];

    int arrSum = 0;
    for(int i = 0; i < n; i++) arrSum += a[i];

    int sum = (diff + arrSum) / 2;

    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int j = 1; j <= sum; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < a[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            }
        }
    }

    cout << dp[n][sum] << endl;
}
