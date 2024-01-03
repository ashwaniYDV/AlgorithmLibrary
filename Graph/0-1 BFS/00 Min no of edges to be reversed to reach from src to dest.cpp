// https://youtu.be/Xqq7uELiYnE

/*
Problem:
Given a directed graph consisting of nodes from 1 to n.
Find the minimum number of edges to be reversed so that we can go from src = 1 to dest = n.

Solution:
If there is a edge from u -> v, add it as egde weight of 0
Also add a reversed edge from v -> u, with weight of 1.
*/

const int N = 2e5+5;
int n, m;

vector<pair<int, int>> g[N];

void bfs01(int src, int dest) {
    vector<int> dis(n+1, INF);
    deque<int> dq;
    dq.push_front(src);
    dis[src] = 0;

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto edge : g[u]) {
            int v = edge.first, w = edge.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
            }
        }
    }

    cout << dis[dest] << endl;
}

void solve() {
    int x, y, z;
    cin >> n >> m;
    f(i, m) {
        cin >> x >> y;
        g[x].pb({y, 0});
        g[y].pb({x, 1});
    }

    bfs01(1, n);
}


/*
Input:
7 7
1 2
3 2
3 4
7 4
7 5
5 6
6 2

Output:
2
*/
