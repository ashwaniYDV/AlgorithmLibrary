// https://cses.fi/problemset/task/1675/
// Road Reparation - CSES


#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5+5;
int n, m;

vector<vector<int>> input, result;

struct DSU {
    vector<int> par;
    DSU(int n) {
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

int kruskals() {
    sort(input.begin(), input.end());
    DSU dsu(n+1);

    int cost = 0;
    for(auto it: input) {
        int w = it[0], u = it[1], v = it[2];
        if(!dsu.sameSet(u, v)) {
            result.push_back(it);
            cost += w;
            dsu.unionSet(u, v);
        }
    }

    return cost;
}

int32_t main() {
    int u, v, w;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        input.push_back({w, u, v});
    }
    
    int cost = kruskals();
    
    // for(auto it: result) {
    //     int w = it[0], u = it[1], v = it[2];
    //     cout << u << " " << v << " " << w << endl;
    // }

    if((int)result.size() != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cost << endl;
    }
}
