/*
Q1) Check if two nodes are on same path in a tree
Q2) Whether one node lies in the subtree of another node

Ans) For any two nodes u, v if they are in same path then,

Intime[v] < Intime[u] and Outtime[v] > Outtime[u]
                 OR
Intime[u] < Intime[v] and Outtime[u ]> Outtime[v]
*/



vl g[N];
ll n, m;

ll in[N], out[N], vis[N];
ll timer = 1;

void dfs(ll u){
    in[u] = timer++;
    vis[u] = 1;
    for(ll v: g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    out[u] = timer++;
}

void solve() {
    ll t, k, u, v;
    cin >> n;
    f(i, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    dfs(1);
    ll queries;
    cin >> queries;
    f(i, queries){
        cin >> u >> v;
        if((in[u] > in[v] && out[u] < out[v]) || (in[u] < in[v] && out[u] > out[v])){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

/*
INPUT:
5
1 2
2 3
2 4
4 5
6
3 5
1 2
1 5
2 4
3 2
3 4

OUTPUT:
NO
YES
YES
YES
YES
NO
*/
