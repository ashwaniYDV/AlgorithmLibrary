// since it's for directed graph, therefore works for undirected as well


ll cycleDetected=0;
ll color[N]; // all white

void dfs(ll u){
    color[u]=1; // grey
    for(ll v: g[u]){
        if(color[v] == 1){
            // do anything you want when cycle detected
            cycleDetected=1;
        }
        if(color[v]==0)
            dfs(v);
    }
    color[u]=2; // black
}

void solve() {
    cin>>n>>m;
    f(i,m) cin>>u>>v, g[u].pb(v);
    loop(i, 1, n){
        if(color[i] == 0){
            dfs(i);
        }
    }
    if(cycleDetected){
        cout<<"Yes, there is/are cycle(s)";
    }else{
        cout<<"There is no cycle";
    }
}
