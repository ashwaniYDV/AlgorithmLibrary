// https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723
// https://youtu.be/fnmisPM6cVo
// https://www.techiedelight.com/fix-children-sum-property-binary-tree/


/*
Given a binary tree, you need to modify the value of its nodes, such that the tree holds the Children sum property.
A binary tree is said to follow the children sum property if, for every node of that tree, 
the value of that node is equal to the sum of the value(s) of all of its children nodes (left child and the right child).
Note :
 1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
 2. You can not change the structure of the original binary tree.
 3. A binary tree is a tree in which each node has at most two children.      
 4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.
*/



/*************************************************************
Following is the Binary Tree node structure

template<typename T>
class BinaryTreeNode {
public :
    T data;
    BinaryTreeNode < T > *left;
    BinaryTreeNode < T > *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
*************************************************************/

int getChildSum(BinaryTreeNode < int > * root) {
    int childSum = 0;
    if(root->left) {
        childSum += root->left->data; 
    }
    if(root->right) {
        childSum += root->right->data; 
    }
    return childSum;
}

void reorder(BinaryTreeNode < int > * root) {
    if(root == NULL) return; 
    
    int childSum = getChildSum(root);
    
    if(childSum > root->data) {
        root->data = childSum;
    } else {
        if(root->left) root->left->data = root->data; 
        if(root->right) root->right->data = root->data; 
    }
    
    reorder(root->left); 
    reorder(root->right); 
    
    int total = getChildSum(root);
    if(root->left or root->right) root->data = total;  
}
void changeTree(BinaryTreeNode < int > * root) {
    reorder(root); 
} 
