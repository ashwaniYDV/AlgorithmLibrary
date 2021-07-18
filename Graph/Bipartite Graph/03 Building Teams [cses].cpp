// https://cses.fi/problemset/task/1668/

/*
There are n pupils in class, and m friendships between them. 
Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. 
You can freely choose the sizes of the teams.
*/

const int N = 2e5+5;
int n, m;

vi g[N];
int vis[N], color[N];

bool isBipartite(int u, int c) {
    vis[u] = 1;
    color[u] = c;
    for(int v: g[u]) {
        if(!vis[v]) {
            if(isBipartite(v, c^1) == false) return false;
        } else {
            if(color[v] == color[u]) return false;
        }
    }
    return true;
}

void solve() {
    int u, v;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v, g[u].pb(v), g[v].pb(u);
    }

    bool bipartite = true;
    loop(i, 1, n) {
        if(!vis[i]) 
            bipartite = bipartite && isBipartite(i, 1);
    }

    if(!bipartite) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    loop(i, 1, n) cout << (color[i] == 1 ? 1 : 2) << " ";

}
