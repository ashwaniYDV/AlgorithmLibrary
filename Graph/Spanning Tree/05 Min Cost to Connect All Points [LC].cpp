// https://leetcode.com/problems/min-cost-to-connect-all-points/

/*
You are given an array points representing integer coordinates of some points on a 2D-plane, 
where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] = |xi - xj| + |yi - yj|.
(called as manhattan distance)
Return min cost to make all points connected. 
All points are connected if there is exactly one simple path between any two points.
*/

// Method 1: Kruskals
class Solution {
public:
    vector<vector<int>> input;
    int n;
    
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
                cost += w;
                dsu.unionSet(u, v);
            }
        }

        return cost;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                auto x = points[i], y = points[j];
                int dist = abs(x[0] - y[0]) + abs(x[1] - y[1]);
                input.push_back({dist, i, j});
            }
        }

        return kruskals();
    }
};



// Method 2: Prims
class Solution {
public:
    static const int N = 1e5+5;
    int n;
    vector<pair<int, int>> g[N];

    int prims(int root) {
        vector<int> dist(n+1, 1e9);
        vector<int> parent(n+1, -1);
        vector<int> vis(n+1, 0);

        set<pair<int, int> > s;
        s.insert({0, root});
        dist[root] = 0;

        int cost = 0;

        while(!s.empty()) {
            auto x = *(s.begin());
            s.erase(x);
            cost += x.first;
            int u = x.second;
            vis[u] = 1;

            for(auto y: g[u]) {
                int v = y.first;
                int weight = y.second;

                if (dist[v] > weight) {
                    if(vis[v]) continue; 

                    s.erase({dist[v], v});
                    dist[v] = weight;
                    s.insert({dist[v], v});
                    parent[v] = u;
                }
            }
        }
        return cost;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                auto x = points[i], y = points[j];
                int dist = abs(x[0] - y[0]) + abs(x[1] - y[1]);
                g[i].push_back({j, dist});
                g[j].push_back({i, dist});
            }
        }

        int root = 0;
        return prims(root);
    }
};
