// https://leetcode.com/problems/flip-equivalent-binary-trees/description/

/*
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

 
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.

Constraints:
The number of nodes in each tree is in the range [0, 100].
Each tree will have unique node values in the range [0, 99].
*/



        
        
/*
Two non-null trees are flip equivalent if:
case 1: (no flip case)
    Left subtree of tree1 is flip equivalent with left subtree of tree2 and 
    right subtree of tree1 is flipequivalent with right subtree of tree2
case 2: (flip case)
    Right subtree of tree1 is flip equivalent with left subtree of tree2 and 
    left subtree of tree1 is flipequivalent with right subtree of tree2
*/
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return 1;
        if((!root1 && root2) || (root1 && !root2)) return 0;
        if(root1->val != root2->val) return 0;

        // case 1: no flipping (matching both sub-trees individually without flipping)
        if(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) {
            return 1;
        }

        // case 2: flipping root1 (matching both sub-trees individually by flipping root1)
        if(flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right)) {
            return 1;
        }

        return 0;
    }
};