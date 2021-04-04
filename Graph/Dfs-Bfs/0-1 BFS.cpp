// https://cp-algorithms.com/graph/01_bfs.html
// https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/

const int N = 300000+5;
int n, m;
vector<pair<int, int>> g[N];

void bfs_01(int src) {
	vector<int> dis(n+1, INF);
	deque<int> dq;
	dq.push_front(src);
	dis[src] = 0;

	while (!dq.empty()) {
	    int u = dq.front();
	    dq.pop_front();

	    for (auto edge : g[u]) {
	        int v = edge.first;
	        int w = edge.second;
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

	for (int i = 0; i <= n; i++) {
		cout << src << " - " << i << " : dis = " << dis[i] << endl;
	}
}

void solve() {
	int u, v, w;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	bfs_01(0);
}

/*
Input:
8 13
0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1
4 5 1
5 6 1
6 7 1
7 8 1

Output:
0 - 0 : dis = 0
0 - 1 : dis = 0
0 - 2 : dis = 1
0 - 3 : dis = 1
0 - 4 : dis = 2
0 - 5 : dis = 1
0 - 6 : dis = 2
0 - 7 : dis = 1
0 - 8 : dis = 2
*/
