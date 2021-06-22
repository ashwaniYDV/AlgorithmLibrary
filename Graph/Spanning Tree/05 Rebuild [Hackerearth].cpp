// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/rebuild/

/*
Given a weighted graph find MST and keep the degree of lower nodes as minimum as possible.
i.e. if mutiple solution have same cost then [deg(1), deg(2), ..., deg(n)] must be lexicographically smallest,
where deg(i) = degree of node i.
*/

/*
Problem:
Given a weighted undirected graph connecting n cities.
The city would like to choose a set of roads such that it's possible to go from one city to any other city.

They know that at least one such set of roads exists. 
If there are multiple sets of roads that satisfy the condition, they would like to find a set that minimizes the total cost of roads.

If there are multiple sets of roads with the same minimum cost, 
they would like to choose a set that minimizes the number of roads incident to the city 1 (while keeping the cost minimum). 
If there are still ties, they would like to minimize the number of roads incident to the city 2 
(while keeping the cost and the number of roads incident to the city 1 to be small). 
This continues on until the last city n.
*/



const int N = 2e5+5;
int n, m;

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
// NOTE: src should be less then dest
struct Edge {
    int src;
    int dest;
    int weight;
};

// NOTE: src should be less then dest
bool compare(Edge e1, Edge e2) {
    if(e1.weight == e2.weight) {
        if(e1.src == e2.src) {
            return e1.dest > e2.dest;
        }
        return e1.src > e2.src;
    }
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
    int u, v, w;
    input.clear();
    result.clear();

    cin >> n >> m;

    f(i, m) {
        cin >> u >> v >> w;
        // important
        if(u > v) swap(u, v);
        Edge edg = {u, v, w};
        input.pb(edg);
    }

    kruskals();

    int cost = 0;
    vector<int> g[n+1];
    for(Edge e: result){
        g[e.src].pb(e.dest);
        g[e.dest].pb(e.src);
        cost += e.weight;
    }
    cout << cost << endl;

    loop(i, 1, n) cout << g[i].size() << " ";
    cout << endl;
}

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}









































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
// NOTE: src should be less then dest
struct Edge {
    int src;
    int dest;
    int weight;
};

// NOTE: src should be less then dest
bool compare(Edge e1, Edge e2) {
    if(e1.weight == e2.weight) {
        if(e1.src == e2.src) {
            return e1.dest > e2.dest;
        }
        return e1.src > e2.src;
    }
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
    int u, v, w;
    input.clear();
    result.clear();

    cin >> n >> m;

    f(i, m) {
        cin >> u >> v >> w;
        // important
        if(u > v) swap(u, v);
        Edge edg = {u, v, w};
        input.pb(edg);
    }

    kruskals();

    int cost = 0;
    vector<int> g[n+1];
    for(Edge e: result){
        g[e.src].pb(e.dest);
        g[e.dest].pb(e.src);
        cost += e.weight;
    }
    cout << cost << endl;

    loop(i, 1, n) cout << g[i].size() << " ";
    cout << endl;
}

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}
