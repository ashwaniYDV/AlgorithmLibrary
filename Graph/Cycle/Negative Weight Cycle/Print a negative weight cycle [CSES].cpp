// https://cses.fi/problemset/task/1197/

/*
You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.

Input:
The first input line has two integers n and m: the number of nodes and edges. 
The nodes are numbered 1,2,…,n.
After this, the input has m lines describing the edges. 
Each line has three integers a, b, and c: there is an edge from node a to node b whose length is c.
*/

/*
Approach:
Perform N-1 iterations of Bellman-Ford algorithm and relax each edge (u, v). 
Keep track of parent of each vertex and store in an array parent[].
Now, do one more iteration and if no edge relaxation take place in this Nth iteration, then there is no cycle of negative weight exists in the graph.

Otherwise take a variable node and store the vertex v from any edge (u, v), which is relaxed in the Nth iteration.
Now, starting from the node vertex go towards its ancestors until a cycle is found and finally print it.
This cycle will be the desired cycle of negative weight.
*/

void solve() {
    int u, v, w;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    f(i, m) {
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }

    vector<int> dis(n+1, INF);
    int src = 1;
    dis[src] = 0;
    vector<int> par(n+1);

    int node;
    for (int i = 1; i <= n; ++i) {
        node = -1;
        for (auto it: edges) {
            tie(u, v, w) = it;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                par[v] = u;
                node = v;
            }
        }
    }

    if (node == -1) {
        cout << "NO\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            node = par[node];
        }

        vector<int> cycle;
        for (int cur = node; ; cur = par[cur]) {
            cycle.push_back(cur);
            if(cur == node && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle) cout << v << ' ';
        cout << endl;
    }
}
