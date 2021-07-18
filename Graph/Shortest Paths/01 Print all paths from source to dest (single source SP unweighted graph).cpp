// Print all shortest paths between given source and destination in an undirected unweighted graph
// https://www.geeksforgeeks.org/print-all-shortest-paths-between-given-source-and-destination-in-an-undirected-graph/

 
int dist[N];
vector<int> g[N];
vector<int> parent[N];
 
void bfs(int source) {
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e18;
    }

    queue < int > q;
    q.push(source);
    dist[source] = 0;
    parent[source] = {-1};

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: g[u]) {
            if (dist[v] > dist[u] + 1) {
                // A shorter distance is found
                // So erase all the previous parents and insert new parent u in parent[v]
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            } else if (dist[v] == dist[u] + 1) {
                // Another candidate parent for shortes path found
                parent[v].push_back(u);
            }
        }
    }
}

void find_paths(vector < vector < int > > & paths, vector < int > & path, int u) {
    // Base Case
    if (u == -1) {
        paths.push_back(path);
        return;
    }

    // Loop for all the parents of the given vertex
    for (int par: parent[u]) {
        // Insert the current vertex in path
        path.push_back(u);

        // Recursive call for its parent
        find_paths(paths, path, par);

        // Remove the current vertex
        path.pop_back();
    }
}

void printPaths(int source, int destination) {
    vector < vector < int >> paths;
    vector < int > path;

    // Function call to find_paths
    find_paths(paths, path, destination);

    for (auto v: paths) {
        // Since paths contain each path in reverse order
        reverse(v.begin(), v.end());

        // Print node for the current path
        for (int u: v) cout << u << " ";
        cout << endl;
    }
}

void solve() {
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int source = 1;
    bfs(source);

    loop(i, 1, n) {
        int destination = i;
        printPaths(source, destination);
        cout << endl;
    }
}

/*
Input:
6 7
1 2
1 3
2 4
2 5
3 4
4 6
5 6

Output:
1 

1 2 

1 3 

1 2 4 
1 3 4 

1 2 5 

1 2 4 6 
1 3 4 6 
1 2 5 6 
*/
