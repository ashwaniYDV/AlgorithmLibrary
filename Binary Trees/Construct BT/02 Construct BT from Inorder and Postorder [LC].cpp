// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// https://youtu.be/LgLRTaEMRVc?si=s5ZDYed8u0b7SyPu

class Solution {
public:
    int n;
    
    TreeNode* f(int postStart, int postEnd, int inStart, int inEnd, vector<int>& postorder, vector<int>& inorder, unordered_map<int, int>& inIndex) {
        if(postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRootIdx = inIndex[root->val];
        int numsLeft = inRootIdx - inStart;

        root->left = f(postStart, postStart + numsLeft - 1, 
                    inStart, inRootIdx - 1, 
                    postorder, inorder, inIndex);
        root->right = f(postStart + numsLeft, postEnd - 1, 
                        inRootIdx + 1, inEnd, 
                        postorder, inorder, inIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();

        unordered_map<int, int> inIndex;
        for(int i = 0; i < n; i++) {
            inIndex[inorder[i]] = i;
        }

        return f(0, n-1, 
                0, n-1, 
                postorder, inorder, inIndex);
    }
};