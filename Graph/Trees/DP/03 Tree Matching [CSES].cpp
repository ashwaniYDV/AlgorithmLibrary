// https://cses.fi/problemset/task/1130/
// https://youtu.be/RuNAYVTn9qM
// https://usaco.guide/gold/dp-trees?lang=cpp

/*
You are given a tree consisting of n nodes.
A matching is a set of edges where each node is an endpoint of at most one edge. 
What is the maximum number of edges in a matching?
Print one integer: the maximum number of pairs.
*/


/*
We hve to find the largest set of edges such that no two edges share an endpoint. 
Let's use DP on trees to do this.
Root the tree at node 1, allowing us to define the subtree of each node.

Case 1: Taking No Edges:
------------------------
dp[u][0] = maximum matching of subtree of u such that we don't take any edges leading to some child v of u
dp[u][0] = ∑ max(dp[v][0], dp[v][1])


Case 2: Taking One Edge
-----------------------
dp[u][1] = maximum matching of subtree of u such that we take one edge leading into a child of u
Note that we can't take more than one edge leading to a child, because then two edges would share an endpoint.

dp[u][1] = for all nodes v: max{ (dp[v][0] + 1) + (dp[u][0] - max(dp[v][0], dp[v][1]))) }
*/

// Method 1: DP soln
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;

vector<int> g[N];
int dp[N][2];
 
void dfs(int u, int par) {
    // precomputing dp[u][0] since dp[u][0] is required to calculate dp[u][1]
    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u);

        dp[u][0] += max(dp[v][0], dp[v][1]);
    }

    for(int v: g[u]) {
        if(v == par) continue;

        int x = (1 + dp[v][0]) + (dp[u][0] - max(dp[v][0], dp[v][1]));
        dp[u][1] = max(dp[u][1], x);
    }
}

int main() {
    int u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    }

    dfs(1, 0);
 
    cout << max(dp[1][0], dp[1][1]) << endl;  
}













// Method 2: Greedy soln
const int N = 2e5+5;
int n, m;

vi g[N];
int marked[N];
int res = 0;

void dfs(int u, int par) {
    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u);
        if(!marked[u] && !marked[v]) {
            res++;
            marked[u] = marked[v] = 1;
        }
    }
}
 
void solve() {
    int x, y, z;
    cin >> n;
    f(i, n-1) cin >> x >> y, g[x].pb(y), g[y].pb(x);

    dfs(1, 0);
 
    cout << res << endl;
}
