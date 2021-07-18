// https://cses.fi/problemset/task/1673/
// https://youtu.be/WMTIoCkVFw4

/*
You play a game consisting of n rooms (1, 2, .., n) and m tunnels. 
All tunnels are one-way tunnels.
Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. 
You may go through a tunnel several times.
Your task is to walk from room 1 to room n. 
What is the maximum score you can get?

Note:
You can assume that it is possible to get from room 1 to room n.
Print one integer: the maximum score you can get. 
However, if you can get an arbitrarily large score, print −1.

Constraints:
1 ≤ 2500 ≤ n
1 ≤ 5000 ≤ m
1 ≤ a, b ≤ n
−10^9 ≤ x ≤ 10^9
*/



/*
Note:
-----
* Bellman ford works when there is no negative weight cycle.
* But in this problem even if there is a cycle in graph but not a part of path between vertex 1 and n is tolerable.
* So we have to vis, revVis, g, revG to handle this case.
* When we negate the weights, we are implicitly talking about positive weight cycles. 

Approach:
---------
* We will calculate shortest path by negating the weights to find the longest weight path.
* But in this problem even if there is a cycle in graph but not a part of path between vertex 1 and n is tolerable.
* So we use g and revG.
* vis[u] is used to check if there exists path from 1 to u.
* revVis[v] is used to check if there exists path from n to v.
* This majorly helps in eliminating relaxation of loops which are not part of 1 to n path (which may conatin negative weight cycle).

Why run dfs twice with g and revG?
---------------------------------
* Bcoz we want to relax only those edges which lie in path from 1 to n,
  to prevent relaxation in nth iteration for loops lying outise 1 to n path. 
* If some edges lies in path outside 1 to n path and they form a positive weight cycle in original graph, 
  then also it is fine since we'll not take this positive weight cycle in our answer
* Now to check which edges lie in path from 1 to n, for each edge u->v we check if there is a path from 1->u and from v->n
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void dfs(int u, vector<int>& vis, vector<vector<int>>& g) {
    vis[u] = 1;
    for(int v: g[u]) {
        if (!vis[v]) {
            dfs(v, vis, g);
        }
    }
} 
 
void solve() {
    int n, m, u, v, w;
    cin >> n >> m;

    vector<vector<int>> g(n+1), revG(n+1);
    vector<int> vis(n+1), revVis(n+1);
    vector<tuple<int, int, int>> edges;

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        // directed graph
        edges.push_back({u, v, -w});
        g[u].push_back(v);
        revG[v].push_back(u);
    }

    dfs(1, vis, g);
    dfs(n, revVis, revG);

    vector<int> dis(n+1, INF);
    dis[1] = 0;
    bool flag = 0;

    // do n iterations to keep track of negative weight cycle on n'th iteration
    for (int i = 1; i <= n; i++) {
        flag = 0;
        for(auto it: edges) {
            tie(u, v, w) = it;
            if(vis[u] and revVis[v] and dis[v] > dis[u] + w) {
                flag = 1;
                dis[v] = dis[u] + w;
            }
        }
    }

    if(flag) cout << -1 << endl;
    else cout << -dis[n] << endl;
}

int32_t main() {
    solve();
    return 0;
}
