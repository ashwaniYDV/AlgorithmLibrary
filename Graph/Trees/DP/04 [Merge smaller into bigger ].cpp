// https://www.hackerrank.com/contests/101feb14/challenges/coloring-tree

/*
## Merging many sets in O(nlogn) amortized (i.e. cannot revert it).
If you have some sets and you often need to merge some of theme, you can do it in naive way 
but in such manner that you always move elements from the smaller one to the larger. 
Thus every element will be moved only O(logn) times since its new set always will be at least twice as large as the old one. 
Some versions of DSU are based on this trick. Also you can use this trick when you merge sets of vertices in subtrees while having dfs.
*/



// Naive Method: O(n^2) 
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
