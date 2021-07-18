// https://leetcode.com/problems/shortest-path-with-alternating-colors/

/*
Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  
In this graph, each edge is either red or blue, and there could be self-edges or parallel edges.
Each [i, j] in red_edges denotes a red directed edge from node i to node j.  
Similarly, each [i, j] in blue_edges denotes a blue directed edge from node i to node j.

Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to node X 
such that the edge colors alternate along the path (or -1 if such a path doesn't exist).
*/

class Solution {
public:
    #define INF 1e8
    static const int N = 1e5;
    int n, dist = INF;
    enum color {RED, BLUE};
    vector<int> gr[N], gb[N];
    
    vector<int> bfs() {
        vector<int> levelr(n, INF), levelb(n, INF);
        queue<pair<int, int>> q;
        q.push({0, RED});
        q.push({0, BLUE});
        levelr[0] = 0;
        levelb[0] = 0;
        
        while(!q.empty()) {
            auto pr = q.front();
            q.pop();
            int u = pr.first, col = pr.second;
            if(col == RED) {
                for(int v: gr[u]) {
                    if(levelr[v] == INF) {
                        levelr[v] = levelb[u] + 1;
                        q.push({v, BLUE});
                    }
                }
            } else if(col == BLUE) {
                for(int v: gb[u]) {
                    if(levelb[v] == INF) {
                        levelb[v] = levelr[u] + 1;
                        q.push({v, RED});
                    }
                }
            }
        }
        
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int mn = min(levelr[i], levelb[i]);
            if(mn == INF) res[i] = -1;
            else res[i] = mn;
        }
        return res;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        this->n = n;
        for(auto i: red_edges){
            gr[i[0]].push_back(i[1]);
        }
        for(auto i: blue_edges){
            gb[i[0]].push_back(i[1]);
        }
        return bfs();
    }
};















// vis array is redundant in shortest but still
class Solution {
public:
    #define INF 1e8
    static const int N = 1e5;
    int n, dist = INF;
    enum color {RED, BLUE};
    vector<int> gr[N], gb[N];
    
    vector<int> bfs() {
        vector<int> levelr(n, INF), levelb(n, INF);
        vector<int> visr(n, 0), visb(n, 0);
        queue<pair<int, int>> q;
        // marking vis for both red and blue for node '0'
        visr[0] = 1, visb[0] = 1;
        q.push({0, RED});
        q.push({0, BLUE});
        levelr[0] = 0;
        levelb[0] = 0;
        
        while(!q.empty()) {
            auto pr = q.front();
            q.pop();
            int u = pr.first, col = pr.second;
            if(col == RED) {
                for(int v: gr[u]) {
                    if(!visb[v] && levelr[v] == INF) {
                        visb[v] = 1;
                        levelr[v] = levelb[u] + 1;
                        q.push({v, BLUE});
                    }
                }
            } else if(col == BLUE) {
                for(int v: gb[u]) {
                    if(!visr[v] && levelb[v] == INF) {
                        visr[v] = 1;
                        levelb[v] = levelr[u] + 1;
                        q.push({v, RED});
                    }
                }
            }
        }
        
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int mn = min(levelr[i], levelb[i]);
            if(mn == INF) res[i] = -1;
            else res[i] = mn;
        }
        return res;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        this->n = n;
        for(auto i: red_edges){
            gr[i[0]].push_back(i[1]);
        }
        for(auto i: blue_edges){
            gb[i[0]].push_back(i[1]);
        }
        return bfs();
    }
};
