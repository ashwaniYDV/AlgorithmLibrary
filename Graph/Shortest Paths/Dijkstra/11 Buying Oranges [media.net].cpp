/*
You are given n cities (1...n) with m bidirectional roads. Price[i] = price of buying oranges at the i'th city.
For each city you have to calculate the minimum amount of money required to buy oranges and return back to the city.
(You have to buy oranges in exactly one city in the path from city to other cities and then coming back yo the city. 
You can buy oranges on the same city without going anywhere else if this is the minimum cost.)

You have to follow the given constraints:

Each bidirectional road has a weight and tax associated with it.
You you are moving empty handed from u->v then cost of travelling is weight of u->v.
If you you are travelling with oranges from u->v then cost of travelling is (weight * tax) of u->v.
*/


/*
Mangesh solution:

Ek 0 node add krdo. 
Ab 0 -> 1, 0 -> 2, ..., 0 -> n undirected edges add krdo with cost = price[i] 
Given undirected edges add kardo u -> v with cost = (weight + (weight * tax))
(weight for forward path when no oranges are bought, weight * tax for backward journey when oranges are bough at some city).
Ab 0 se Dijkstra lga do aa gya tha aise mera shi.
*/

const int N = 1e5+5;
int n, m;

vector<pair<int, int>> g[N];
int price[N], dis[N];
 
void dijkstra(int source) {
    for(int i = 0; i <= n; i++) dis[i] = INF;
 
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
            if(dis[v] > dis[u] + w) {
                s.erase({dis[v], v});
                dis[v] = dis[u] + w;
                s.insert({dis[v], v});
            }
        }
    }

    loop(i, 1, n) cout << dis[i] << " ";
}

void solve() {
    int u, v, w, tax;
    cin >> n >> m;

    loop(i, 1, n) cin >> price[i];

    loop(i, 1, m) {
        cin >> u >> v >> w >> tax;

        g[u].push_back({v, w + w * tax});
        g[v].push_back({u, w + w * tax});

        // add extra central node 0
        g[0].pb({i, price[i]});
        g[i].pb({0, price[i]});
    }

    dijkstra(0);
}


/*
Input:
6 7
50 30 12 60 55 9
1 2 3 15 
1 3 4 6
2 4 5 11
2 5 7 19
4 5 8 4
3 6 6 7
5 6 1 1

Output:
40 30 12 51 11 9 
*/
