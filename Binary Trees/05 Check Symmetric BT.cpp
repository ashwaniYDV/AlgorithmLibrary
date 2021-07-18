// https://leetcode.com/problems/symmetric-tree/

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Symmetric:

                2
              /   \
             3     3
           /  \   /  \
          5   9   9   5

                2
              /   \
             3     3
           /  \   /  \
          5   9   9   5
         /             \
        4               4
        
Not Symmetric:
                2
              /   \
             1     3
           /  \   /  \
          5   6   9   5
*/


class Solution {
public:
    bool fun(TreeNode *root1, TreeNode* root2) {
        if(!root1) return !root2;
        if(!root2) return !root1;
        
        return (root1->val == root2->val) && fun(root1->left, root2->right) && fun(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return fun(root->left, root->right);
    }
};
