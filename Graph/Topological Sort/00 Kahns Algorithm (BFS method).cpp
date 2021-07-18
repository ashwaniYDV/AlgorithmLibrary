// https://cses.fi/problemset/task/1679/
// Course Schedule - CSES

/*
Notes:
-----
* Topological sorting for Directed Acyclic Graph (DAG) is a 
  linear ordering of vertices such that for every directed edge u -> v, 
  vertex u comes before v in the ordering. 
* Topological Sorting for a graph is not possible if the graph is not a DAG.
*/


const int N = 2e5+5;
int n, m; 
int in[N];
vi g[N];
vector<int> res;

// sorted order
void kahn_in_sorted_order(int n) {
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=1; i<=n; i++) {
		if(in[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int u = q.top();
		q.pop();
		res.pb(u);
		for(int v: g[u]){
			in[v]--;
			if(in[v] == 0) q.push(v);
		}
	}

	if((int)res.size() < n) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for(int x: res) {
		cout << x << " ";
	}
}

// any order
void kahn(int n) {
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(in[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int u = q.front();
		q.pop();
		res.pb(u);
		for(int v: g[u]){
			in[v]--;
			if(in[v] == 0) q.push(v);
		}
	}

	if((int)res.size() < n) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for(int x: res) {
		cout << x << " ";
	}
}

void solve() {
	int u, v;
	cin >> n >> m;
	f(i, m) {
		cin >> u >> v;
		g[u].pb(v);
		in[v]++;
	}
	kahn(n);
}
