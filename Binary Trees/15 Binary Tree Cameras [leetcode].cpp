// https://leetcode.com/problems/binary-tree-cameras/
// https://youtu.be/VBxiavZYfoA

/*
You are given the root of a binary tree. We install cameras on the tree nodes 
where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.
*/



class Solution {
public:
#define inf 1e9
    map<tuple<TreeNode*, bool, bool>, int> dp;

    int fun(TreeNode* root, bool isCam, bool isParCam) {
        if (!root) {
            if (isCam) return inf;
            return 0;
        }

        if (dp.count({root, isCam, isParCam})) return dp[ {root, isCam, isParCam}];

        int x = inf, y = inf, z = inf;
        if (isCam) {
            // child may or may not have camera
            x = 1 + min(fun(root->left, 0, 1), fun(root->left, 1, 1)) + min(fun(root->right, 0, 1), fun(root->right, 1, 1));
        } else {
            if (isParCam) {
                // child may or may not have camera
                y = min(fun(root->left, 0, 0), fun(root->left, 1, 0)) + min(fun(root->right, 0, 0), fun(root->right, 1, 0));
            } else {
                // atleast one child must have a camera and other child may or may not have camera
                int op1 = fun(root->left, 1, 0) + min(fun(root->right, 0, 0), fun(root->right, 1, 0));
                int op2 = fun(root->right, 1, 0) + min(fun(root->left, 0, 0), fun(root->left, 1, 0));
                z = min(op1, op2);
            }
        }

        return dp[ {root, isCam, isParCam}] = min({x, y, z});
    }

    int minCameraCover(TreeNode* root) {
        dp.clear();
        return min(fun(root, 0, 0), fun(root, 1, 0));
    }
};



















class Solution {
public:
    #define inf 1e9
    map<pair<TreeNode*, pair<bool, bool>>, int> dp;
    
    int fun(TreeNode* root, bool isCam, bool isParCam) {
        if(!root) {
            if(isCam) return inf;
            return 0;
        }
 
        if(dp.count({root, {isCam, isParCam}})) return dp[{root, {isCam, isParCam}}];
        
        int x = inf, y = inf, z = inf;
        if(isCam) {
            x = 1 + min(fun(root->left, 0, 1), fun(root->left, 1, 1)) + min(fun(root->right, 0, 1), fun(root->right, 1, 1));
        } else  if(isParCam) {
            y = min(fun(root->left, 0, 0), fun(root->left, 1, 0)) + min(fun(root->right, 0, 0), fun(root->right, 1, 0));
        } else {
            int op1 = fun(root->left, 1, 0) + min(fun(root->right, 0, 0), fun(root->right, 1, 0));
            int op2 = fun(root->right, 1, 0) + min(fun(root->left, 0, 0), fun(root->left, 1, 0));
            z = min(op1, op2);
        }
        
        return dp[{root, {isCam, isParCam}}] = min({x, y, z});
    }
    
    int minCameraCover(TreeNode* root) {
        dp.clear();
        return min(fun(root, 0, 0), fun(root, 1, 0));
    }
};
