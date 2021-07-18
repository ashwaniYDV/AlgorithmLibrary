// https://cses.fi/problemset/task/1158/

/*
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. 
What is the maximum number of pages you can buy? You can buy each book at most once.
*/

void solve() {
    int sum;
    cin >> n >> sum;
    int weight[n], value[n];
    f(i, n) cin >> weight[i];
    f(i, n) cin >> value[i];

    vector<int> prevDp(sum + 1, 0), dp(sum + 1, 0);

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(i == 0 || j == 0) {
                dp[j] = 0;
                continue;
            }

            if(j >= weight[i-1]) {
                dp[j] = max(prevDp[j], prevDp[j - weight[i-1]] + value[i-1]);
            } else {
                dp[j] = prevDp[j];
            }
        }
        prevDp = dp;
    }

    cout << dp[sum] << endl;
}
