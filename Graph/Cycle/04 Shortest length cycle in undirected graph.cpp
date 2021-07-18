/*
Problem name: Graph Girth
Link: https://cses.fi/problemset/task/1707/
USACO: https://usaco.guide/problems/cses-1707-graph-girth/solution
*/


/*
Given an undirected graph, your task is to determine its girth, i.e., the length of its shortest cycle.

Input:
The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1,2,…,n.
After this, there are m lines describing the edges. Each line has two integers a and b: there is an edge between nodes a and b.
You may assume that there is at most one edge between each two nodes.

Output:
Print one integer: the girth of the graph. If there are no cycles, print −1.

Constraints:
1≤n≤2500
1≤m≤5000

Example:
Input:
5 6
1 2
1 3
2 4
2 5
3 4
4 5

Output:
3
*/






/*
Let's consider a simpler problem: given a graph, find the shortest cycle that passes through node 1.

What does a cycle through node 1 look like? In any cycle through node 1, there exists two nodes u and v on that cycle 
such that there is a path from 1 to u and 1 to v, and there is an edge between u and v. 
The length of this cycle is dist(1, u) + dist(1, v) + 1.

One might now try to use BFS to find dist(1, i) for each i in O(N + M) time 
and then check for each edge (u, v) whether dist(1, u) + dist(1, v) + 1 is minimal.

Of course, this means that we might count a "cycle" like (1 -> x -> u -> v -> x -> 1).
                  1
                  |
                  x
                /   \
                u __ v
                  
However, this doesn't matter for our original problem, since the shortest cycle will always be shorter than such a "cycle".
(This shorter cycle will come when we set x as root)

There's one problem with this approach though: if the edge (u, v) is on the path from node 1 to node v, then (1 -> u -> v -> 1) isn't a cycle! 
And this time, it does matter in our original problem!

Fortunately, there's a relatively simple fix.
Instead of first finding all dist(1, i) and then checking for the minimum, do both at the same time during the BFS.

Now to prevent "backtracking", we only consider dist(1, u) + dist(1, v) + 1 as a minimum if we're currently at node u and dist(1, v) >= dist(1, u).

This algorithm runs in O(N + M) time. Since N and M are so small, we can just apply this algorithm for all nodes instead of just node 1.
The final complexity of this solution is thus O(N(N + M)).
*/




const int N = 2510;
int n, m;

vector<int> g[N];

int bfs(int src) {
    vector <int> dist(n+1, -1);
    
    queue <int> q;
    q.push(src);
    dist[src] = 0;

    int cycle_len = INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if (dist[v] >= dist[u]) {
                cycle_len = min(cycle_len, dist[v] + dist[u] + 1);
            }
        }
    }

    return cycle_len;
}

void solve() {
    int u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int res = INF;
    for (int i = 1; i <= n; i++) {
        res = min(res, bfs(i));
    }

    if (res == INF) {
        cout << -1 << endl;
        return;
    }

    cout << res << endl;
}
