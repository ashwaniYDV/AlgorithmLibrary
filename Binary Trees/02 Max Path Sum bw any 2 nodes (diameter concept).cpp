// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/

/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any path.

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/

class Solution {
public:
    int res = -1e9;
    
    int go(TreeNode* root) {
        if(!root) return 0;
        
        int ls = go(root->left);
        int rs = go(root->right);
        
        res = max(res, ls + rs + root->val);
        
        int heightSum = max(ls, rs) + root->val;
        return max(heightSum, 0);
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        go(root);
        return res;
    }
};
