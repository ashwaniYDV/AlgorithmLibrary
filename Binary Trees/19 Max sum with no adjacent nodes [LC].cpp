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
    void dfs(TreeNode* root, map<pair<TreeNode*, int>, int>& dp) {
        if(!root) return;

        int sum0 = 0, sum1 = root->val;

        if(root->left) {
            dfs(root->left, dp);

            sum0 += max(dp[{root->left, 0}], dp[{root->left, 1}]);
            sum1 += dp[{root->left, 0}];
        }

        if(root->right) {
            dfs(root->right, dp);

            sum0 += max(dp[{root->right, 0}], dp[{root->right, 1}]);
            sum1 += dp[{root->right, 0}];
        }

        dp[{root, 0}] = sum0;
        dp[{root, 1}] = sum1;
    }

    int rob(TreeNode* root) {
        map<pair<TreeNode*, int>, int> dp;
        dfs(root, dp);
        return max(dp[{root, 0}], dp[{root, 1}]);
    }
};