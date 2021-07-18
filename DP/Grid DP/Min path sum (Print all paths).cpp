// https://youtu.be/f8Vdifn2YjQ

struct node {
    int i;
    int j;
    string pathSoFar;
};

void solve() {
    cin >> n >> m;
    int grid[n][m];
    f(i, n) {
        f(j, m) {
            cin >> grid[i][j];
        }
    }

    int dp[n][m];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else if (i == 0) {
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            } else {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "Min Cost of path = " << dp[n - 1][m - 1] << endl;

    // reverse engineering
    queue<node> q;
    q.push({n - 1, m - 1, ""});

    while (q.size()) {
        node x = q.front();
        q.pop();

        if (x.i == 0 && x.j == 0) {
            string path = x.pathSoFar;
            reverse(all(path));
            cout << path << endl;
        } else if (x.i == 0) {
            q.push({x.i, x.j - 1, x.pathSoFar + "H" });
        } else if (x.j == 0) {
            q.push({ x.i - 1, x.j, x.pathSoFar + "V" });
        } else {
            if (dp[x.i][x.j - 1] < dp[x.i - 1][x.j]) {
                q.push({x.i, x.j - 1, x.pathSoFar + "H" });
            } else if (dp[x.i][x.j - 1] > dp[x.i - 1][x.j]) {
                q.push({ x.i - 1, x.j, x.pathSoFar + "V" });
            } else {
                q.push({x.i, x.j - 1, x.pathSoFar + "H" });
                q.push({ x.i - 1, x.j, x.pathSoFar + "V" });

                // agar answer ke ordering ka issue aae to "V" wala pehle daal do queue me
                // q.push({ x.i - 1, x.j, x.pathSoFar + "V" });
                // q.push({x.i, x.j - 1, x.pathSoFar + "H" });
            }
        }
    }
}
