void solve() {
    ll x, y, z, sum;
    cin >> n;
    ll a[n];
    f(i, n) cin >> a[i];
    cin >> sum;
    ll dp[n + 1][sum + 1];
    for(ll i = 0; i <= n; i++) dp[i][0] = 1;
    for(ll j = 1; j <= sum; j++) dp[0][j] = 0;

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= sum; j++){
            if(j < a[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            }
        }
    }
    cout << dp[n][sum] << endl;
}
