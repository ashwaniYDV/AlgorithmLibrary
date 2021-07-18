// https://youtu.be/phgjL7SbsWs
// Jump Game (Minimum nuber of paths required)(Print all paths)

// Method 1
struct node {
    int index;
    int sizeOfJump;
    int jumpsRequired;
    string pathSoFar;
};

void solve() {
    cin >> n;
    vector<int> jump(n);
    f(i, n) cin >> jump[i];

    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= jump[i]; j++) {
            if (i + j >= n) break;
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    cout << "Min number of jumps = " << dp[n - 1] << endl;

    // reverse engineering
    queue<node> q;
    q.push({0, jump[0], dp[0], "0"});

    while (q.size()) {
        node x = q.front();
        q.pop();

        if (x.index == n - 1) {
            cout << x.pathSoFar << endl;
        }

        for (int j = 1; j <= x.sizeOfJump; j++) {
            int nextIndex = x.index + j;
            if (nextIndex >= n) break;

            if (nextIndex != n - 1 && jump[nextIndex] == 0) continue;

            if (dp[nextIndex] == x.jumpsRequired + 1) {
                q.push({nextIndex, jump[nextIndex], dp[nextIndex], x.pathSoFar + " -> " + to_string(nextIndex)});
            }
        }
    }
}






















// Method 2
struct node {
    int index;
    int sizeOfJump;
    int jumpsRequired;
    string pathSoFar;
};

void solve() {
    cin >> n;
    vector<int> jump(n);
    f(i, n) cin >> jump[i];

    vector<int> dp(n, INF);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j <= jump[i]; j++) {
            if (i + j >= n) break;
            dp[i] = min(dp[i], dp[i + j] + 1);
        }
    }
    cout << "Min number of jumps = " << dp[0] << endl;

    // reverse engineering
    queue<node> q;
    q.push({0, jump[0], dp[0], "0"});

    while (q.size()) {
        node x = q.front();
        q.pop();

        if (x.jumpsRequired == 0) {
            cout << x.pathSoFar << endl;
        }

        for (int j = 1; j <= x.sizeOfJump; j++) {
            int nextIndex = x.index + j;
            if (nextIndex >= n) break;

            if (dp[nextIndex] == INF) {
                continue;
            }

            if (dp[nextIndex] == x.jumpsRequired - 1) {
                q.push({nextIndex, jump[nextIndex], dp[nextIndex], x.pathSoFar + " -> " + to_string(nextIndex)});
            }
        }
    }
}


/*
Input:
10
3 3 0 2 1 2 4 2 0 0

Output:
Min number of jumps = 4
0->3->5->6->9
0->3->5->7->9
*/
