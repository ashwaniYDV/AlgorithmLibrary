// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
// https://github.com/Ashishgup1/Competitive-Coding/blob/master/Prim's%20MST.cpp

// Pepcoding = https://youtu.be/Vw-sktU1zmc



const int N = 1e5 + 5;
int n, m;
vector < pair < int, int >> g[N];

int prims(int root) {
    vector < int > dist(n + 1, INF);
    vector < int > parent(n + 1, -1);
    vector < int > vis(n + 1, 0);

    set < pair < int, int > > s;
    s.insert({0, root});
    dist[root] = 0;

    int cost = 0;

    while (!s.empty()) {
        auto x = * (s.begin());
        s.erase(x);
        cost += x.first;
        int u = x.second;
        vis[u] = 1;

        for (auto y: g[u]) {
            int v = y.first;
            int weight = y.second;

            if (dist[v] > weight) {
                if (vis[v]) continue;

                s.erase({dist[v], v});
                dist[v] = weight;
                s.insert({dist[v], v});
                parent[v] = u;
            }
        }
    }

    return cost;
}


void solve() {
    int u, v, w, x, y;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    // Taking root of MST as 1
    int root = 1;
    cout << prims(root);
}



// I dont know why in priority_queue implementation MS tree is coming same but cost is coming differet
