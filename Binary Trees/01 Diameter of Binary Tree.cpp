// https://leetcode.com/problems/diameter-of-binary-tree/

/*
The question can be solved by small modification to program of Height of tree.
The idea is quite simple. Max value of Height(leftSubtree)+Height(rightSubtree) (at any node ) is the diameter. 
Keep track of maxium diameter duing traversal and find the height of the tree.

So although the longest path doesn't have to go through the root node, it has to pass the root node of some subtree of the tree 
(because it has to be from one leaf node to another leaf node, otherwise we can extend it for free). 
The longest path that passes a given node as the ROOT node is T = left_height+right_height. So you just calculate T for all nodes and output the max T.
*/


class Solution {
public:
    int diameter = 0;
    
    int go(TreeNode* root) {
        if(!root) return 0;
        
        int leftSubtreeDepth = go(root->left);
        int rightSubtreeDepth = go(root->right);
        
        diameter = max(diameter, leftSubtreeDepth+rightSubtreeDepth);
        
        int height = max(leftSubtreeDepth, rightSubtreeDepth) + 1;
        return height;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        go(root);
        return diameter;
    }
};
