// https://atcoder.jp/contests/dp/tasks/dp_g
// https://www.geeksforgeeks.org/longest-path-in-a-directed-acyclic-graph-dynamic-programming/



// Method 1.1
const int N = 3e5+5;
int n, m;
vi g[N];
int dp[N];

int dfs(int u) {
    if(dp[u]) return dp[u];

    for (int v: g[u]) {
        dp[u] = max(dp[u], 1 + dfs(v));
    }

    return dp[u];
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v);

    memset(dp, 0, sizeof dp);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dfs(i));
    }

    cout << res << endl;
}







// Method 1.2
const int N = 3e5+5;
int n, m;
vi g[N];
int dp[N];

int dfs(int u) {
    if(dp[u] != -1) return dp[u];
    dp[u] = 0;

    for (int v: g[u]) {
        dp[u] = max(dp[u], 1 + dfs(v));
    }

    return dp[u];
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v);

    memset(dp, -1, sizeof dp);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dfs(i));
    }

    cout << res << endl;
}






// Method 1.3
const int N = 3e5+5;
int n, m;
vi g[N];
int dp[N];

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v);

    memset(dp, 0, sizeof dp);

    std::function<int(int)> dfs = [&] (int u) {
        if (dp[u]) return dp[u];
        
        for (int v: g[u]) {
            dp[u] = max(dp[u], 1 + dfs(v));
        }
        
        return dp[u];
    };

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dfs(i));
    }

    cout << res << endl;
}

















// Method 2: Topological Sort
const int N = 3e5+5;
int n, m;

vi g[N];
int dp[N], indegree[N];

void kahn() {
    queue<int> q;
    loop(i, 1, n) {
        if(indegree[i] == 0) q.push(i);
    }

    int path_len = 0;
    while(!q.empty()) {
        int sz = q.size();
        f(i, sz) {
            int u = q.front();
            q.pop();

            for(int v: g[u]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        path_len += 1;
    }
    cout << path_len - 1 << endl;
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v;
        g[u].pb(v);
        indegree[v]++;
    }
    kahn();
}
















// Method 3
const int N = 3e5+5;
int n, m;
vi g[N];
int vis[N];
int dp[N];

void dfs(int u) {
    vis[u] = 1;
    dp[u] = 0;

    for (int v: g[u]) {
        if(!vis[v]) {
            dfs(v);
        }

        dp[u] = max(dp[u], 1 + dp[v]);
    }
} 

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) cin >> u >> v, g[u].pb(v);

    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i]);
    }
    cout << res << endl;
}
