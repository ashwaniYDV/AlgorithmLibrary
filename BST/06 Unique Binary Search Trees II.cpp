// https://leetcode.com/problems/unique-binary-search-trees-ii/
// https://youtu.be/hQn61BjdA7M

/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. 
Return the answer in any order.
*/


class Solution {
public:
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;
        
        if(start > end) {
            res.push_back(NULL);
            return res;
        }
        
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> left = helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);
            
            for(TreeNode* l: left) {
                for(TreeNode* r: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    
                    res.push_back(root);
                }
            }
        }
        
        return res;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        
        return helper(1, n);
    }
};
