// https://www.lintcode.com/problem/375/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return: root of new tree
     */
    
    TreeNode* dfs(TreeNode* root) {
        if(!root) return root;
        
        TreeNode* cloned = new TreeNode(root->val);
        
        if(root->left) {
            cloned->left = dfs(root->left);
        }
        if(root->right) {
            cloned->right = dfs(root->right);
        }

        return cloned;
    }

    TreeNode * cloneTree(TreeNode * root) {
        return dfs(root);
    }
};
