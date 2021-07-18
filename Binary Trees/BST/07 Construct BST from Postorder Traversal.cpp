// O(n)
class Solution {
public:
    int n, pos;
    TreeNode* build(vector<int>&postorder, int min, int max){
        if (pos < 0) return NULL;
        int val = postorder[pos];
        if (val > max || val <min) return NULL;
        
        TreeNode* node = new TreeNode(val);
        pos--;
        // reverse order call then preorder problem
        node->right = build(postorder, val, max);
        node->left = build(postorder, min, val);
        
        return node;
    }
    TreeNode* bstFromPostorder(vector<int>& postorder) {
        this->n = postorder.size();
        if(n == 0) return NULL;
        pos = n - 1;
        return build(postorder, INT_MIN, INT_MAX);
    }
};
