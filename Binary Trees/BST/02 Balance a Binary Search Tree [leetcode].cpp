// https://leetcode.com/problems/balance-a-binary-search-tree/


// Method 2: AVL Tree

// Method 1: Using "Sorted array to height-balanced BST" concept
class Solution {
public:
    TreeNode* fun(int l, int r, vector<int>& nums) {
        // base case
        if(l > r) return NULL;

        int mid = ((l + r) >> 1);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = fun(l, mid - 1, nums);
        root->right = fun(mid + 1, r, nums);

        return root;
    }
    
    TreeNode* sortedArrayToHeightBalancedBST(vector<int>& nums) {
        return fun(0, nums.size() - 1, nums);
    }

    void inorder(TreeNode* root, vector<int>& nums) {
        if(!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;
        
        vector<int> nums;
        inorder(root, nums);

        return sortedArrayToHeightBalancedBST(nums);
    }
};
