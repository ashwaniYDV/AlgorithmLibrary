// https://cses.fi/problemset/task/1683/

/*
A game has n planets, connected by m teleporters. Two planets a and b belong to the same kingdom exactly 
when there is a route both from a to b and from b to a. Your task is to determine for each planet its kingdom.

Input:
The first input line has two integers n and m: the number of planets and teleporters. The planets are numbered 1,2,…,n.
After this, there are m lines describing the teleporters. 
Each line has two integers a and b: you can travel from planet a to planet b through a teleporter.

Output:
First print an integer k: the number of kingdoms. After this, print for each planet a kingdom label between 1 and k. 
You can print any valid solution.
*/

const int N = 2e5+5;
int n, m;
 
vector<int> g[N], transpose_g[N];
int vis[N];
stack<int> st;

int component[N];
int componentNo = 0;

void dfs(int u) {
    vis[u] = 1;
    for(int v: g[u]) {
        if(!vis[v]) dfs(v);
    }
    st.push(u);
}
 
void revDfs(int u) {
    component[u] = componentNo;
    vis[u] = 1;
    for(int v: transpose_g[u]) {
        if(!vis[v]) revDfs(v);
    }
}
 
void solve() {
    int u, v;
    cin >> n >> m;
 
    f(i, m) cin >> u >> v, g[u].pb(v), transpose_g[v].pb(u);
    
    // to store nodes in decreasing order of out time in stack
    loop(i, 1, n) {
        if(!vis[i]) dfs(i);
    }
 
    loop(i, 1, n) vis[i] = 0;
    ll totalSCC = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            totalSCC++;
            componentNo++;
            revDfs(node);
        }
    }
 
 
    cout << totalSCC << endl;
    loop(i, 1, n) cout << component[i] << " ";
}
