// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/

/*
You are given a list of binary relations, equalities and inequalities, like a = b, a != d, b = c etc. 
Your task is to output YES if you can assign integers to input variables in such a way, that you can satisfy all equalities and inequalities. 
Otherwise you should output NO.
*/

const int N = 1e6+5;
int n, m;

/*--------------------DSU BEGIN----------------------------------*/
int par[N];
void initialize() {
    for(int i = 1; i <= n; i++) {
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

void solve() {
    int k, u, v;
    cin >> n >> k;
    initialize();
    vector<pair<int, int>> a;
    string s;
    f(i, k) {
        cin >> u >> s >> v;
        if(s == "=") 
            unionSet(u, v);
        else 
            a.pb({u, v});
    }

    for(auto it: a) {
        if(findParent(it.F) == findParent(it.S)){
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}

signed main() {
    IOS
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
} 
