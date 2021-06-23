// https://codeforces.com/contest/1427/problem/C

/*
This is a classical dynamic-programming task with a twist. 

We say that two celebrities i < j are compatible if it is possible to take a photo of both, that is
|xi - xj| + |yi - yj| ≤ tj - ti.
*/


// TLE Solution using LIS concept
struct node {
    int time, x, y;
};

void solve() {
    int x, y, z, t, r;
    cin >> r >> n;
    // Given: a is sorted with time t
    vector<node> a(n);
    f(i, n) {
        cin >> t >> x >> y;
        a[i] = {t, x, y};
    }

    int dp[n];

    // base case
    int res = 0;
    f(i, n) {
        int dist = abs(1 - a[i].x) + abs(1 - a[i].y);
        if(dist <= (a[i].time - 0)) dp[i] = 1;
        else dp[i] = 0;

        res = max(res, dp[i]);
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int dist = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
            if(dp[j] > 0 && dist <= (a[i].time - a[j].time)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << endl;
}
