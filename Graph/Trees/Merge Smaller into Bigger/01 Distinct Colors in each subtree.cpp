// https://www.hackerrank.com/contests/101feb14/challenges/coloring-tree

/*
// https://cses.fi/problemset/task/1139/
You are given a rooted tree consisting of n nodes. The nodes are numbered 1,2,...,n, and node 1 is the root. Each node has a color.
Your task is to determine for each node the number of distinct colors in the subtree of the node.
*/

/*
What optimization we are going to use?
You might have already studied it but we can also apply on tree as well. The optimization is the path optimization that we studied in DSU.
There are two path optimizations in DSU and one of them is Union by Rank. This is the exact optimization we are going to apply here. 
*/

/*
## Merging many sets in O(nlogn) amortized (i.e. cannot revert it).
If you have some sets and you often need to merge some of theme, you can do it in naive way 
but in such manner that you always move elements from the smaller one to the larger. 
Thus every element will be moved only O(logn) times since its new set always will be at least twice as large as the old one. 
Some versions of DSU are based on this trick. Also you can use this trick when you merge sets of vertices in subtrees while having dfs.
*/




// Method: O(nlogn)
// Merge Smaller into Bigger
const int N = 1e5+5;
int n, m;
vi g[N];
int color[N];
set<int> *st[N];
int res[N];

void dfs(int u, int par) {
	int mx = 0;
	int mxNode = -1;
	
	for(int v : g[u]) {
		if(v == par) continue;
		dfs(v , u);
		if(st[v]->size() > mx)
			mx = st[v]->size(), mxNode = v;
	}
	
	if(mxNode == -1) 
		st[u] = new set<int>();
	else
		st[u] = st[mxNode];
	
	st[u]->insert(color[u]);
	
	for(int v : g[u]) {
		if(v != par && v != mxNode) {
			for(int c : *st[v])
				st[u]->insert(c);
		}
	}
	
	res[u] = st[u] -> size();
}

void solve() {
	int u, v, q, root;
    cin >> n >> q >> root;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    for(int i = 1; i <= n; i++) 
    	cin >> color[i];

    dfs(root, -1);

    for(int i = 0; i < q; i++) {
    cin >> u; 
    	cout << res[u] << "\n";
    }

}































// Naive Method: O(n^2.logn) 
const int N = 2e5+5;
int n, m;

vi g[N];
int color[N];
set<int> uniqSubtreeCol[N];

void dfs(int u, int par) {
    uniqSubtreeCol[u].insert(color[u]);

    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u);

        for(int x: uniqSubtreeCol[v])
            uniqSubtreeCol[u].insert(x);
    }
}

void solve() {
    int u, v, q, root;
    cin >> n >> q >> root;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    for(int i = 1; i <= n; i++) 
        cin >> color[i];

    dfs(root, -1);

    for(int i = 0; i < q; i++) { 
        cin >> u;
        cout << uniqSubtreeCol[u].size() << "\n";
    }

}
