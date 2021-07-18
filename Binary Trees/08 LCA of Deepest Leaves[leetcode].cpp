/*
2 questions same solution.
*/


// Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

class Solution {
public:
    unordered_map<TreeNode*, int> depth;
    
    int countDepth(TreeNode* root){
        if(!root) return 0;
        
        if(depth.count(root)) depth[root];
        
        return depth[root] = 1 + max(countDepth(root->left), countDepth(root->right));
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;
        
        int ldepth = countDepth(root->left);
        int rdepth = countDepth(root->right);
        
        if(ldepth == rdepth) return root;
        
        if(ldepth < rdepth)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
};












// Smallest Subtree with all the Deepest Nodes
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

/*
Given the root of a binary tree, the depth of each node is the shortest distance to the root.
Return the smallest subtree such that it contains all the deepest nodes in the original tree.
A node is called the deepest if it has the largest depth possible among any node in the entire tree.
The subtree of a node is tree consisting of that node, plus the set of all descendants of that node.
*/

class Solution {
public:
    unordered_map<TreeNode*, int> depth;
    
    int countDepth(TreeNode* root){
        if(!root) return 0;
        
        if(depth.count(root)) depth[root];
        
        return depth[root] = 1 + max(countDepth(root->left), countDepth(root->right));
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return NULL;
        
        int ldepth = countDepth(root->left);
        int rdepth = countDepth(root->right);
        
        if(ldepth == rdepth) return root;
        
        if(ldepth < rdepth)
            return subtreeWithAllDeepest(root->right);
        else
            return subtreeWithAllDeepest(root->left);
    }
};
