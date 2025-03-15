// https://leetcode.com/problems/house-robber-iii/
/*
The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called root.
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that all houses in this place form a binary tree. 
It will automatically contact the police if two directly-linked houses were broken into on the same night.
Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
*/

class Solution {
public:
    // {notPick, pick}
    pair<int, int> f(TreeNode* root) {
        if(!root) return {0, 0};

        int notPick = 0, pick = root->val;

        pair<int, int> left = f(root->left);
        notPick += max(left.first, left.second);
        pick += left.first;

        pair<int, int> right = f(root->right);
        notPick += max(right.first, right.second);
        pick += right.first;

        return {notPick, pick};
    }

    int rob(TreeNode* root) {
        auto it = f(root);
        return max(it.first, it.second);
    }
};