// https://codeforces.com/problemset/problem/1144/F
// https://www.youtube.com/watch?v=ZWd1SbJeBV0

/*
You are given a connected undirected graph consisting of n vertices and m edges. 
There are no self-loops or multiple edges in the given graph.
You have to direct its edges in such a way that the obtained directed graph does not contain any paths of length greater than 1 
*/

/*
If the graph is not bipartite then the answer is NO.
Otherwise the answer is YES.

We will now direct the edges from RED->BLUE or from BLUE->RED (anyway will work). 
This way our new graph will not contain any paths of length > 1 
(where the length of path is denoted as the number of traversed edges).

NOTE: Bipartite graphs can contain cycles of even weight only. Odd weight cycle graphs are non bipartite.
*/

const int N = 2e5+5;
int n, m;

vi g[N];
int vis[N], color[N];
vector<pair<int, int>> edges;

bool isBipartite(int u, int c) {
	vis[u] = 1;
	color[u] = c;
	for(int v: g[u]) {
		if(!vis[v]) {
			if(isBipartite(v, c^1) == false) return false;
		} else {
			if(color[v] == color[u]) return false;
		}
	}
	return true;
}

void solve() {
	int u, v;
	cin >> n >> m;
	f(i, m) {
		cin >> u >> v, g[u].pb(v), g[v].pb(u);
		edges.pb({u, v});
	}

	if (!isBipartite(1, 0)) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

	for(auto it: edges) {
		u = it.F, v = it.S;
		if(color[u] == 0) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
}
