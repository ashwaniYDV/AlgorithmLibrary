// https://cses.fi/problemset/task/1679

/* 
We just have to check cycle in directed graph for no topo sort case.
Directed Acyclic Graphs (DAG) always have a valid topological sort (NOTE: the answer is not unique)
*/


const int N = 2e5+5;
int n, m; 

vi g[N];
int color[N];
vector<int> res; // we can use stack as well (since we have to print reverse order)

int impossible = 0;

void dfs(int u) {
	color[u] = 1;

	for(int v: g[u]) {
		if(color[v] == 1) {
			impossible = 1;
			return;
		}
		if(color[v] == 0) {
			dfs(v);
		}
	}

	color[u] = 2;
	res.pb(u);
}

void solve() {
	int u, v;
	cin >> n >> m;
	f(i, m) {
		cin >> u >> v;
		g[u].pb(v);
	}
	
	loop(i, 1, n) {
		if(color[i] == 0) {
			dfs(i);
			if(impossible) {
				cout << "IMPOSSIBLE\n";
				return;
			}
		}
	}

	reverse(all(res));

	for(int x: res) cout << x << " ";
}
