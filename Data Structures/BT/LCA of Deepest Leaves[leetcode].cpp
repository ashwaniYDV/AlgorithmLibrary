// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> depth;
    int countDepth(TreeNode* root){
        if(!root)
            return 0;
        if(!depth.count(root))
            depth[root] = 1 + max(countDepth(root->left), countDepth(root->right));
        return depth[root];
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return NULL;
        int lcount = countDepth(root->left);
        int rcount = countDepth(root->right);
        if(lcount == rcount)
            return root;
        else if(lcount < rcount)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
};
