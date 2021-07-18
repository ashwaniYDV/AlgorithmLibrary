// https://atcoder.jp/contests/dp/tasks/dp_g

/*
Consider:
No cycles can exist in the graph, i.e. a DAG is formed.
The problem becomes to get the longest path in the DAG.
Topological sort can iterate the vertices of a DAG in the linear ordering.
Using Kahn's algorithm (BFS) to implement topological sort while counting the levels can give us the longest chain of nodes in the DAG.
*/

// Method 1: BFS
const int N = 3e5+5;
int n, m;

vi g[N];
int indegree[N];

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





// Method 2: DP
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

const int N = 2e5+5;
int n, m;

vector<int> g[N];
int dp[N], inDegree[N];

int topologicalSort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
            dp[i] = 0;
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            
            inDegree[v]--;
            if(inDegree[v] == 0) q.push(v);
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        res = max(res, dp[i]);
    }
    return res;
}

void solve() {
    int u, v;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        dp[i] = -INF;
        inDegree[i] = 0;
    }

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        inDegree[v]++;
        g[u].push_back(v);
    }

    cout << topologicalSort();
}


int32_t main() {
    solve();
}
