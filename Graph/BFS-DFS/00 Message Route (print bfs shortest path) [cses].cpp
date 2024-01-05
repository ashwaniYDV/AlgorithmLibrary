// https://cses.fi/problemset/task/1667/

/*
Print shortest path from 1 to n.
*/

const int N = 2e5+5;
int n, m;
vi g[N];
int vis[N];
int par[N];

void solve() {
    int x, y, z;
    cin >> n >> m;

    f(i, m) {
        cin >> x >> y, g[x].pb(y), g[y].pb(x);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    par[1] = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: g[u]) {
            if(!vis[v]) {
                par[v] = u;
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    if(!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    int node = n;
    vi res;
    while(par[node] != -1) {
        res.pb(node);
        node = par[node];
    }
    res.pb(1);

    reverse(all(res));
    cout << res.size() << endl;
    for(int x: res) cout << x << " ";
} 
