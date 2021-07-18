// https://leetcode.com/problems/redundant-connection-ii/

/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, 
plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), 
with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, 
where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array.
*/




// DSU with indegree
/*
Case1: A vertex has no duplicate parents. Return the first edge that creates the loop (Same as Redundant Connection I)
Case2: A node has two parents {u1, u2}:
      Case2.1: Return {u1, v} or {u2, v} that creates the loop
      Case2.2: Return the second edge that creates duplicate parent
*/

class Solution {
    struct DSU {
        vector<int> par;

        void init(int n) {
            par.resize(n + 1, -1);
        }

        int find_par(int a){
            if(par[a] < 0)
                return a;
            return par[a] = find_par(par[a]);
        }

        void union_set(int a, int b){
            a = find_par(a);
            b = find_par(b);
            if(a == b)
                return;
            if(par[a] > par[b])
                swap(a, b);
            par[a] += par[b];
            par[b] = a;
        }
    };
public:
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
                // current(later) visted edge
                edge2 = {u, v};
                
                // Delete the later edge
                edge[0] = edge[1] = -1;
            }
            parents[v] = u;
        }
        
        DSU obj;
        obj.init(n);
        
        // cycle detection
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            // Invalid edge (we deleted in step 1)
            if (u < 0 || v < 0) continue;
            
            int parU = obj.find_par(u);
            int parV = obj.find_par(v);

            // Both u and v are already in the tree
            if (parU == parV) {
                return edge1.empty() ? edge : edge1;
            }
            
            obj.union_set(u, v);
        }
        
        // when no cycle is detected above
        return edge2;
    }
};
