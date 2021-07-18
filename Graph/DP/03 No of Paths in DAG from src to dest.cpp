// https://cses.fi/problemset/task/1681/
// https://usaco.guide/problems/cses-1681-game-routes/solution

/*
Problem:
A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. 
The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?
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

// Method 1
const int N = 2e5+5;
int n, m;

vector<int> g[N];
vector<int> revG[N];
int parent[N], dp[N], inDegree[N];

// Does a topological sort
void topologicalSort() {
    queue<int> q;
    loop(i, 1, n) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int next: g[node]) {
            inDegree[next]--;
            if(inDegree[next] == 0) q.push(next);
        }

        // The below block computes the DP
        for(int prev: revG[node]) {
            dp[node] = (dp[node] + dp[prev]) % MOD;
        }
    }

}

void solve() {
    int u, v;
    cin >> n >> m;

    loop(i, 1, n) {
        dp[i] = 0;
        inDegree[i] = 0;
    }

    f(i, m) {
        cin >> u >> v;
        inDegree[v]++;

        g[u].pb(v);
        revG[v].pb(u);
    }

    int src = 1, dest = n;
    dp[src] = 1;
    topologicalSort();

    cout << dp[dest] << endl;
}  





























// Method 2
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

    dp[n] = 1;
    dfs(1);

    cout << dp[1] << "\n";
}
