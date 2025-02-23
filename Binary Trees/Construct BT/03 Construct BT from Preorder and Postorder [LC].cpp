// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
// https://youtu.be/4jSGuXq_XLQ?si=_QzPg5nPmGjrFsvy

class Solution {
public:
    int n;
    
    TreeNode* f(int preStart, int preEnd, int postStart, vector<int>& preorder, unordered_map<int, int>& postIndex) {
        if(preStart > preEnd) return nullptr;
        if(preStart == preEnd) return new TreeNode(preorder[preStart]);

        TreeNode* root = new TreeNode(preorder[preStart]);

        int leftSubtreeRoot = preorder[preStart + 1];
        int leftSubtreeSize = postIndex[leftSubtreeRoot] - postStart + 1;

        root->left = f(preStart + 1, preStart + leftSubtreeSize, 
                    postStart, 
                    preorder, postIndex);
        root->right = f(preStart + leftSubtreeSize + 1, preEnd, 
                        postStart + leftSubtreeSize, 
                        preorder, postIndex);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        n = preorder.size();

        unordered_map<int, int> postIndex;
        for(int i = 0; i < n; i++) {
            postIndex[postorder[i]] = i;
        }

        return f(0, n-1, 
                0,
                preorder, postIndex);
    }
};