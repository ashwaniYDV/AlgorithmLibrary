// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// https://youtu.be/aZNaLrVebKQ?si=aELAVt4C4VDK11oO

class Solution {
public:
    int n;
    
    TreeNode* f(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inIndex) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRootIdx = inIndex[root->val];
        int numsLeft = inRootIdx - inStart;

        root->left = f(preStart + 1, preStart + numsLeft, 
                    inStart, inRootIdx - 1, 
                    preorder, inorder, inIndex);
        root->right = f(preStart + numsLeft + 1, preEnd, 
                        inRootIdx + 1, inEnd, 
                        preorder, inorder, inIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();

        unordered_map<int, int> inIndex;
        for(int i = 0; i < n; i++) {
            inIndex[inorder[i]] = i;
        }

        return f(0, n-1, 
                0, n-1, 
                preorder, inorder, inIndex);
        
    }
};