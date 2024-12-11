// https://www.codechef.com/practice/course/zco-inoi-problems/IARCSJUD/problems/CATERCON

/*
dp[i][0] = max volume of passengers for subtree rooted at node i, if the root (node i) of that subtree is not included.
dp[i][1] = max volume of passengers for subtree rooted at node i, if the root (node i) of that subtree is included.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5+5;

int costs[N];
vector<int> g[N];
int dp[N][2];

int n, m;

void dfs(int u, int par) {
    dp[u][0] = 0;
    dp[u][1] = costs[u];

    for(int v: g[u]) {
        if(v == par) continue;

        dfs(v, u);

        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void solve() {
    int u, v;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> costs[i];
        dp[i][0] = 0;
        dp[i][1] = 0;
        g[i].clear();
    }

    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1);

    cout << max(dp[1][0], dp[1][1]) << endl;
}

int32_t main() {
    solve();
}
