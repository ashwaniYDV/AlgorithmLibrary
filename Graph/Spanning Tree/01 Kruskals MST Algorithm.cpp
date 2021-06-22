/*--------------------DSU BEGIN----------------------------------*/
int par[N];
void initialize() {
    for(int i = 0; i < N; i++) {
        par[i] = -1;
    }
}
int findParent(int a) {
    if(par[a] < 0)
        return a;
    return par[a] = findParent(par[a]);
}
void unionSet(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a == b) return;
    if(par[a] > par[b]) swap(a,b);
    par[a] += par[b];
    par[b] = a;
}
/*--------------------DSU END------------------------------------*/


/*--------------------KRUSKAL'S BEGIN-----------------------------*/
struct Edge {
    int src;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

vector<Edge> input;
vector<Edge> result;

void kruskals() {
    sort(input.begin(), input.end(), compare);
    initialize();

    int cost = 0;
    for(Edge currEdge: input) {
        int srcParent = findParent(currEdge.src);
        int destParent = findParent(currEdge.dest);
        if(srcParent != destParent) {
            result.pb(currEdge);
            unionSet(srcParent, destParent);
        }
    }
}
/*--------------------KRUSKAL'S END------------------------------*/


void solve() {
    int u, v, x, y;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v >> x;
        Edge edg = {u, v, x};
        input.pb(edg);
    }
    kruskals();
    int cost = 0;
    for(Edge e: result){
        cout << e.src << " " << e.dest << " " << e.weight << endl;
        cost += e.weight;
    }
    cout << "Min cost: " << cost;
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
