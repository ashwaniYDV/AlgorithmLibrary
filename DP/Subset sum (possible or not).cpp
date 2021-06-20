// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

// method 1
// DP with bitmasking

// method 2
ll fun(ll a[], ll pos, ll sum){
    if(pos < 0 || sum < 0) return 0;
    if(sum == 0) return 1;

    return fun(a, pos - 1, sum - a[pos]) || fun(a, pos - 1, sum);
}

// methid 3
ll dp_method(ll a[], ll sum){
    ll dp[n+1][sum + 1];
    for (ll i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (ll j = 1; j <= sum; j++) {
        dp[0][j] = 0;
    }
    for (ll i = 1; i <= n; i++) { 
        for (ll j = 1; j <= sum; j++) { 
            if(j < a[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

void solve() {
    ll x, y, z, sum;
    cin >> n;
    ll a[n];
    f(i, n) cin >> a[i];
    cin >> sum;
    // cout << dp_method(a, sum) << endl;
    cout << fun(a, n - 1, sum) << endl;
}
