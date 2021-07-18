// https://cses.fi/problemset/task/1681/
// https://usaco.guide/problems/cses-1681-game-routes/solution

/*
Problem:
A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. 
The game has been designed so that there are no directed cycles in the underlying graph. 
In how many ways can you complete the game?

Input:
The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1,2,…,n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.

Output:
Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 10^9+7.
*/


/*
Solution:
Time Complexity: O(N + M)

This problem is very similar to the "Longest Flight Route" problem. 
Let dp[v] denote the number of paths reaching v. 

Clearly: 
dp[v] = Summation{edge u->v exists dp[u]},
        or 1 if v is src node

We process the nodes topologically so dp[u] will already have been computed before dp[v].
*/

// Method 1: DP
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int MOD = 1e9+7;

const int N = 2e5+5;
int n, m;

vector<int> g[N];
int dp[N], inDegree[N];

void topologicalSort(int src) {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    dp[src] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: g[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;

            inDegree[v]--;
            if(inDegree[v] == 0) q.push(v);
        }
    }

}

void solve() {
    int u, v;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        inDegree[i] = 0;
    }

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        inDegree[v]++;
        g[u].push_back(v);
    }

    int src = 1, dest = n;
    topologicalSort(src);

    cout << dp[dest] << endl;
}  

int32_t main() {
    solve();
}






// Method 2: DFS
const int N = 3e5+5;
int n, m;

vector<int> g[N];
vector<int> dp(N, -1);

void dfs(int u) {
    if(dp[u] != -1) return;

    dp[u] = 0;
    
    for(int v: g[u]) {
        dfs(v);

        dp[u] += dp[v];
        dp[u] %= MOD;
        if(dp[u] < 0) dp[u] += MOD;
    }
}
 
void solve() {
    int x, y;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        g[x].pb(y);
    }

    // base case of DP
    dp[n] = 1;

    dfs(1);

    cout << dp[1] << "\n";
}
