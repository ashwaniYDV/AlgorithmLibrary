// https://cp-algorithms.com/graph/finding-cycle.html
// https://cses.fi/problemset/task/1678/

/*
Byteland has n cities and m flight connections. Your task is to design a round trip that begins in a city, 
goes through one or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.

Input:
The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n.
Then, there are m lines describing the flights. Each line has two integers a and b: there is a flight connection from city a to city b. 
All connections are one-way flights from a city to another city.

Output:
First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
*/

const int N = 2e5+5;
int n, m;

vi g[N];
int color[N], parent[N];
int cycle_start, cycle_end;

bool dfs(int u) {
    color[u] = 1;
    for (int v: g[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (color[v] == 1) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v, g[u].pb(v);
    }

    loop(i, 1, n) {
        color[i] = 0;
        parent[i] = -1;
    }
    cycle_start = -1;

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && dfs(i)) break;
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
