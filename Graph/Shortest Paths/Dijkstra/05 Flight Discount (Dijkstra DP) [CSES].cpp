// https://cses.fi/problemset/task/1195/

/*
Question: (NOTE: edges are directed)
Your task is to find a minimum-price flight route from city 1 to city n. 
You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.

Input:
The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,...,n.
After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. 
Each flight is unidirectional. You can assume that it is always possible to get from city 1 to city n.
*/

/*
dp[i][0] = shortest distance from the start node to node i, without using the discount. 
dp[i][1] = shortest distance after using the discount.
*/

const int N = 2e5+5;
int n, m;

vector<pair<int,int>> g[N];
int dp[N][2];

void dijkstra() {
    int source = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = INF;
    }

    dp[source][0] = 0;
    // {distance, {node, j}}, where j = 0 or 1
    set<pair<int, pair<int, int>>> s;
    s.insert({dp[source][0], {source, 0}});

    while (!s.empty()) {
        int u = s.begin()->second.first;
        int j = s.begin()->second.second;
        s.erase(s.begin());

        for (auto x : g[u]) {
            int v = x.first, w = x.second;
            if (dp[v][j] > dp[u][j] + w) {
                s.erase({dp[v][j], {v, j}});
                dp[v][j] = dp[u][j] + w;
                s.insert({dp[v][j], {v, j}});
            }
            // now setting w = 0, if possible
            if (j < 1 && dp[v][j + 1] > dp[u][j] + (w / 2)) {
                s.erase({dp[v][j + 1], {v, j + 1}});
                dp[v][j + 1] = dp[u][j] + (w / 2);
                s.insert({dp[v][j + 1], {v, j + 1}});
            }
        }
    }

    int res = min(dp[n][0], dp[n][1]);
    cout << res << " ";
}

void solve() {
    int u, v, w;
    cin >> n >> m;

    f(i, m) {
        cin >> u >> v >> w, g[u].pb({v, w});
    }

    dijkstra();
} 






















const int N = 2e5+5;
int n, m;

vector<pair<int,int>> g[N];
int dp[N][2];

void dijkstra() {
    int source = 1, dest = n;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = INF;
    }

    dp[source][0] = 0;
    // {distance, {node, j}}, where j = 0 or 1
    set<pair<int, pair<int, int>>> s;
    s.insert({dp[source][0], {source, 0}});

    while (!s.empty()) {
        int u = s.begin()->second.first;
        int j = s.begin()->second.second;
        int cost = s.begin()->first;
        s.erase(s.begin());

        if(u == dest) {
            cout << cost << endl;
            return;
        }

        for (auto x : g[u]) {
            int v = x.first, w = x.second;
            if (dp[v][j] > dp[u][j] + w) {
                s.erase({dp[v][j], {v, j}});
                dp[v][j] = dp[u][j] + w;
                s.insert({dp[v][j], {v, j}});
            }
            // now setting w = 0, if possible
            if (j < 1 && dp[v][j + 1] > dp[u][j] + (w / 2)) {
                s.erase({dp[v][j + 1], {v, j + 1}});
                dp[v][j + 1] = dp[u][j] + (w / 2);
                s.insert({dp[v][j + 1], {v, j + 1}});
            }
        }
    }
}

void solve() {
    int u, v, w;
    cin >> n >> m;

    f(i, m) {
        cin >> u >> v >> w, g[u].pb({v, w});
    }

    dijkstra();
}  


























const int N = 2e5+5;
int n, m;

vector<pair<int,int>> g[N];
int dp[N][2];

using node = pair<int, pair<int, int>>;

void dijkstra() {
    int source = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = INF;
    }

    dp[source][0] = 0;
    // {distance, {node, j}}, where j = 0 or 1
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({dp[source][0], {source, 0}});

    while (!pq.empty()) {
        int u = pq.top().second.first;
        int j = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        if(cost > dp[u][j]) continue;

        for (auto x : g[u]) {
            int v = x.first, w = x.second;
            if (dp[v][j] > dp[u][j] + w) {
                dp[v][j] = dp[u][j] + w;
                pq.push({dp[v][j], {v, j}});
            }
            // now setting w = 0, if possible
            if (j < 1 && dp[v][j + 1] > dp[u][j] + (w / 2)) {
                dp[v][j + 1] = dp[u][j] + (w / 2);
                pq.push({dp[v][j + 1], {v, j + 1}});
            }
        }
    }

    int res = min(dp[n][0], dp[n][1]);
    cout << res << " ";
}

void solve() {
    int u, v, w;
    cin >> n >> m;

    f(i, m) {
        cin >> u >> v >> w, g[u].pb({v, w});
    }

    dijkstra();
} 
