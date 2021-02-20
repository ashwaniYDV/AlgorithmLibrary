// https://atcoder.jp/contests/abc192/tasks/abc192_e


// AC solution using BFS (Dijkstra)
const int N = 1e5 + 5;
int n, m, x, y;

vector < pair < int, pii >> g[N];

int findNextTime(int N, int K) {
    int rem = (N + K) % K;

    if (rem == 0)
        return N;
    else
        return N + K - rem;
}

void dijkstra(int x) {
    int dp[n + 5];
    f(i, n + 5) dp[i] = INF;

    priority_queue < pii, vector < pii > , greater < pii >> pq;
    pq.push({0, x});
    dp[x] = 0;

    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        int u = x.S;

        for (auto i: g[u]) {
            int v = i.F, t = i.S.F, k = i.S.S;
            int tempT = findNextTime(dp[u], k);

            if (dp[v] > (tempT + t)) {
                dp[v] = (tempT + t);
                pq.push({dp[v], v});
            }
        }
    }

    if (dp[y] == INF) {
        cout << -1 << endl;
        return;
    }
    cout << dp[y] << endl;
}

void solve() {
    int u, v, t, k;
    cin >> n >> m >> x >> y;
    f(i, m) {
        cin >> u >> v >> t >> k;
        g[u].pb({v, {t, k}});
        g[v].pb({u, {t, k}});
    }
    dijkstra(x);
}

























// TLE using DFS
const int N = 1e5 + 5;
int n, m, x, y;

vector < pair < int, pii >> g[N];
int vis[N];
int res = INF;

int findNextTime(int N, int K) {
    int rem = (N + K) % K;

    if (rem == 0)
        return N;
    else
        return N + K - rem;
}

void dfs(int u, int time) {
    if (u == y) {
        res = min(res, time);
        return;
    }

    vis[u] = 1;

    for (auto i: g[u]) {
        int v = i.F, t = i.S.F, k = i.S.S;
        if (vis[v]) continue;

        int tempT = findNextTime(time, k);

        dfs(v, tempT + t);
    }

    vis[u] = 0;
}

void solve() {
    int u, v, t, k;
    cin >> n >> m >> x >> y;
    f(i, m) {
        cin >> u >> v >> t >> k;
        g[u].pb({v, {t, k}});
        g[v].pb({u, {t, k}});
    }
    dfs(x, 0);
    if (res == INF) {
        cout << -1 << endl;
        return;
    }
    cout << res << endl;
}
