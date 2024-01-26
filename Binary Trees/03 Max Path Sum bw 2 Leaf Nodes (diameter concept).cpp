// https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

/*
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another leaf node.
NOTE: Here Leaf node is a node which is connected to exactly one different node.
*/

// Method 1
class Solution {
public:
    int fun(Node *root, int &res) {
        if (!root) return 0;

        // Find the maximum path sum in the left and right subtrees
        int ls = fun(root->left, res);
        int rs = fun(root->right, res);

        // we can update res only when both left and right child exist
        if (root->left && root->right) {
            res = max(res, ls + rs + root->data);
            return max(ls, rs) + root->data;
        }
        
        if(!root->left) return rs + root->data;
        if(!root->right) return ls + root->data;
    }
    
    // Function to find the maximum path sum
    int maxPathSum(Node *root) {
        int res = INT_MIN;
        int heightSum = fun(root, res);
        
        //--- for test case ---
        //          7
        //         /  \              
        //      Null  -3
        // value of res will be INT_MIN but the answer is 4, which is returned by fun() as heightSum
        
        if (!root->left || !root->right) {
            res = max(res, heightSum);
        }
        
        return res;
    }
};


// Method 2
class Solution {
public:
    int fun(Node *root, int &res) {
        if (!root) return 0;

        // Find the maximum path sum in the left and right subtrees
        int ls = fun(root->left, res);
        int rs = fun(root->right, res);
        
        // case 1
        if(!root->left) return rs + root->data;
        // case 2
        if(!root->right) return ls + root->data;

        // we can update res only when both left and right child exist
        res = max(res, ls + rs + root->data);
        return max(ls, rs) + root->data;
    }
    
    // Function to find the maximum path sum
    int maxPathSum(Node *root) {
        int res = INT_MIN;
        int heightSum = fun(root, res);
        
        //--- for test case ---
        //          7
        //         /  \              
        //      Null  -3
        // value of res will be INT_MIN but the answer is 4, which is returned by fun() as heightSum
        
        if (!root->left || !root->right) {
            res = max(res, heightSum);
        }
        
        return res;
    }
};
