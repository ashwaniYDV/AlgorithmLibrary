// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-revisited-9e1091ea/
// Shortest Path Revisited
// https://unacademy.com/class/tricky-variations-of-dijkstra-algorithm/TA76JSGL
// Pulkit Chhabra Unacademy

/*
Problem:
In the country of HackerEarth, there are N cities and M bi-directional roads. 
We need to transport essential items from City 1  to all other cities. (There exists a path always)

But every road has some positive amount of Toll Charge associated with it say C (it is not same for all roads). 
We need to find the minimum amount of charge that it required to deliver essential items for each city.

Fortunately, to our rescue we have K special offers, which means while travelling from City 1 to any other city 
we can select at-most K roads and we will not be charged for using those roads.

Can you now find the minimum charge that we have to pay to deliver essential items for each city.

(Remember we require to provide answers for each destination city separately i.e. we have K offers for every city and not as a whole)
*/

/*
Approach:

Since the value of K is small, we can use Dynamic Programming Here.
We will modify Dijikstra Algorithm to incorporate at most K special offers.

At every step of Dijikstra Algorithm, we can decide whether we wish to use a special offer or not.
So, recurrence can be like , where dp[i][j] represents the minimum charge required to reach city i if we use j special offers.

At a particular iteration of Dijikstra, assume we have node u currently, so
Case 1: If we do not use offer
dp[v][j] = weight of edge(u, v) + dp[u][j]

Case 2: If we use offer (i.e. weight of edge(u, v) is set as 0 by using offer)
dp[v][j+1] = dp[u][j]
*/





// Method 1
const int N = 5e5+5;
int n, m;
vector<pair<int,int>> g[N];
int k;
// dp[i][j] = the minimum charge required to reach city i from source if we use j special offers
int dp[N][20];

void dijkstra() {
    int source = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            dp[i][j] = INF;
    }

    dp[source][0] = 0;
    // {distance, {node, j}}, where j <= k
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
            if (j < k && dp[v][j + 1] > dp[u][j]) {
                s.erase({dp[v][j + 1], {v, j + 1}});
                dp[v][j + 1] = dp[u][j];
                s.insert({dp[v][j + 1], {v, j + 1}});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int res = INF;
        for (int j = 0; j <= k; j++) {
            res = min(res, dp[i][j]);
        }
        cout << res << " ";
    }
}
 
void solve() {
    int u, v, w;
    cin >> n >> m >> k;

    f(i, m) {
        cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    dijkstra();
}

























// Method 2
const int N = 5e5+5;
int n, m;
vector<pair<int,int>> g[N];
int k;
int dp[N][20];

void dijkstra() {
    int source = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            dp[i][j] = INF;
    }

    dp[source][0] = 0;
    // {distance, node, j}, where j <= k
    set<vector<int>> s;
    s.insert({dp[source][0], source, 0});

    while (!s.empty()) {
        auto it = *s.begin();
        int u = it[1];
        int j = it[2];
        s.erase(s.begin());

        for (auto x : g[u]) {
            int v = x.first, w = x.second;
            if (dp[v][j] > dp[u][j] + w) {
                s.erase({dp[v][j], v, j});
                dp[v][j] = dp[u][j] + w;
                s.insert({dp[v][j], v, j});
            }
            // now setting w = 0, if possible
            if (j < k && dp[v][j + 1] > dp[u][j]) {
                s.erase({dp[v][j + 1], v, j + 1});
                dp[v][j + 1] = dp[u][j];
                s.insert({dp[v][j + 1], v, j + 1});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int res = INF;
        for (int j = 0; j <= k; j++) {
            res = min(res, dp[i][j]);
        }
        cout << res << " ";
    }
}
 
void solve() {
    int u, v, w;
    cin >> n >> m >> k;

    f(i, m) {
        cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    dijkstra();
}






























// Method 3
const int N = 5e5+5;
int n, m;

vector<pair<int, int>> g[N];
int k;
int dp[N][20];

void dijkstra() {
    int source = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            dp[i][j] = INF;
    }

    dp[source][0] = 0;

    // {distance, {node, j}}, where j <= k
    priority_queue < pair<int, pair<int, int>> , vector < pair<int, pair<int, int>>> , greater < pair<int, pair <int, int>>> > pq;
    pq.push({dp[source][0], {source, 0}});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int u = it.second.first;
        int j = it.second.second;

        for (auto x: g[u]) {
            int v = x.first, w = x.second;
            if (dp[v][j] > dp[u][j] + w) {
                dp[v][j] = dp[u][j] + w;
                pq.push({dp[v][j], {v, j}});
            }
            // now setting w = 0, if possible
            if (j < k && dp[v][j + 1] > dp[u][j]) {
                dp[v][j + 1] = dp[u][j];
                pq.push({dp[v][j + 1], {v, j + 1}});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int res = INF;
        for (int j = 0; j <= k; j++) {
            res = min(res, dp[i][j]);
        }
        cout << res << " ";
    }
}

void solve() {
    int u, v, w;
    cin >> n >> m >> k;

    f(i, m) {
        cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    dijkstra();
}

































// Method 4
const int N = 5e5+5;
int n, m;

vector<pair<int, int>> g[N];
int k;
int dp[N][20];

void dijkstra() {
    int source = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            dp[i][j] = INF;
    }

    dp[source][0] = 0;

    // {distance, {node, j}}, where j <= k
    priority_queue < pair<int, pair<int, int>> , vector < pair<int, pair<int, int>>> , greater < pair<int, pair <int, int>>> > pq;
    pq.push({dp[source][0], {source, 0}});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int u = it.second.first;
        int j = it.second.second;
        int cost = it.first;

        if(cost > dp[u][j]) continue;

        for (auto x: g[u]) {
            int v = x.first, w = x.second;
            if (dp[v][j] > dp[u][j] + w) {
                dp[v][j] = dp[u][j] + w;
                pq.push({dp[v][j], {v, j}});
            }
            // now setting w = 0, if possible
            if (j < k && dp[v][j + 1] > dp[u][j]) {
                dp[v][j + 1] = dp[u][j];
                pq.push({dp[v][j + 1], {v, j + 1}});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int res = INF;
        for (int j = 0; j <= k; j++) {
            res = min(res, dp[i][j]);
        }
        cout << res << " ";
    }
}

void solve() {
    int u, v, w;
    cin >> n >> m >> k;

    f(i, m) {
        cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    dijkstra();
}
