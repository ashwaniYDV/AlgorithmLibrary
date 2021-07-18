// https://github.com/my3m/shortest-path-fuel-constraints
// https://stackoverflow.com/questions/22061009/a-shortest-path-with-fuel-constraints

/*
You are given a weighted connected graph of cities with all edges having positive weights. 
Some cities (vertices) have a gas station whereas some don’t. 
You have a vehicle with the tank capacity of C. That is, with full tank, the car can travel for C units of distance. 
Assume that any city with a gas station can fill the vehicle's tank to full. 
Find out the shortest path between the a given source and a given destination. 
Assume that you start with a full tank.
*/

const int N = 1e3+5;
int n, m;

int dis[N][100];
vector<pair<int, int> > g[N];
map<int, int> isFuelCity;
int fuelStationCapacity;
 
void dijkstra(int src, int dest) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= fuelStationCapacity; j++) {
            dis[i][j] = INF;
        }
    }

    dis[src][fuelStationCapacity] = 0;
    // dis[src][0] = 0;
    set<vector<int>> s;
    s.insert({0, src, fuelStationCapacity});
 
    while(!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        int cost = x[0], u = x[1], curFuel = x[2];

        // since curFuel is updated if it is petrol station, thus update dis[u][curFuel] also
        if(isFuelCity[u]) {
            curFuel = fuelStationCapacity;
            dis[u][curFuel] = min(dis[u][curFuel], cost);
        }

        // dis[u][curFuel] = min(dis[u][curFuel], cost);
 
        for(auto it: g[u]) {
            int v = it.first;
            int w = it.second;
            if(curFuel < w) continue;

            if(dis[v][curFuel - w] > dis[u][curFuel] + w) {
                s.erase({dis[v][curFuel - w], v, curFuel - w});
                dis[v][curFuel - w] = dis[u][curFuel] + w;
                s.insert({dis[v][curFuel - w], v, curFuel - w});
            }
        }
    }
 
    int res = INF;
    for(int i = 0; i <= fuelStationCapacity; i++) {
        res = min(res, dis[dest][i]);
    }
    cout << res << endl;
}
 
void solve() {
    int u, v, w;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    cin >> fuelStationCapacity;

    cin >> m;
    f(i, m) cin >> u, isFuelCity[u] = 1;

    dijkstra(1, 2);
    dijkstra(1, 6);
    dijkstra(1, n);
}




/*
Input:
6 7
1 2 13
1 3 5
1 4 12
1 5 11
2 4 6
3 5 10
5 6 2
12
3
1 3 4

Output:
18
17
17
*/
