// CSES Flight Routes
// https://cses.fi/problemset/task/1196/
// https://youtu.be/009PBKHXtyA
// https://usaco.guide/problems/cses-1196-flight-routes/solution

/*
Your task is to find the k shortest flight routes from city 1 to city n. A route can visit the same city several times.
Note that there can be several routes with the same price and each of them should be considered (see the example).
Input:
The first input line has three integers n, m, and k: the number of cities, the number of flights, and the parameter k. 
The cities are numbered 1,2,…,n. After this, the input has m lines describing the flights. 
Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. 
All flights are one-way flights. You may assume that there are at least k distinct routes from city 1 to city n.
Output:
Print k integers: the prices of the k cheapest routes sorted according to their prices.
Example
Input:
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1
Output:
4 4 7
Explanation: The cheapest routes are 1→3→4 (price 4), 1→2→3→4 (price 4) and 1→2→4 (price 7).
*/


/*
Solution:
This problem is about Single Source K Shortest Path whereas Dijkstra is about Single Source (One) Shortest Path.
In other words this is a more general case of Dijkstra.
Time Complexity: O(m*k*log(m*k))
Maintain a priority queue of the `k` best distances found for each vertex while applying normal Dijkstra. 
We'll iterate through the adjacency list of each vertex at most `k` times.
*/ 



const int N = 2e5+5;
int n, m;

vector<pair<int, int>> g[N];
priority_queue<int> bestDis[N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void solve() {
    int u, v, w, k;
    cin >> n >> m >> k;
 
    f(i, m) {
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }

    bestDis[1].push(0);
    pq.push({0, 1});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int cost = it.first;
        int u = it.second;
        
        // this is imp else TLE
        if (cost > bestDis[u].top()) {
            continue;
        }

        for (auto it: g[u]) {
            int v = it.first, w = it.second;
            int vCost = cost + w;

            if (bestDis[v].size() < k) {
                bestDis[v].push(vCost);
            } else if (vCost < bestDis[v].top()) {
                bestDis[v].pop();
                bestDis[v].push(vCost);
            }
            
            pq.push({vCost, v});
        }
    }

    vector<int> res;
    while (!bestDis[n].empty()) {
        res.pb(bestDis[n].top());
        bestDis[n].pop();
    }

    reverse(all(res));
    for (int x: res) cout << x << " ";
}
