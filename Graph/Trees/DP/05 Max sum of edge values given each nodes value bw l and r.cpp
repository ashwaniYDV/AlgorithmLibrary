// https://codeforces.com/contest/1529/problem/C
// C. Parsa's Humongous Tree

/*
Problem:
You have a tree on n vertices.
On each vertex v he has written two integers lv and rv.
You wants to assign a number av (lv ≤ av ≤ rv) to each vertex v such that the beauty of the tree is maximized.
Beauty of the tree = sum of |au−av| over all edges (u,v) of the tree.
Your task is to find the maximum possible beauty of tree.
*/

/*
The solution is based on the fact that an optimal assignment for a exists such that for each vertex v, av = (lv or rv).
Thus each node does not have value between lv, rv. Each node value is exactly either lv or rv.

Based on this fact, we can use dynamic programming to find the answer.
Define: 
dp[u][0] = maximum beauty of u's subtree if au = lv.
dp[u][1] = maximum beauty of u's subtree if au = rv.

dp[u][j] is calculated based on u's children, for each of u's children such as v, we add v's contribution to dp[u][j].

The transitions are:
dp[u][0] += max(dp[v][0]+|lu−lv|, dp[v][1]+|lu−rv|)
dp[u][1] += max(dp[v][0]+|ru−lu|, dp[v][1]+|ru−rv|)

answer = max(dp[1][0], dp[1][1])
*/

const int N = 2e5+5;
int n, m;

pii a[N];
vi g[N];
int dp[N][2];

void dfs(int u, int par) {
    dp[u][0] = dp[u][1] = 0;

    for(int v: g[u]) {
        if(v == par) continue;

        dfs(v, u);

        dp[u][0] += max(dp[v][0] + abs(a[u].F - a[v].F), dp[v][1] + abs(a[u].F - a[v].S));
        dp[u][1] += max(dp[v][0] + abs(a[u].S - a[v].F), dp[v][1] + abs(a[u].S - a[v].S));
    }
}

void solve() {
    int x, y, z, u, v;
    cin >> n;
    loop(i, 1, n) {
        cin >> a[i].F >> a[i].S;
        g[i].clear();
    }
    f(i, n-1) {
        cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
}

signed main() {
    IOS
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
}
