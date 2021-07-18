// https://leetcode.com/problems/balanced-binary-tree/

/*
Given a binary tree, determine if it is height-balanced.

To check if a tree is height-balanced, get the height of left and right subtrees of every node. 
Return true if difference between heights is not more than 1 and left and right subtrees are balanced, otherwise return false. 
*/

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
    bool res;
    
    int check(TreeNode* root) {
        if(!root) return 0;
        
        int leftH = check(root->left);
        int rightH = check(root->right);
        
        if(abs(leftH - rightH) > 1) res = false;
        
        return 1 + max(leftH, rightH);
    }
    
    bool isBalanced(TreeNode* root) {
        res = true;
        check(root);
        return res;
    }
};
