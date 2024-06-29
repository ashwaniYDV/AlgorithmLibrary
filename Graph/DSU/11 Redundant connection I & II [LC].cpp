// https://leetcode.com/problems/redundant-connection/
// Undirected version

/*
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
*/

class Solution {
public:
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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto it: edges) {
            if(dsu.sameSet(it[0], it[1])) {
                return it;
            }
            dsu.unionSet(it[0], it[1]);
        }
        return {};
    }
};







// https://leetcode.com/problems/redundant-connection-ii/
// Directed version

/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, 
plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), 
with one additional directed edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. 
Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, 
where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array.
*/




/*
Intuition: DSU with indegree
----------------------------
Case1: A vertex has no duplicate parents.
       Return the first edge that creates loop (Same as Redundant Connection I)
Case2: A node has two parents {u1, u2}:
       Case2.1: Return {u1, v} or {u2, v} that creates the loop
       Case2.2: Return the second edge that creates duplicate parent
*/

class Solution {
public:
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

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> parents(n + 1, 0);
        vector<int> edge1, edge2;
        
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            // A node has two parents
            if (parents[v] > 0) {
                // first visted edge
                edge1 = {parents[v], v};
                // current (later) visted edge
                edge2 = {u, v};
            }
            parents[v] = u;
        }
        
        DSU dsu(n);
        
        // cycle detection
        for(auto& edge: edges) {
            // Skipping edge2 (hypothetically we delete this edge to check if edge1 is forming a cycle)
            if (edge == edge2) continue;

            int u = edge[0];
            int v = edge[1];

            // Both u and v are already in the tree
            if (dsu.sameSet(u, v)) {
                // since edge2 is skipped, so edge1 (if exists) is the culprit forming a cycle
                return edge1.empty() ? edge : edge1;
            }
            
            dsu.unionSet(u, v);
        }
        
        // when no cycle is detected above
        return edge2;
    }
};