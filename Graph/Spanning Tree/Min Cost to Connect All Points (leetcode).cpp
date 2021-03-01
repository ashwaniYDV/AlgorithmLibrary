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
        map<int, pair<int, int>> mp;
        int ct = 1;
        for(auto i: points) {
            mp[ct++] = {i[0], i[1]};
        }
        n = points.size();

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                auto x = mp[i], y = mp[j];
                int dist = abs(x.first - y.first) + abs(x.second - y.second);
                g[i].push_back({j, dist});
                g[j].push_back({i, dist});
            }
        }

        int root = 1;
        return prims(root);
    }
};
