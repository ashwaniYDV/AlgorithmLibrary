/*
For each node in the given tree, find no of ancestors of current node which have color greater than current node.
*/


const int N = 1e5+5;
int n, m;

vi g[N];
int BIT[N], color[N], res[N];

void update(int i, int val) {
    while(i < N) {
        BIT[i] += val;
        i += (i&-i);
    }
}

int query(int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}

void dfs(int u, int par) {
    // no of colors greater than color[u]
    res[u] = query(N-1) - query(color[u]);
    // adding since kids nodes will have this node as ancestor
    update(color[u], 1);

    for(int v: g[u]) {
        if(v != par) {
            dfs(v, u);
        }
    }

    // removing since other nodes in proceeding dfs will not have this node as ancestor
    update(color[u], -1);
}

void solve() {
    int u, v;
    cin >> n;
    
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    loop(i, 1, n) cin >> color[i];

    // coordinate compression
    set<int> st;
    map<int, int> mp;
    loop(i, 1, n) st.insert(color[i]);
    int rank = 1;
    for(int x: st) {
        mp[x] = rank++;
    }
    loop(i, 1, n) color[i] = mp[color[i]];

    dfs(1, -1);
    loop(i, 1, n) cout << res[i] << " ";
} 


/*
Input:
7
1 2
1 3
2 4
2 5
3 6
3 7
6 2 9 1 4 2 3

Output:
0 1 0 2 1 2 2 
*/
