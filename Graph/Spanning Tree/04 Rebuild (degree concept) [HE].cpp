// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/rebuild/
// https://youtu.be/hvY3hhYMd20

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
If there are multiple sets of roads that satisfy the condition, 
they would like to find a set that minimizes the total cost of roads.

If there are multiple sets of roads with the same min cost, 
they would like to choose a set that minimizes no of roads incident to city 1 (while keeping the cost minimum). 
If there are still ties, they would like to minimize no of roads incident to city 2 
(while keeping the cost and no of roads incident to city 1 to be small). 
This continues on until the last city n.
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+5;
int n, m;

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

// NOTE: src should be less then dest
struct Edge {
    int src;
    int dest;
    int weight;
};

struct KRUSAKALS {
    vector<Edge> input, result;

    KRUSAKALS() {
        input.clear();
        result.clear();
    }

    void addEdge(int u, int v, int w) {
        // important
        if(u > v) swap(u, v);
        Edge edg = {u, v, w};
        input.push_back(edg);
    }

    int solve() {
        // NOTE: src should be less then dest
        sort(input.begin(), input.end(), [](Edge& e1, Edge& e2) {
            if(e1.weight == e2.weight) {
                if(e1.src == e2.src) {
                    return e1.dest > e2.dest;
                }
                return e1.src > e2.src;
            }
            return e1.weight < e2.weight;
        });

        DSU dsu(n+1);

        int cost = 0;
        for(Edge currEdge: input) {
            int srcParent = dsu.findParent(currEdge.src);
            if(!dsu.sameSet(currEdge.src, currEdge.dest)) {
                result.push_back(currEdge);
                dsu.unionSet(currEdge.src, currEdge.dest);
                cost += currEdge.weight;
            }
        }

        return cost;
    }
};

void solve() {
    int u, v, w;
    cin >> n >> m;

    KRUSAKALS kruskals; 

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        kruskals.addEdge(u, v, w);   
    }

    int cost = kruskals.solve();
    
    vector<int> g[n+1];
    for(Edge e: kruskals.result){
        g[e.src].push_back(e.dest);
        g[e.dest].push_back(e.src);
    }
    cout << cost << endl;

    for(int i = 1; i <= n; i++) cout << g[i].size() << " ";
    cout << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
