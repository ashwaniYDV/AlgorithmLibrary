// https://codeforces.com/problemset/problem/118/E
// https://youtu.be/lx9QCdt79vQ

/*
If there is any bridge, then consider two components as shown connected by bridge

    --------------|                    |-----------
    |             |     bridge edge    |          |
    |      A      |------------------->|    B     |
    |             |                    |          |
    |--------------                    |----------|
    
If bridge edge is directed in this way, then A component nodes can reach B component nodes but not vice versa. 
    
    --------------|                    |-----------
    |             |     bridge edge    |          |
    |      A      |<-------------------|    B     |
    |             |                    |          |
    |--------------                    |----------|
    

If bridge edge is directed in this way, then B component nodes can reach A component nodes but not vice versa.

Thus if there is a bridge then the answer is simply NO.

Otherwise we have answers and the question is just to direct these edges in any correct possible way.
First of all we direct the edges as formed by the DFS tree from parent to child (i.e u->v).
Now we are only left to direct the back edges.
We will direct the back-edges from child to ancestor (u->v, where v is ancestor; see code for insight).
Since back edge always introduces a cycle thus this new directed graph becomes cyclic and we can reach from any node to any other node.

Claim 1: There is path from root node (node 1) to any other node (DFS Tree property)
Claim 2: There is a path from every other node to root node via some back-edge
*/


const int N = 1e5+5;
int n, m;

vector<int> g[N];
vector<pair<int, int>> resEdges;
int in[N], low[N];
int timer;
bool hasBridge;

void dfs(int u, int par) {
    in[u] = low[u] = ++timer;

    for(int v: g[u]) {
        if(v == par) continue;
        //If v is not visited (forward edge)
        if(in[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > in[u]) {
                hasBridge = true;
            }

            resEdges.pb({u, v});
        }
        // back edge (for back edge v is ancestor; back edge introduces a cycle)
        else {
            low[u] = min(low[u], in[v]);

            if(in[u] > in[v]) {
                resEdges.pb({u, v});
            }
        }
    }
}

void solve() {
    int u, v;
    cin >> n >> m;

    // undirected graph
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    loop(i, 1, n) in[i] = -1, low[i] = -1;
    timer = 0;
    hasBridge = false;
    
    loop(i, 1, n) {
        if(in[i] == -1) {
            dfs(i, -1);
        }
    }

    if(hasBridge) {
        cout << 0 << endl;
        return;
    }

    for(auto i: resEdges) {
        cout << i.F << " " << i.S << endl;
    }
}

signed main() {
    IOS
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
} 
