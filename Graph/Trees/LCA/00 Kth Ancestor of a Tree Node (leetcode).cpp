// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

/*
sparse table(LCA array) and binary lifting
log2(5*1e4) = 15.609 === 20
*/

class TreeAncestor {
public:
    vector<vector<int> > LCA; // LCA[node][i] == [node] 's [2^i]th parent
    TreeAncestor(int n, vector<int>& parent) {
        // initialize
        LCA.resize(n, vector<int>(20));
        
        // 2^0
        for(int i = 0; i < n; i++) {
            LCA[i][0] = parent[i];
        }
        
        // 2^i
        for(int i = 1; i < 20; i++){
            for(int node = 0; node < n; node ++) {
                int parNode = LCA[node][i-1];
                if(parNode != -1) {
                  LCA[node][i] = LCA[parNode][i-1];
                } else {
                  LCA[node][i] = -1;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        // method 1
        // while(k) {
        //     int i = log2(k);
        //     node = LCA[node][i];
        //     if(node == -1) return -1;
        //     k -= (1 << i);
        // }
        
        // method 2
        for(int i = 20-1; i >= 0; i--) {
            if(k & (1 << i)) {
                node = LCA[node][i];
                if(node == -1) return -1;
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
