// https://youtu.be/YH6M9WFp02g

struct node {
    int i, j;
    string pathSoFar;
};

void solve() {
    int W;
    cin >> n >> W;
    vi weight(n), value(n);
    f(i, n) cin >> weight[i];
    f(i, n) cin >> value[i];

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (j < weight[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
            }
        }
    }
    cout << dp[n][W] << endl;

    // reverse engineering
    queue < node > q;
    q.push({n, W, ""});

    while (!q.empty()) {
        node x = q.front();
        q.pop();

        if (x.i == 0 || x.j == 0) {
            cout << x.pathSoFar << endl;
            continue;
        }

        // excluded
        if (dp[x.i][x.j] == dp[x.i - 1][x.j]) {
            q.push({x.i - 1, x.j, x.pathSoFar});
        }

        // included
        if ((x.j >= weight[x.i - 1]) && dp[x.i][x.j] == (dp[x.i - 1][x.j - weight[x.i - 1]] + value[x.i - 1])) {
            q.push({x.i - 1, x.j - weight[x.i - 1], to_string(value[x.i - 1]) + " " + x.pathSoFar});
        }
    }
}
