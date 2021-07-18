// It's a dynamic programming solution

// single source shortest path (includes negative edges)
// this is directed version
// For questions related to visiting atleast K edges only consider relaxation from 0 to K only instead of (n-1)  

// drawback: If there is a cycle with negative weight, it fails
// it will work fine for cycles of positive weight

// therefore after relaxing >= n times, then also path weights are changing that means there is a negative weight cycle in the graph

// https://leetcode.com/problems/cheapest-flights-within-k-stops/



void solve() {
    ll u, v, w, src;
    cin >> n >> m;
    vector < vector < ll >> g;
    f(i, m) {
        cin >> u >> v >> w;
        vector < ll > temp;
        temp.pb(u);
        temp.pb(v);
        temp.pb(w);
        g.pb(temp);
    }
    cin >> src;
    vector < int > dis(n, INT_MAX);
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++) {
        vector < int > tempDis(dis);
        for (auto x: g) {
            int u = x[0];
            int v = x[1];
            int d = x[2];
            tempDis[v] = min(tempDis[v], dis[u] + d);
        }
        dis = tempDis;
    }
    for (int i = 0; i < n; i++) {
        cout << dis[i] << " ";
    }
}
