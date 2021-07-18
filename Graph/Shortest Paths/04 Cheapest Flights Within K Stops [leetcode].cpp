// https://leetcode.com/problems/cheapest-flights-within-k-stops/


// Method 1: Bellman Ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        for(int i = 0; i <= K; i++){
            vector<int> tempDis(dis);
            for(auto x: flights){
                int u = x[0];
                int v = x[1];
                int d = x[2];
                tempDis[v] = min(tempDis[v], dis[u] + d);
            }
            dis = tempDis;
        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};








// Method 2
class Solution {
public:
    static const int N = 1e2+5;
    int n;
    vector<int> g[N];
    int vis[N];
    map<pair<int, int>, int> costs;
    int fareCost = 1e9;
    
    void dfs(int u, int dst, int k, int cost) {
        if(u == dst) {
            fareCost = min(fareCost, cost);
            return;
        }
        
        if(k < 0) return;
        
        vis[u] = 1;
        
        for(int v: g[u]) {
            if(!vis[v] && cost + costs[{u, v}] < fareCost) {
                dfs(v, dst, k - 1, cost + costs[{u, v}]);
            }
        }
        // backtrack
        vis[u] = 0;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        n = flights.size();
        
        for(vector<int> i: flights) {
            g[i[0]].push_back(i[1]);
            costs[{i[0], i[1]}] = i[2];
        }
        dfs(src, dst, K, 0);
        
        if(fareCost == 1e9) return -1;
        return fareCost;
    }
};