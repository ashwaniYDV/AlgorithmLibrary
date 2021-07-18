// https://cp-algorithms.com/graph/finding-cycle.html
// https://cses.fi/problemset/task/1669

/*
Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, 
and finally returns to the starting city. Every intermediate city on the route has to be distinct.
*/





const int N = 2e5+5;
int n, m;

vi g[N];
int vis[N], parent[N];
int cycle_start, cycle_end;

bool dfs(int u, int par) {
    vis[u] = true;
    for (int v: g[u]) {
        if(!vis[v]) {
            parent[v] = u;
            if (dfs(v, parent[v])) return true;
        }
        else if (vis[v] && v != par) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    return false;
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v, g[u].pb(v), g[v].pb(u);
    }

    loop(i, 1, n) {
        vis[i] = 0;
        parent[i] = -1;
    }
    cycle_start = -1;

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, parent[i])) break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n" << endl;
        return;
    }

    vector<int> cycle;
    cycle.pb(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.pb(v);
    }
    cycle.pb(cycle_start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << endl;
    for (int v : cycle) {
        cout << v << " ";
    }
    cout << endl;
}























const int N = 2e5+5;
int n, m;

vi g[N];
int vis[N], parent[N];
int cycle_start, cycle_end;

bool dfs(int u, int par) {
    vis[u] = true;
    for (int v: g[u]) {
        // skipping edge to parent vertex
        if(v == par) continue;

        if (vis[v]) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }

        parent[v] = u;
        if (dfs(v, parent[v])) return true;
    }
    return false;
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v, g[u].pb(v), g[v].pb(u);
    }

    loop(i, 1, n) {
        vis[i] = 0;
        parent[i] = -1;
    }
    cycle_start = -1;

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, parent[i])) break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n" << endl;
        return;
    }

    vector<int> cycle;
    cycle.pb(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.pb(v);
    }
    cycle.pb(cycle_start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << endl;
    for (int v : cycle) {
        cout << v << " ";
    }
    cout << endl;
}
