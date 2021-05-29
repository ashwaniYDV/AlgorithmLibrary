// 

const int N = 2e5+5;
int n, m;

set<int> g[N];
int parent[N];
int subTreeSize[N];

/*--------Decompose Part-----------*/ 
int dfs1(int u, int par) {
    subTreeSize[u] = 1;
 
    for(int v: g[u]) {
        if(v != par)
            subTreeSize[u] += dfs1(v , u);
    }

    return subTreeSize[u];
}
 
int dfs(int u, int par, int n) {
    for(int v: g[u]) {
        if(v != par && subTreeSize[v] > n/2)
            return dfs(v , u , n);
    }
 
    return u;
}
 
void decompose(int u, int par) {
 
    int stSize = dfs1(u, -1);
 
    int centroid = dfs(u, par, stSize);
 
    cout << "Tree rooted at " << u << " with size " << stSize << " has centroid " << centroid << endl;
 
    parent[centroid] = par;
 
    for(int v : g[centroid]) {
        g[v].erase(centroid);
        decompose(v, centroid);
    }
}
/*--------Decompose Ends-----------*/
 
void solve() {
    int u, v;
    cin >> n;
 
    f(i, n-1) cin >> u >> v, g[u].insert(v), g[v].insert(u);
 
    decompose(1, -1);
 
    cout << "Parent array is as follows:" << endl;
    loop(i, 1, n)
    cout << "Parent[" << i << "] = " << parent[i] << endl;
}
 
signed main() {
    IOS
    int t = 1;
    // cin >> t;
    f(i, t) {
        solve();
    }
}

/*
15
2 1
2 3
2 4
2 5
5 6
5 8
6 7
8 9
9 10
9 13
10 11
10 12
13 14
13 15
*/

/*
Tree rooted at 1 with size 15 has centroid 8
Tree rooted at 5 with size 7 has centroid 2
Tree rooted at 1 with size 1 has centroid 1
Tree rooted at 3 with size 1 has centroid 3
Tree rooted at 4 with size 1 has centroid 4
Tree rooted at 5 with size 3 has centroid 6
Tree rooted at 5 with size 1 has centroid 5
Tree rooted at 7 with size 1 has centroid 7
Tree rooted at 9 with size 7 has centroid 9
Tree rooted at 10 with size 3 has centroid 10
Tree rooted at 11 with size 1 has centroid 11
Tree rooted at 12 with size 1 has centroid 12
Tree rooted at 13 with size 3 has centroid 13
Tree rooted at 14 with size 1 has centroid 14
Tree rooted at 15 with size 1 has centroid 15
Parent array is as follows:
Parent[1] = 2
Parent[2] = 8
Parent[3] = 2
Parent[4] = 2
Parent[5] = 6
Parent[6] = 2
Parent[7] = 6
Parent[8] = -1
Parent[9] = 8
Parent[10] = 9
Parent[11] = 10
Parent[12] = 10
Parent[13] = 9
Parent[14] = 13
Parent[15] = 13
*/
