// https://leetcode.com/problems/unique-binary-search-trees-ii/
// https://youtu.be/hQn61BjdA7M


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
