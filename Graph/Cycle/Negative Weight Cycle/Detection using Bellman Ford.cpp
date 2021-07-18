// https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/

/*
We are given a directed graph. We need compute whether the graph has negative cycle or not. 
A negative cycle is one in which the overall sum of the cycle comes negative.
*/

/*
How does it work? 
As discussed in Bellman Ford algorithm, for a given source, it first calculates the shortest distances which have at-most one edge in the path. 
Then, it calculates shortest paths with at-most 2 edges, and so on. 
After the i-th iteration of outer loop, the shortest paths with at most i edges are calculated. 
There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times. 
If there is a negative weight cycle, then one more iteration would give a shorted path.
*/

// This program works only if all vertices are reachable from a source vertex 0.
class Solution {
public:
    #define INF 1e9
    bool isNegCycleBellmanFord(int src, int n, vector < long long > & dis, vector < vector < int >> & edges) {
        dis = vector < long long > (n, INF);
        dis[src] = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (auto x: edges) {
                int u = x[0];
                int v = x[1];
                int d = x[2];
                if (dis[u] < INF) {
                    dis[v] = min(dis[v], dis[u] + d);
                }
            }
        }

        for (auto x: edges) {
            int u = x[0];
            int v = x[1];
            int d = x[2];
            if (dis[v] > dis[u] + d) {
                return true;
            }
        }

        return false;
    }

    int isNegativeWeightCycle(int n, vector < vector < int >> edges) {
        vector < long long > dis(n);
        return isNegCycleBellmanFord(0, n, dis, edges);
    }
};














/*
How to handle disconnected graph (If cycle is not reachable from source)? 
The above algorithm and program might not work if the given graph is disconnected. 
It works when all vertices are reachable from source vertex 0.
To handle disconnected graph, we can repeat the process for vertices for which distance is infinite.
*/
class Solution {
public:
    #define INF 1e9
    bool isNegCycleBellmanFord(int src, int n, vector < long long > & dis, vector < vector < int >> & edges) {
        dis = vector < long long > (n, INF);
        dis[src] = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (auto x: edges) {
                int u = x[0];
                int v = x[1];
                int d = x[2];
                if (dis[u] < INF) {
                    dis[v] = min(dis[v], dis[u] + d);
                }
            }
        }

        for (auto x: edges) {
            int u = x[0];
            int v = x[1];
            int d = x[2];
            if (dis[v] > dis[u] + d) {
                return true;
            }
        }

        return false;
    }

    int isNegativeWeightCycle(int n, vector < vector < int >> edges) {
        // To keep track of visited vertices to avoid recomputations.
        vector < int > vis(n, 0);

        // This array is filled by Bellman-Ford
        vector < long long > dis(n);

        // Call Bellman-Ford for all those vertices that are not visited
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                // If cycle found
                if (isNegCycleBellmanFord(i, n, dis, edges)) return true;

                // Mark all vertices that are visited in above call.
                for (int i = 0; i < n; i++) {
                    if (dis[i] != INF) {
                        vis[i] = 1;
                    }
                }
            }
        }

        return false;
    }
};
