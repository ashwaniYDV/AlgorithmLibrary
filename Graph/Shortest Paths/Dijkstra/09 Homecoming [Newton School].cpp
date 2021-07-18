// https://my.newtonschool.co/playground/code/lhy8675e8tpa/

/*
There are n cities in the universe and our beloved Spider-Man is in city 1. 
He doesn't like to travel by vehicles, so he shot webs forming edges between some pairs of cities. 
Eventually, there were m edges and each had some cost associated with it.

Spider-Man now defines the cost of a path p from cities p1 to pk as w1 + 2w2 + 3w3 . . . + (k-1)*wk-1, where wi is the cost of an edge from pi to pi+1.
Thus, the minimum distance between cities i and j is the smallest cost of a path starting from i and ending at j.

Find the minimum distance from city 1 to all the cities i (1 ≤ i ≤ n). If there exists no way to go from city 1 to city i, print -1.

Note:
All the edges are bidirectional. There may be multiple edges and self-loops in the input.
Input
The first line contains two space separated integers n and m - the number of nodes and edges respectively.
The next m lines contain three-space separated integers x, y, w - representing an edge between x and y with cost w.

Constraints:
1 ≤ n ≤ 3000
0 ≤ m ≤ 10000
1 ≤ x, y ≤ n
1 ≤ w ≤ 10^9

Output:
Output n lines. In the ith line, output the minimum distance from city 1 to the ith city. If there exists no such path, output -1.



Sample Input:
6 5
2 4 3
2 3 4
2 1 2
2 5 6
1 5 2

Sample Output:
0
2
10
8
2
-1

Explanation:
Shortest path from 1 to 3 is (1->2->3)  with total weight= 1*2+2*4=10
Shortest path from 1 to 5 is (1->5)  with total weight= 1*2=2
There doesn't exist any path from 1 to 6 so print -1
*/





const int N = 1e5+5;
int n, m;

int dis[N];
vector<pair<int, int> > g[N];
 
void dijkstra(int source) {
    for(int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
 
    dis[source] = 0;
    set<vector<int>> s;
    // {cost, u, k}
    s.insert({0, source, 0});
 
    while(!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        int u = x[1];
        int k = x[2];
 
        for(auto it: g[u]) {
            int v = it.first;
            int w = it.second;
            if(dis[v] > dis[u] + w * (k + 1)) {
                s.erase({dis[v], v, k + 1});
                dis[v] = dis[u] + w * (k + 1);
                s.insert({dis[v], v, k + 1});
            }
        }
    }
 
    loop(i, 1, n) cout << (dis[i] == INF ? -1 : dis[i]) << endl;
}
 
void solve() {
    int u, v, w;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> u>> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dijkstra(1);
}
