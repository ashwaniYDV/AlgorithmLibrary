// https://cses.fi/problemset/task/1680/
// https://youtu.be/9HMawd5jn9A

/*
Problem:
Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. 
Of course, Uolevi wants to choose a trip that has as many cities as possible.
Uolevi wants to fly from city 1 to city n so that he visits the maximum number of cities. 
You are given the list of possible flights, and you know that there are no directed cycles in the flight network.

Input:
The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n.
After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. 
Each flight is a one-way flight.

Output:
First print the maximum number of cities on the route. After this, print the cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
*/


/*
Dijkstra assumes monotonicity. Monotonicity means a function is either non decreasing or non increasing. 
Dijkstra works when distance/cost is monotonic i.e. all positive edges or all negative edges. But there must be absolutely no negative cycles.
This problem satisfies monotonicity.
*/



// Method 1: Using Topological Sort DP



// Method 2

const int N = 2e5+5;
int n, m;
int dis[N], parent[N];
vector<pair<int, int> > g[N];
 
void dijkstra(int source, int destination) {
    for(int i = 1; i <= n; i++) {
        dis[i] = -INF;
        parent[i] = -1;
    }
 
    dis[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
 
    while(!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        int u = x.second;
 
        for(auto it: g[u]) {
            int v = it.first;
            int w = it.second;
            if(dis[v] < dis[u] + w) {
                s.erase({dis[v], v});
                dis[v] = dis[u] + w;
                s.insert({dis[v], v});
                parent[v] = u;
            }
        }
    }
 
    int node = destination;
    vector<int> res;
    while(parent[node] != -1) {
        res.push_back(node);
        node = parent[node];
    }
    res.push_back(source);

    if(res.size() == 1) {
        cout << "IMPOSSIBLE\n";
    }

    cout << res.size() << endl;

    reverse(res.begin(), res.end());
    for(auto i: res) {
        cout << i << " ";
    }
}
 
void solve() {
    int u, v, w;
    cin >> n >> m;
    f(i, m) {
        cin >> u>> v;
        g[u].push_back({v, 1});
    }
    dijkstra(1, n);
}
