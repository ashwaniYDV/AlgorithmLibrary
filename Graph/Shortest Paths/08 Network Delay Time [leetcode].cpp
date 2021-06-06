// https://leetcode.com/problems/network-delay-time/

/*
You are given a network of n nodes, labeled from 1 to n.  
You are also given times, a list of travel times as directed edges 
times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. 
Return the time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.
*/


class Solution {
    #define INF 1e9
    static const int N = 100000;
public:
    vector<pair<int, int>> g[N];
    int vis[N], dp[N];
    int n;
    
    void dijkstra(int source) {
        for(int i = 1; i <= n; i++) 
            dp[i] = INF;
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, source});
        dp[source] = 0;

        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();

            int u = x.second;

            if(dp[u] < x.first) continue;

            for(auto y: g[u]) {
                if(dp[y.first] > dp[u] + y.second) {
                    dp[y.first] = dp[u] + y.second;
                    pq.push({dp[y.first], y.first});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        n = N;
        for(auto i: times) {
            g[i[0]].push_back({i[1], i[2]});
        }
        dijkstra(K);
        int mx = 0;
        for(int i = 1; i <= N; i++){
            if(dp[i] == INF) return -1;
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};























class Solution {
    #define INF 1e9
    static const int N = 100000;
public:
    vector<pair<int, int>> g[N];
    int vis[N], dp[N];
    int n;
    
    void dijkstra(int source) {
    for (int i = 1; i <= n; i++) 
        dp[i] = INF;

    set<pair<int, int>> s;
    s.insert({dp[source], source});
    dp[source] = 0;
    
	while (!s.empty()) {
	    int u = s.begin()->second;
	    s.erase(s.begin());
	    for (auto x : g[u]) {
	        int v = x.first, w = x.second;
	        if (dp[v] > dp[u] + w){
	        	s.erase({dp[v], v});
	        	dp[v] = dp[u] + w;
	        	s.insert({dp[v], v});
	       	}
	    }
	}
}
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        n = N;
        for(auto i: times) {
            g[i[0]].push_back({i[1], i[2]});
        }
        dijkstra(K);
        int mx = 0;
        for(int i = 1; i <= N; i++){
            if(dp[i] == INF) return -1;
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
