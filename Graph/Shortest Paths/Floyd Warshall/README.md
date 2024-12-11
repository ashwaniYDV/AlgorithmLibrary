Floy Warshall
------------
* All pairs shortest path.
* It's a dynamic programming solution.


```
This will only work
--------------------
for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
}

This will not work
--------------------
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
}
```
