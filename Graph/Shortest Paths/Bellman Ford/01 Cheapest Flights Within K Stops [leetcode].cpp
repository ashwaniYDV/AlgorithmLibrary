// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// https://youtu.be/5eIK3zUdYmE?si=KRuov4vDX7jHWs6A

/*
There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.

Note:
k = no of stops in bw src and dest (i.e. excluding src and dest stops)
  = intermediate stops bw src and dest
*/

/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/662812/C%2B%2B-BFS-or-Bellman-Ford-Algo-or-Dijkstra-Algo

In bellman ford there are possibities of getting our answer for node X distance away before Xth iteration.
That is why temp is used to eliminate the possibility of getting our ans for node X distance away before Xth iteration.
That means at Kth iteration only node K distance away can fill.

tempDis will store the changes made in dis vector, cause we don't want to use the immediate changes in the dist
Lets take second example:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
if we don't use tmp vector than
[0, 1, 100] will update dist of dist[1] = 100
[1, 2, 100] will update dist[2] as 200 but (this is wrong cause we can use at most k i.e 0 here stops but here 0->1->2 will be 1 stops)
*/


// Method 1: Bellman Ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dis(n, 1e9);
        dis[src] = 0;

        // Run only K+1 times since we want shortest distance with at most K intermediate stops
        // i.e. using atmost K+1 hops
        for(int i = 0; i <= K; i++) {
            vector<int> tempDis(dis);
            for(auto x: flights) {
                int u = x[0];
                int v = x[1];
                int d = x[2];

                if(dis[u] != 1e9)
                    tempDis[v] = min(tempDis[v], dis[u] + d);
            }
            dis = tempDis;
        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};


// MEthod 2: Dijkstra
class Solution {
    public: int findCheapestPrice(int n, vector < vector < int >> & flights, int src, int dst, int k) {
        vector < pair < int, int >> g[n];
        for (int i = 0; i < flights.size(); i++) {
            g[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        priority_queue<array<int, 3>, vector<array<int, 3>> , greater<array<int, 3>>> pq;
        
        // {stops, dis, node} -> this will only work
        // if you take {dis, stops, node} -> this will give wrong answer
        pq.push({0, 0, src});
        vector < int > dist(n, 1e9);
        dist[src] = 0;

        while (!pq.empty()) {
            int stops = pq.top()[0];
            int dis = pq.top()[1];
            int u = pq.top()[2];
            pq.pop();

            // since pq is first sorted by k, we can break from here since rest stops will be greater only
            // we can use continue also, but it will be time consuming
            if (stops > k) break;

            for (auto it: g[u]) {
                int v = it.first, w = it.second;

                // use dis instead of dist[u] here
                if (dist[v] > dis + w) {
                    dist[v] = dis + w;
                    pq.push({stops + 1, dist[v], v});
                }
            }
        }

        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};








// Method 3: BFS
class Solution {
public:
    public: int findCheapestPrice(int n, vector<vector<int>> & flights, int src, int dst, int k) {
        vector<pair<int, int>> g[n];
        for (auto it: flights) {
            g[it[0]].push_back({it[1], it[2]});
        }

        queue<vector<int>> q;
        vector<int>dist(n, 1e9);

        q.push({0, src, 0});
        dist[src] = 0;

        while(!q.empty()){
            int stops = q.front()[0];
            int u = q.front()[1];
            int dis = q.front()[2];
            q.pop();

            if(stops > k) break;

            for(auto it: g[u]) {
                int v = it.first, w = it.second;

                if(dist[v] > dis + w){
                    dist[v] = dis + w;
                    q.push({stops + 1, v, dist[v]});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};