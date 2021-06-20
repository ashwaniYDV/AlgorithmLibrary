/*
https://cses.fi/problemset/task/1634/
This problem can only be solved by this method
*/
// order m space
ll fun(ll a[], ll sum) {
    ll dp[sum + 1];
    f(i, sum + 1) dp[i] = INF;
    // for sum = 0, coins requires = 0;
    dp[0] = 0;
    for (ll j = 1; j <= sum; j++) {
        for (ll i = 0; i < n; i++) {
            if (j >= a[i] && dp[j - a[i]] != INF) {
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }
    }
    return dp[sum];
}
// or this way
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

int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    // cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}
