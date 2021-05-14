/*
No cycle or Even cycle graph -> Bipartite
Odd cycle graph -> Not-Bipartite
*/


const int N = 2e5+5;
int n, m;

vi g[N];
int vis[N], color[N];

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
	}

	bool check = true;
	loop(i, 1, n) {
		if(!vis[i]) 
			check = check && isBipartite(i, 1);
	}

	if(check)
		cout<<"Graph is bipartite.";
	else
		cout<<"Graph is not bipartite.";

}
