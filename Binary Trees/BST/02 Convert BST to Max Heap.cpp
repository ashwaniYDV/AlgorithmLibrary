// https://www.geeksforgeeks.org/convert-bst-to-max-heap/
// https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1

/*
Given a Binary Search Tree which is also a Complete Binary Tree. 
The problem is to convert a given BST into a Special Max Heap with the condition that 
all the values in the left subtree of a node should be less than all the values in the right subtree of the node. 
This condition is applied on all the nodes in the so converted Max Heap. 

Examples:  

Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  
 
Output :       7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
*/



/*
Approach 
========
Create an array arr[] of size n, where n is the number of nodes in the given BST. 
Perform the inorder traversal of the BST and copy the node values in the arr[] in sorted order. 
Now perform the postorder traversal of the tree. 
While traversing the root during the postorder traversal, one by one copy the values from the array arr[] to the nodes. 
*/


class Solution{
public:
    vector<int> a;
    int i;

    void inorder(Node *root) {
        if(!root) return;
        
        inorder(root->left);
        a.push_back(root->data);
        inorder(root->right);
    }
    
    void postorder(Node *root) {
        if(!root) return;
        
        postorder(root->left);
        postorder(root->right);
        root->data = a[i++];
    }
    
    void convertToMaxHeapUtil(Node* root) {
        a.clear();
        i = 0;
        inorder(root);
        postorder(root);
    }    
};
