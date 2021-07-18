// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// https://youtu.be/_-QHfMDde90


// Normal Binary Tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if (!root || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        // both left and right are not null, we found our result
        return root;
    }
};












// Binary Search Tree

Node* LCA(Node *root, int n1, int n2) {
    if (!root) return root;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2) return LCA(root->left, n1, n2);


    // If both n1 and n2 are greater than  root, then LCA lies in right
    if (root->data < n1 && root->data < n2)  return LCA(root->right, n1, n2);


    return root;
}
