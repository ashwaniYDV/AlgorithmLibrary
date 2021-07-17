// https://codeforces.com/problemset/problem/518/D

/*
To solve this problem let's use dynamic programming. 
We will store two-dimensional array dp[][] with type double. In dp[i][j] will store the likelihood that after i seconds j people are on escalator.

In dynamic will be following transitions. 
If j  =  n, i. e. all n people already on escalator then we make transition dp[i][n] = (dp[i-1][n-1] * p) + dp[i-1][n];. 
Else, or person number j go to escalator in i second, i. e. dp[i ][j] +  = dp[i-1][j-1] * p, 
or person number j stays on his place, i. e. z[i ][j]   + =  dp[i-1][j] * (1 - p).
Overall dp[i][j] = (dp[i-1][j-1] * p) + (dp[i-1][j] * (1 - p));
*/

ld dp[2005][2005];

void solve() {
    int x, y, z, t;
    ld p;
    cin >> n >> p >> t;
    
    dp[0][0] = 1;

    for(int i = 1; i <= t; i++) {
        dp[i][0] = dp[i-1][0] * (1 - p);
    }

    for(int i = 1; i <= t; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = (dp[i-1][j-1] * p) + (dp[i-1][j] * (1 - p));
        }
        dp[i][n] = (dp[i-1][n-1] * p) + dp[i-1][n];
    }

    ld ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += i * dp[t][i];
    }
    cout << ans << endl;
}

signed main() {
    IOS
    PRECISION(10);
    clock_t begin = clock();
    int t = 1;
    // cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}
