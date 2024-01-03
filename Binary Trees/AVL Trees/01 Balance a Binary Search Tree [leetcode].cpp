// https://leetcode.com/problems/balance-a-binary-search-tree/

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
    map<TreeNode*, int> NodeToHeight;
    
    // A utility function to get height of the tree
    int height(TreeNode* N) {
        if(!N) return 0;
        return NodeToHeight[N];
    }
        
    // A utility function to right rotate subtree rooted with y
    TreeNode* rightRotate(TreeNode *y) {
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        NodeToHeight[y] = max(height(y->left), height(y->right)) + 1;
        NodeToHeight[x] = max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // A utility function to left rotate subtree rooted with x
    TreeNode* leftRotate(TreeNode *x) {
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        NodeToHeight[x] = max(height(x->left), height(x->right)) + 1;
        NodeToHeight[y] = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Get Balance factor of node N
    int getBalance(TreeNode *N) {
        if (!N) return 0;
        return height(N->left) - height(N->right);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        return left && right && abs(getBalance(root)) <= 1;                    
    }

    TreeNode* performrRotation(TreeNode *root) {
        // If the tree had only one node then return
        if (!root) return root;

        root->left = performrRotation(root->left);        
        root->right = performrRotation(root->right);    

        // UPDATE HEIGHT OF THE CURRENT NODE
        NodeToHeight[root] = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Imbalance
        if (balance > 1 && getBalance(root->left) >= 0) {
            root = rightRotate(root);
            return root;
        }

        // Left Right Imbalance
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
            return root;
        }

        // Right Right Imbalance
        if (balance < -1 && getBalance(root->right) <= 0) {
            root = leftRotate(root);
            return root;
        }

        // Right Left Imbalance
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
            return root;
        }

        /* return the (unchanged) node pointer */
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;
        
        root = performrRotation(root);
        
        // comment out this _if block_ if you want to see the solution to fail for some testcases like
		// [1,null,15,14,17,7,null,null,null,2,12,null,3,9,null,null,null,null,11]
        if(!isBalanced(root)) {
            return balanceBST(root);
        }
        return root;
    }
};
