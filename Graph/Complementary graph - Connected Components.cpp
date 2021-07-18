/*
Problem 1) https://codeforces.com/contest/920/problem/E
Problem 2) https://codeforces.com/problemset/problem/190/E

Que - Find number of connected components in the original graph if complementary graph is given of the original graph
Time - O(n*log(n))
*/


/*
Problem 1) https://codeforces.com/contest/920/problem/E

You are given an undirected graph consisting of n vertices and n*(n-1)/2 - m edges. Instead of giving you the edges that exist in the graph, 
we give you m unordered pairs (x, y) such that there is no edge between x and y, and if some pair of vertices is not listed in the input, 
then there is an edge between these vertices.
You have to find the number of connected components in the graph and the size of each component. 
*/

// Problem 1 - Method 1 (DFS)
const int N = 2e5+5;
int n, m;
set<int> unvisited;
set<int> g[N];
int cnt = 0;

void dfs(int u) {
    cnt++;
    unvisited.erase(u);
    vector<int> tmp;

    for(int x: unvisited) {
        if(g[u].count(x) == 0) {
            tmp.pb(x);
        }
    }
    for(int v: tmp) {
        unvisited.erase(v);
    }
    for(int v: tmp) {
        dfs(v);
    }
}

void solve() {
    int u, v;
    cin >> n >> m;

    f(i, m) cin >> u >> v, g[u].insert(v), g[v].insert(u);

    vector<int> res;

    for(int i = 1; i <= n; i++) {
        unvisited.insert(i);
    }
    for(int i = 1; i <= n; i++) {
        if(unvisited.count(i)) {
            cnt = 0;
            dfs(i);
            res.pb(cnt);
        }
    }

    sort(all(res));
    cout << res.size() << endl;
    for(auto i: res) cout << i <<' ';
}












// Problem 1 - Method 2 (BFS)
const int N = 2e5+5;
int n, m;
set<int> unvisited;
set<int> g[N];
int cnt = 0;

void bfs(int node) {
    queue <int> q;
    q.push(node);
    unvisited.erase(node);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        vector<int> tmp;

        for(int x: unvisited) {
            if(g[u].count(x) == 0) {
                tmp.pb(x);
                q.push(x);
            }
        }
        for(int v: tmp) {
            unvisited.erase(v);
        }
    }
}

void solve() {
    int u, v;
    cin >> n >> m;

    f(i, m) cin >> u >> v, g[u].insert(v), g[v].insert(u);

    vector<int> res;

    for(int i = 1; i <= n; i++) {
        unvisited.insert(i);
    }
    for(int i = 1; i <= n; i++) {
        if(unvisited.count(i)) {
            cnt = 0;
            bfs(i);
            res.pb(cnt);
        }
    }

    sort(all(res));
    cout << res.size() << endl;
    for(auto i: res) cout << i <<' ';
}
