/*
There is tree of N (0 < N <= 10^5) vertices and N-1 edges. 
You have been given n-1 queries (which is permutation of 0 to n-1) 
and in each query, you have to remove the edge no query[i]
and give the largest size of the component from the resultant components.
*/


/*
It is same as Road Construction [CSES] problem but in reverse order.
Thus instead of removing edges, it will have an effect that we are adding edges.
Thus we'll do DSU in reverse order and calculate answer.
*/


const int N = 1e5+5;
int n, m;

struct DSU {
    vector<int> par;
    void init(int n) {
        par.resize(n+1, -1);
    }
    int findParent(int a) {
        if(par[a] < 0) return a;
        return par[a] = findParent(par[a]);
    }
    bool unionSet(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a == b) return 0;
        if(par[a] > par[b]) swap(a,b);
        par[a] += par[b];
        par[b] = a;
        return 1;
    }
    bool sameSet(int x, int y) { 
        return findParent(x) == findParent(y); 
    }
    int size (int x) { 
        return -par[findParent(x)]; 
    }
};


void solve() {
    int u, v;
    cin >> n;

    vector<pair<int, int>> treeEdges;
    f(i, n-1) cin >> u >> v, treeEdges.pb({u, v});

    vector<int> q(n-1);
    f(i, n-1) cin >> q[i]; 
    
    DSU dsu;
    dsu.init(n);
    int noOfForests = n, largestForest = 1;
    
    vector<int> res;
    res.pb(1);

    for(int i = n-2; i >= 0; i--) {
        u = treeEdges[q[i]].first, v = treeEdges[q[i]].second;
        if (!dsu.sameSet(u, v)) {
            dsu.unionSet(u, v);
            largestForest = max(largestForest, dsu.size(u));
            noOfForests--;
        }
        res.pb(largestForest);
    }

    reverse(all(res));
    loop(i, 1, n-1) cout << res[i] << " ";
} 



/*
Input:
7
1 2
1 3
2 4
2 5
3 6
3 7
0 2 4 3 1 5

Output:
4 4 3 3 2 1 
*/
