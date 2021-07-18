#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;
vector<int> g[N];

void dfs(int u, int par, int d, vector<int>& depth) {
	depth[u] = d;
	for(int v: g[u]) {
		if(v == par) continue;
		dfs(v, u, d + 1, depth);
	}
}

int diameterOfTreeDFS() {
	vector<int> depth(n+1, 0);
	dfs(1, -1, 0, depth);
	int pos = 0, mx = 0;
	for(int i = 1; i <= n; i++) {
		if(depth[i] > mx) {
			mx = depth[i];
			pos = i;
		}
	}
	depth.resize(n+1, 0);
	dfs(pos, -1, 0, depth);

	int diameter = 0;
	for(int i = 1; i <= n; i++) {
		diameter = max(diameter, depth[i]);
	}

	return diameter;
}

int main() {
    int u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    }

    cout << diameterOfTreeDFS();
}









#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m;
vector<int> g[N];

pair<int, int> bfs(int root) {
	vector<int> depth(n+1, 0);
	queue<int> q;
	q.push(root);
	depth[root] = 0;
 
	while(!q.empty()) {
		int u = q.front();
        q.pop();
 
		for(int v: g[u]) {
			if(depth[v] || v == root) continue;
            depth[v] = depth[u] + 1;
            q.push(v);
		}
	}

	int pos = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		if(depth[i] > mx) {
			mx = depth[i];
			pos = i;
		}
	}

	return {pos, mx};
}

int diameterOfTreeBFS() {
	pair<int, int> x = bfs(1);
	int diameter = bfs(x.first).second;
	return diameter;
}

int main() {
    int u, v;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    }

    cout << diameterOfTreeBFS();
}