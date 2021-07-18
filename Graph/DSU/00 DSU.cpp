// Path compression DSU
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








struct DSU {
    vector<int> par, rank;
    DSU(int n) {
        par.resize(n+1);
        rank.resize(n+1);
        for(int i = 0; i <= n; i++) {
            par[i] = i;
            rank[i] = 1;
        }
    }
    int findParent(int a) {
        if(par[a] == a) return a;
        return par[a] = findParent(par[a]);
    }
    bool unionSet(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if(a == b) return 0;
        if(rank[a] < rank[b])
            swap(a, b);
        par[b] = a;
        rank[a] += rank[b];
        return 1;
    }
    bool sameSet(int x, int y) { 
        return findParent(x) == findParent(y); 
    }
    int size(int x) { 
        return rank[findParent(x)]; 
    }
};
