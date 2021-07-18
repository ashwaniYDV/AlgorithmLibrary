// https://youtu.be/0ca1nvR0be4
// https://www.lintcode.com/problem/878/

/*
Example 1:
Input: {1,#,2,3,4}
Output: [1,3,4,2]
Explanation: 
  1
   \
    2
   / \
  3   4
  The root doesn't have left subtree, so the root itself is left boundary.
  The leaves are node 3 and 4.
  The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
  So order them in anti-clockwise without duplicates and we have [1,3,4,2].
  

Example 2:
Input: {1,2,3,4,5,6,#,#,#,7,8,9,10}
Output: [1,2,4,7,8,9,10,6,3]
Explanation: 
          1
     /          \
    2            3
   / \          / 
  4   5        6   
     / \      / \
    7   8    9  10  
  The left boundary are node 1,2,4. (4 is the left-most node according to definition)
  The leaves are node 4,7,8,9,10.
  The right boundary are node 1,3,6,10. (10 is the right-most node).
  So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
*/





class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    
    void addLeftBoundary(TreeNode* root, vector<int> &res) {
        TreeNode* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->val);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    
    void addRightBoundary(TreeNode* root, vector<int> &res) {
        TreeNode* cur = root->right;
        vector<int> tmp;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->val);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = tmp.size()-1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
    }
    
    // add leaves traversing by inorder traversal 
    // (since it gaurantees sortedness and leaf nodes are sorted from left to right in BST)
    void addLeaves(TreeNode* root, vector<int>& res) {
        if(!root) return;
        
        addLeaves(root->left, res);
        if (isLeaf(root)) {
            res.push_back(root->val);
        }
        addLeaves(root->right, res);
    }

    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        vector<int> res;
        if (!root) return res;

        if (!isLeaf(root)) res.push_back(root->val);

        addLeftBoundary(root, res); 
        // add leaf nodes
        addLeaves(root, res);
        addRightBoundary(root, res); 
        
        return res;
    }
};
