// O(n^2)
class Solution {
public:
    void build(TreeNode* &root, int val) {
        if(!root) {
            root = new TreeNode(val);
            return;
        }
        if(val <= root->val) {
            build(root->left, val);
        } else {
            build(root->right, val);
        }  
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int x: preorder) {
            build(root, x);
        }
        return root;
    }
};






/*
pos variable is taken as an address since we want to instantly update pos for any function called in the stack 
so that the array element is used only once in process of building the BST
*/

// O(n)
class Solution {
public:
    int n;
    TreeNode* build(vector<int>&preorder, int &pos, int min, int max){
        if (pos >= n) return NULL;
        int val = preorder[pos];
        if (val > max || val <min) return NULL;
        
        TreeNode* node = new TreeNode(val);
        pos++;
        node->left = build(preorder, pos, min, val);
        node->right = build(preorder, pos, val, max);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->n = preorder.size();
        if(n == 0) return NULL;
        int pos = 0;
        return build(preorder, pos, INT_MIN, INT_MAX);
    }
};





// O(n)
class Solution {
public:
    int n, pos = 0;
    TreeNode* build(vector<int>&preorder, int min, int max){
        if (pos >= n) return NULL;
        int val = preorder[pos];
        if (val > max || val <min) return NULL;
        
        TreeNode* node = new TreeNode(val);
        pos++;
        node->left = build(preorder, min, val);
        node->right = build(preorder, val, max);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->n = preorder.size();
        if(n == 0) return NULL;
        pos = 0;
        return build(preorder, INT_MIN, INT_MAX);
    }
};
