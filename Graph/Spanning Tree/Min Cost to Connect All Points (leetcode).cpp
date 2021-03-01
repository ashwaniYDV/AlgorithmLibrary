// https://leetcode.com/problems/min-cost-to-connect-all-points/

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
