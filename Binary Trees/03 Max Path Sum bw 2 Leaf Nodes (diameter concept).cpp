// https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

/*
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another leaf node.
NOTE: Here Leaf node is a node which is connected to exactly one different node.
*/


class Solution {
public:
    int fun(Node *root, int &res) {
        if (!root) return 0;

        // Find the maximum path sum in the left and right subtrees
        int ls = fun(root->left, res);
        int rs = fun(root->right, res);

        // If both left and right children exist
        if (root->left && root->right) {
            res = max(res, ls + rs + root->data);
            return max(ls, rs) + root->data;
        }
        
        // Return the sum of the maximum sum path till the current root node
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
        
        // if (res == INT_MIN) {
        if (!root->left || !root->right) {
            return heightSum;
        }
        
        return res;
    }
};
