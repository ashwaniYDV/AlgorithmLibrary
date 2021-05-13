// https://codeforces.com/blog/entry/57593
// https://cses.fi/problemset/task/2079/
// https://youtu.be/0DJwKePjweQ

/*
Centroid of a Tree is a node which if removed from the tree would split it into a 'forest', 
such that any tree in the forest would have at most half the number of vertices in the original tree. 

NOTE: 
1) A tree may have one centroid or may have two centroids (at most 2 centroids). 
If it has two centroids, they are always connected (otherwise, the tree can't have n vertices).

2) In a tree only two Centroid possible (from Jordan Theorem). 
If there are two centroids you can take any cause those two centroids will look like the same.
*/



// Method 1: Can find both centroid (if present)
int n, m;
vi g[N];
int subtreeSize[N];
vector<int> centroid;

void getSubtreeSize(int u, int par) {
    subtreeSize[u] = 1;
    bool is_centroid = true;
    for (int v: g[u]) {
        if (v == par) continue;
        getSubtreeSize(v, u);
        subtreeSize[u] += subtreeSize[v];
        if (subtreeSize[v] > n / 2) is_centroid = false;
    }
    if (n - subtreeSize[u] > n / 2) 
    	is_centroid = false;
	if (is_centroid) 
		centroid.push_back(u);
}

void solve() {
	int u, v;
    cin >> n;

    for(int i = 1; i <= n; i++) 
    	g[i].clear(), subtreeSize[i] = 0;
    centroid.clear();

    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    getSubtreeSize(1, -1);
    for(int i: centroid) cout << i << " ";
    cout << endl;

}






























// Method 2: (It can only find one centroid)
// CodeNCode
int n, m;
vector < int > g[N];
int subtreeSize[N];

void getSubtreeSize(int u, int par) {
    subtreeSize[u] = 1;
    for (int v: g[u]) {
        if (v == par) continue;
        getSubtreeSize(v, u);
        subtreeSize[u] += subtreeSize[v];
    }
}

int centroid(int u, int par) {
    for (int v: g[u]) {
        if (v != par && subtreeSize[v] > (n / 2)) return centroid(v, u);
    }
    return u;
}

void solve() {
    int u, v;
    cin >> n;
    f(i, n - 1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    getSubtreeSize(1, -1);
    cout << centroid(1, -1) << endl;
}
