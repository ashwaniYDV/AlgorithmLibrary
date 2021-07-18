// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/discuss/686268/Explanation-for-this-question-c%2B%2B-sample-code

/*
ok so there is concept of binary lifting, what is binary lifting ??

So any number can be expressed power of 2,
and we can greedily find that ,
by taking highest powers and taking the modulo,
or just utilising the inbuilt binary format that
how numbers are stored in computer,
so we know how to represent k in binary format,
so now using the same concept we will jump on k height using binary powers,
and remove the highest power ,
but here we must know the 2^i th height parent from every node,
so we will preprocess the tree as shown in the code,
so u could see as 2^i = 2^(i-1) + 2^(i-1),
so if we calculated 2^(i-1) th parent of every node beforehand
we could calculate 2^i th parent from that,
like 2^(i-1) th parent of 2^(i-1) th parent of the node,
right like 4th parent is 2nd parent of 2nd parent of node,
this is called binary lifting.

so now utilise the binary version of k and jump accordingly.
I have also made parent of 0 to -1,
so that I could stop if I went above the node.
*/

class TreeAncestor {
public:
    vector<vector<int> > LCA; // LCA[node][i] :::: [node]'s [2^i]th parent
    int height = 20;
    TreeAncestor(int n, vector<int>& parent) {
        // initialize
        LCA.resize(n, vector<int>(height + 1));
        
        // 2^0
        for(int i = 0; i < n; i++){
            LCA[i][0] = parent[i];
        }
        
        // 2^i
        for(int i = 1; i <= height; i++) {
            for(int node = 0; node < n; node ++) {
                int parNode = LCA[node][i-1];
                if(parNode != -1) 
                    LCA[node][i] = LCA[parNode][i - 1];
                else 
                    LCA[node][i] = -1;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i <= height; i++){
            if(k & (1 << i)){
                node = LCA[node][i];
                if(node == -1) return -1;
            }
        }

        return node;
    }
};
