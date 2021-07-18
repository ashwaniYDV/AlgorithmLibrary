// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/

/*
Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.
You can return the answer in any order.
*/



// Method 1: (Optimized)

/*
             20
            /   \
           8      22
          / \
         4   12
            /  \
           10   14

There are two types of nodes to be considered. 
1) Nodes in the subtree rooted with target node. For example if the target node is 8 and k is 2, then such nodes are 10 and 14. 
2) Other nodes, may be an ancestor of target, or a node in some other subtree. For target node 8 and k is 2, the node 22 comes in this category.

Finding the first type of nodes is easy to implement. Just traverse subtrees rooted with the target node and decrement k in recursive call. 
When the k becomes 0, print the node currently being traversed. Here we call the function as kdistanceNodeDown().

How to find nodes of second type? 
For the output nodes not lying in the subtree with the target node as the root, we must go through all ancestors. 
For every ancestor, we find its distance from target node, let the distance be d.
Now we go to other subtree (if target was found in left subtree, then we go to right subtree and vice versa) of the ancestor 
and find all nodes at k - d distance from the ancestor.
Following is the implementation of the above approach. 


Note:
dl is distance of root's left child from target
thus dl+1 is Distance of root from target

dr is distance of root's right child from target
thus dr+1 is Distance of root from target
*/

class Solution {
public:
    vector<int> res;
    
    void kdistanceNodeDown(TreeNode *root, int k) {
        if (!root || k < 0)  return;

        if (k == 0) {
            res.push_back(root->val);
            return;
        }

        kdistanceNodeDown(root->left, k - 1);
        kdistanceNodeDown(root->right, k - 1);
    }

    // This function returns distance of root from target node, 
    // It returns -1 if target node is not present in tree rooted with root.
    int kdistanceNode(TreeNode* root, TreeNode* target , int k) {
        // Base Case: If tree is empty, return -1
        if (!root) return -1;

        // If target is same as root. Use the downward function to print all nodes at distance k in subtree rooted with target or root
        if (root == target) {
            kdistanceNodeDown(root, k);
            return 0;
        }

        // Recur for left subtree
        int dl = kdistanceNode(root->left, target, k);

        // Check if target node was found in left subtree
        if (dl != -1) {
             // If root is at distance k from target, print root
             // dl is Distance of root's left child from target
             if (dl + 1 == k) {
                 res.push_back(root->val);
             }

             // Else go to right subtree and print all k - dl - 2 distant nodes
             // Note that the right child is 2 edges away from left child
             else {
                 kdistanceNodeDown(root->right, k - dl - 2);
             }

             // Add 1 to the distance and return value for parent calls
             return 1 + dl;
        }

        // Note that we reach here only when node was not found in left subtree
        // Recur for right subtree
        int dr = kdistanceNode(root->right, target, k);
        if (dr != -1) {
            // dr is Distance of root's right child from target
            if (dr + 1 == k) {
                res.push_back(root->val);
            } else {
                kdistanceNodeDown(root->left, k - dr - 2);
            }
            
            return 1 + dr;
        }

        // If target was neither present in left nor in right subtree
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        res.clear();
        kdistanceNode(root, target, k);
        return res;
    }
};















// Method 2: (Naive memory)
class Solution {
public:
    vector<int> res;   
    map<TreeNode*, TreeNode*> parent;  
    map<TreeNode*, int> vis;
    
    void findParent(TreeNode* node) {
        if(!node ) return;
        
        if(node->left) {
            parent[node->left] = node;
            findParent(node->left);
        }
        if(node->right) {
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    void dfs(TreeNode* node, int k) {
        if(vis[node]) return;
        
        vis[node] = 1;
        
        if(k == 0) {
            res.push_back(node->val);
            return;
        }
        
        if(node->left) {
            dfs(node->left, k - 1);
        }
        if(node->right) {
            dfs(node->right, k - 1);
        }
        
        TreeNode* par = parent[node];
        if(par) dfs(par, k - 1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if( !root ) return {};
        findParent(root);
        
        dfs(target, k);
        return res;
    }
};
