// https://www.hackerrank.com/contests/101feb14/challenges/coloring-tree


// TLE Solution (Exact solution is by Merge smaller into bigger tree DP optimization technique)
const int N = 1e5+5;
int n, m;

// sqrt(n)
int BLK = 555;
 
struct query {
    int l, r, i;
    bool operator<(const query &o) const {
        if((l / BLK) != (o.l / BLK))
            return l < o.l;
        return ((l / BLK) & 1) ? r < o.r : r > o.r;
    }
};
 
query Q[N];
vector<int> g[N];
 
// strt time, terminating time, flat tree, color
int S[N], T[N], FT[2*N], col[N];
int nodeF[N];
unordered_map<int, int> colorF;
int ans[N];
int timer = 1;
int counter = 0;
 
void dfs(int u, int par) {
	S[u] = timer;
	FT[timer] = u;
	timer++;
	
	for(int v : g[u]) {
		if(v != par)
			dfs(v, u);
	}
	
	T[u] = timer;
	FT[timer] = u;
	timer++;
}
 
void add(int idx) {
	int node = FT[idx];
	int c = col[node];
	nodeF[node]++;
	
	if(nodeF[node] == 2) { 
		colorF[c]++;
		if(colorF[c] == 1) {
			counter++;
		}
	}
	
}
 
void remove(int idx) {
	int node = FT[idx];
	int c = col[node];
	nodeF[node]--;
	
	if(nodeF[node] == 1) {
		colorF[c]--;
		if(colorF[c] == 0) {
			counter--;
		}
	}
	
}
 
void solve() {
	int u, v, q, root;
	cin >> n >> q >> root;
 
	for(int i = 1; i <= n-1; i++) cin >> u >> v, g[u].pb(v), g[v].pb(u);
	for(int i = 1; i <= n; i++) cin >> col[i];
 
	dfs(root, -1);
 
	for(int i = 1; i <= q; i++) {
		cin >> u;
		Q[i].l = S[u];
		Q[i].r = T[u];
		Q[i].i = i;
	}
	// sort(Q, Q + q);
	sort(Q + 1, Q + q + 1);
 
	// int ML = 0 , MR = -1;
	int ML = 1 , MR = 0;
	for(int i = 1; i <= q; i++) {
		int L = Q[i].l;
		int R = Q[i].r;
 
 		// expansion
		while(ML > L)
		ML-- , add(ML);
 	
 		// expansion
		while(MR < R)
		MR++ , add(MR);
 
 		// contraction
		while(ML < L)
		remove(ML) , ML++;
 
 		// contraction
		while(MR > R)
		remove(MR) , MR--;
 
 
 		ans[Q[i].i] = counter;
	}
 
	for(int i = 1; i <= q; i++) cout << ans[i] << endl;
}
