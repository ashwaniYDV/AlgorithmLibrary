// https://cses.fi/problemset/task/1132/
// https://youtu.be/Rnv4qvoxsTo
// https://usaco.guide/problems/cses-1132-tree-distances-i/solution

/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.

Input:
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output:
Print n integers: for each node 1,2,…,n, the maximum distance to another node.
*/


/*
node1 and node2 are the end points of diameter of tree.
When any node is rooted, it's max height will eventually end at end points of diameter, i.e. either node1 or node2

depth1 = calculated when node1 is root
depth2 = calculated when node2 is root
*/

const int N = 2e5+5;
int n, m;
 
vector<int> g[N];
vector<int> depth1, depth2;

void dfs(int u, int par, int d, vector<int>& depth) {
    depth[u] = d;
    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u, d + 1, depth);
    }
}

void diameterOfTree() {
    depth1 = vector<int>(n+1, 0);
    dfs(1, -1, 0, depth1);
    int node1 = 0, mx = 0;
    for(int i = 1; i <= n; i++) {
        if(depth1[i] > mx) {
            mx = depth1[i];
            node1 = i;
        }
    }

    depth1 = vector<int>(n+1, 0);
    dfs(node1, -1, 0, depth1);

    int node2 = 0;
    mx = 0;
    for(int i = 1; i <= n; i++) {
        if(depth1[i] > mx) {
            mx = depth1[i];
            node2 = i;
        }
    }

    depth2 = vector<int>(n+1, 0);
    dfs(node2, -1, 0, depth2);

}

void solve() {
    int u, v;
    cin >> n;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    diameterOfTree();

    loop(i, 1, n) {
        cout << max(depth1[i], depth2[i]) << " ";
    }
}
