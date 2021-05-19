// https://youtu.be/_aWooet7O_4
// https://cp-algorithms.com/graph/edmonds_karp.html


int n;
vector<vector<int>> capacity;
vector<vector<int>> g;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v : g[u]) {
            if (parent[v] == -1 && capacity[u][v]) {
                parent[v] = u;
                int new_flow = min(flow, capacity[u][v]);
                if (v == t)
                    return new_flow;
                q.push({v, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void solve() {
    int u, v, x, m;
    cin >> n >> m;
    capacity.assign(n, vector<int>(n, 0));
    g.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> x;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        capacity[u][v] += x;
    }
    cout << maxflow(0, n - 1);
}
