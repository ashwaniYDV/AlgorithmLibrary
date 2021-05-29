// https://cses.fi/problemset/task/1137/


const int N = 2e5+5;
int n, m;
vi g[N];
 
int arr[N];
int nodeV[N];
int subtreeSize[N];
int in[N];
int _timer;
 
// Euler Tour Technique (ETT)
void dfs(int u, int par) {
    in[u] = _timer;
    arr[in[u]] = nodeV[u];
    _timer++;
    subtreeSize[u] = 1;
    
    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u);
        subtreeSize[u] += subtreeSize[v];
    }
}

/*************** ST ********************************/
int st[2 * N];

void build(int si, int ss, int se) {
    if(ss == se) {
        st[si] = arr[ss];
        return;
    }
 
    int mid = (ss + se) / 2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    st[si] = st[2*si] + st[2*si+1];
}
 
void update(int si, int ss, int se, int qi, int dx) {
    if(ss > qi || se < qi) return;
    
    if(ss == se) {
        st[si] += dx;
        return;
    }
    
    int mid = (ss + se) >> 1;
    update(2*si , ss , mid , qi , dx);
    update(2*si + 1 , mid+1 , se , qi , dx);
    
    st[si] = st[2*si] + st[2*si + 1];
}
 
int query(int si, int ss, int se, int qs, int qe) {
    if(ss > qe || se < qs) 
        return 0;
    
    if(ss >= qs && se <= qe)
        return st[si];
    
    int mid = (ss + se) >> 1;
    int L = query(2*si , ss , mid , qs , qe);
    int R = query(2*si + 1 , mid+1 , se , qs , qe);
    
    return L + R;
}
/***************************************************/


void solve() {
    int q, u, v, x, type;
    cin >> n >> q;
    
    loop(i, 1, n) cin >> nodeV[i];
    loop(i, 1, n-1) cin >> u >> v, g[u].pb(v), g[v].pb(u);
    
    _timer = 1;
    dfs(1 , -1);
    build(1 , 1 , n);
    
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> u >> x;
            update(1, 1, n, in[u], x - arr[in[u]]);
            arr[in[u]] = x;
        } else {
            cin >> u;
            cout << query(1, 1, n, in[u], in[u] + subtreeSize[u] - 1) << endl;
        }
    }
}
