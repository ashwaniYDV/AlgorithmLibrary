// https://leetcode.com/problems/all-possible-full-binary-trees/

/*
Problem:
Given an integer n, return a list of all possible full binary trees with n nodes. 
Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. 
You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.
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
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;
        
        if(start > end) {
            res.push_back(NULL);
            return res;
        }
        
        for(int i = start; i <= end; i++) {
            // these two lines solve TLE by ignoring unnacessary func calls
            if(start > (i-1) && (i+1) < end) continue;
            if(start < (i-1) && (i+1) > end) continue;
            
            vector<TreeNode*> left = helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);
            
            for(TreeNode* l: left) {
                for(TreeNode* r: right) {
                    // condition for full binary tree
                    if((r && l) || (!r && !l)) {
                        TreeNode* root = new TreeNode(0);
                        root->left = l;
                        root->right = r;

                        res.push_back(root);
                    }
                }
            }
        }
        
        return res;      
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n == 0) return vector<TreeNode*>();
        
        return helper(1, n);
    }
};
