// Longest Path in DAG from src to dest (DP concept of Topo Sort)
// https://cses.fi/problemset/task/1680/
// https://usaco.guide/gold/toposort?lang=cpp#dynamic-programming

/*
Problem:
Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. 
Of course, Uolevi wants to choose a trip that has as many cities as possible.
Uolevi wants to fly from city 1 to city n so that he visits the maximum number of cities. 
You are given the list of possible flights, and you know that there are no directed cycles in the flight network.

Input:
The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n.
After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. 
Each flight is a one-way flight.

Output:
First print the maximum number of cities on the route. 
After this, print the cities in the order they will be visited. 
You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
*/



/*
Intuition:
One useful property of DAG is, as the name suggests, that no cycles exist. 
If we consider each node in the graph as a state, 
we can perform dynamic programming on the graph if we process the states in an order that guarantees for every edge u->v that u is processed before v.
Fortunately, this is the exact definition of a topological sort!

In this task, we must find the longest path in a DAG.
Let dp[v] denote the length of the longest path from src ending at the node v,
Clearly:
dp[v] = Max{edge u->v exists (dp[u] + 1)} 
        or 1 if v is src node
        
If we process the states in topological order, it is guaranteed that dp[u] will already have been computed before computing dp[v]
*/


// Method 1
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 2e5+5;
int n, m;

vector<int> g[N];
int parent[N], dp[N], inDegree[N];

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
            if(dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
            // this is important (since src can lie in middle of some longest DAG path)
            if(v == src) dp[src] = 1;

            inDegree[v]--;
            if(inDegree[v] == 0) q.push(v);
        }
    }
}

void solve() {
    int u, v;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = -1;
        dp[i] = -INF;
        inDegree[i] = 0;
    }

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        inDegree[v]++;

        g[u].push_back(v);
    }

    int src = 1, dest = n;
    topologicalSort(src);

    int node = dest;
    bool containsSrc = false;
    if(node == src) containsSrc = true;

    vector<int> res;

    while(node != -1 && dp[node] >= 0) {
        res.push_back(node);
        node = parent[node];
        if(node == src) containsSrc = true;
    }

    if(!containsSrc) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    cout << dp[dest] << endl;

    reverse(res.begin(), res.end());
    for(int x: res) cout << x << " ";
}

int32_t main() {
    solve();
}













// Method 2
const int N = 3e5+5;
int n, m;

vector<int> g[N];
vector<int> dp(N, -1), child(N, -1);

void dfs(int u) {
    if(dp[u] != -1) return;

    dp[u] = 0;
    
    for(int v: g[u]) {
        dfs(v);

        if(dp[v] > dp[u]) {
            dp[u] = dp[v];
            child[u] = v;
        }
    }
    if(dp[u] > 0) dp[u]++;
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

    if(dp[1] == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    } 

    cout << dp[1] << "\n";
    int u = 1;
    while(u != -1) {
        cout << u << " ";
        u = child[u];
    }
}
