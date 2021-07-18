/*
https://cses.fi/problemset/task/1634/

Consider a money system consisting of n coins. Each coin has a positive integer value. 
Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.

Example:
If the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
*/

// order m space
ll fun(ll a[], ll sum) {
    ll dp[sum + 1];
    f(i, sum + 1) dp[i] = INF;
    // for sum = 0, coins requires = 0;
    dp[0] = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 1; j <= sum; j++) {
            if (j >= a[i] && dp[j - a[i]] != INF) {
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }
    }
    return dp[sum];
}


// order n*m space
void solve() {
    ll x, y, z, sum;
    cin >> n;
    ll a[n];
    f(i, n) cin >> a[i];
    cin >> sum;
    ll dp[n + 1][sum + 1];
    for(ll i = 0; i <= n; i++) dp[i][0] = 0;
    for(ll j = 1; j <= sum; j++) dp[0][j] = INF;
    
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= sum; j++){
            if(j < a[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = min(dp[i - 1][j], dp[i][j - a[i - 1]] + 1);
            }
        }
    }
    cout << dp[n][sum] << endl;
}
