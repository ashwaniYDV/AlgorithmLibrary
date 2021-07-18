// Method 1 (Generalized)
const int N = 1e5+5;
int n, m;

const int height = (int)ceil(log2(N));
vector<pair<int, int>> g[N];
int level[N];
vector<vector<int>> LCA, minWeight;

void dfs(int u, int par, int lvl, int wt) {
    level[u] = lvl;
    LCA[u][0] = par;
    minWeight[u][0] = wt;

    for (auto it: g[u]) {
        int v = it.F, w = it.S;
        if (v != par) {
            dfs(v, u, lvl + 1, w);
        }
    }
}

void init() {
    dfs(1, -1, 0, INF);

    for(int i = 1; i <= height; i++) {
        for(int node = 1; node <= n; node++) {
            int parNode = LCA[node][i - 1];
            if(parNode != -1) {
                LCA[node][i] = LCA[parNode][i - 1];
                minWeight[node][i] = min(minWeight[parNode][i - 1], minWeight[node][i - 1]);
            } else {
                LCA[node][i] = -1;
                minWeight[node][i] = INF;
            }
        }
    }
}

int getLCA(int a, int b) {
    if(level[a] > level[b]) swap(a, b);

    int mn = INF;

    int d = level[b] - level[a];
    for(int i = height-1; i >= 0; i--) {
        if(d & (1 << i)) {
            mn = min(mn, minWeight[b][i]);
            b = LCA[b][i];
        }
    }

    if (a == b) return mn;

    for(int i = height - 1; i >= 0; i--) {
        if (LCA[a][i] != LCA[b][i]) {
            mn = min(mn, minWeight[a][i]);
            a = LCA[a][i];
            mn = min(mn, minWeight[b][i]);
            b = LCA[b][i];
        }
    }

    return min({mn, minWeight[a][0], minWeight[b][0]});
}

void solve() {
    int u, v, w, q;
    cin >> n;

    LCA.resize(N, vector<int>(height+1, -1));
    minWeight.resize(N, vector<int>(height+1, INF));

    f(i, n-1) {
        cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    init();

    cin >> q;
    while(q--) {
        cin >> u >> v;
        cout << getLCA(u, v) << endl;
    }
}

/*
Input:
9
1 2 3
1 3 4
2 4 1
2 5 5
3 6 2
3 7 3
1 8 1
8 9 4
5
1 3
4 6
2 5
1 7
3 8

Output:
4
1
5
3
1
*/































// Method 2 (Generalized)
const int N = 1e5+5;
int n, m;

const int height = (int)ceil(log2(N));
vector<pair<int, int>> g[N];
int level[N];
vector<vector<int>> LCA, minWeight;

void dfs(int u, int par, int lvl) {
    level[u] = lvl;
    LCA[u][0] = par;

    for (auto it: g[u]) {
        int v = it.F, w = it.S;
        if (v != par) {
            dfs(v, u, lvl + 1);
        }
    }
}

void build(int u, int par, int wt){
    LCA[u][0] = par;
    minWeight[u][0] = wt;
    
    for(int i = 1; i < height; i++) {
        int parNode = LCA[u][i - 1];
        if(parNode != -1) {
            LCA[u][i] = LCA[parNode][i - 1];
            minWeight[u][i] = min(minWeight[parNode][i - 1], minWeight[u][i - 1]);
        } else {
            LCA[u][i] = -1;
            minWeight[u][i] = INF;
        }
    }
    for(auto it: g[u]) {
        int v = it.F, w = it.S;
        if(v != par) {
            build(v, u, w);
        }
    }
}

int getLCA(int a, int b) {
    if(level[a] > level[b]) swap(a, b);

    int mn = INF;

    int d = level[b] - level[a];
    for(int i = height-1; i >= 0; i--) {
        if(d & (1 << i)) {
            mn = min(mn, minWeight[b][i]);
            b = LCA[b][i];
        }
    }

    if (a == b) return mn;

    for(int i = height - 1; i >= 0; i--) {
        if (LCA[a][i] != LCA[b][i]) {
            mn = min(mn, minWeight[a][i]);
            a = LCA[a][i];
            mn = min(mn, minWeight[b][i]);
            b = LCA[b][i];
        }
    }

    return min({mn, minWeight[a][0], minWeight[b][0]});
}

void solve() {
    int u, v, w, q;
    cin >> n;

    LCA.resize(N, vector<int>(height+1, -1));
    minWeight.resize(N, vector<int>(height+1, INF));

    f(i, n-1) {
        cin >> u >> v >> w, g[u].pb({v, w}), g[v].pb({u, w});
    }

    dfs(1, -1, 0);
    build(1, -1, INF);

    cin >> q;
    while(q--) {
        cin >> u >> v;
        cout << getLCA(u, v) << endl;
    }
}






































// Method 3: Sameer Raj
#include<bits/stdc++.h>	
#define pb push_back
#define endl "\n"
#define F first
#define S second 
#define inf 2e9    
using namespace std;

const int N = 3e5 + 5;
const int up = 20;
int level[N];
int lca[N][up], min_wt[N][up];
vector<pair<int, int>> g[N];

void fill(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < up; j++)
			lca[i][j] = 1, min_wt[i][j] = inf;
}

void dfs(int v, int par, int depth = 0){
	level[v] = depth;
	for(auto z: g[v]){
		auto to = z.F;
		if(to == par)
			continue;
		dfs(to, v, depth + 1);
	}
}

void build(int v, int par, int wt){
	lca[v][0] = par;
	min_wt[v][0] = wt;
	for(int i = 1; i < up; i++){
		lca[v][i] = lca[lca[v][i - 1]][i - 1];
		min_wt[v][i] = min(min_wt[lca[v][i - 1]][i - 1], min_wt[v][i - 1]);
	}
	for(auto z: g[v]){
		auto to = z.F;
		if(to == par)
			continue;
		build(to, v, z.S);
	}
}

int retlca(int a, int b){
	if(level[a] > level[b])
		swap(a, b);
	int lev_diff = level[b] - level[a];
	int mn = inf;
	for(int i = up - 1; i >= 0; i--){
		if(!(lev_diff & (1 << i)))
			continue;
		mn = min(mn, min_wt[b][i]);
		b = lca[b][i];
	}
	if(a == b){
		return mn;
	}
	for(int i = up - 1; i >= 0; i--){
		if(lca[a][i] == lca[b][i])
			continue;

		mn = min(mn, min_wt[a][i]);
		a = lca[a][i];
		mn = min(mn, min_wt[b][i]);
		b = lca[b][i];
		
	}
	return min({mn, min_wt[a][0], min_wt[b][0]});
}

main() {	
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill();
	int n, m;
	cin >> n >> m;
	for(int i = 0, x, y, w; i < m; i++){
		cin >> x >> y >> w;
		g[x].pb({y, w});
		g[y].pb({x, w});
	}
	dfs(1, 1);
	build(1, 1, inf);
	int q;	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << retlca(a, b);
		cout << endl;
	}
}
