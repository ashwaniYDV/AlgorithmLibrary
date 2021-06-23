/*
This problem is very similar to the Unbounded Knapsack Problem, where there are multiple occurrences of the same item. Here the pieces of the rod.

An analogy between Unbounded Knapsack and the Rod Cutting Problem:

______________________________________________________________________________________________________
Unbounded Knapsack Problem                    |       Rod Cutting Problem
______________________________________________________________________________________________________
Size of array (n)                             |       Length of rod (n)
Value of the item (value[])                   |       Price of the pieces of rod (price[])
Weight array (weitht[])                       |       Length of array (length[])
Max knapsack capacity (W)                     |       Length of main rod (n == mxLength)
______________________________________________________________________________________________________
*/


void solve() {
    vi price = { 1, 5, 8, 9, 10, 17, 17, 20 };

    n = price.size();
    vi length(n);
    f(i, n) length[i] = i+1;

    int mxLength = n;

    int dp[n + 1][mxLength + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= mxLength; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(j < length[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - length[i - 1]] + price[i - 1]);
            }
        }
    }
    cout << dp[n][mxLength] << endl;
}
