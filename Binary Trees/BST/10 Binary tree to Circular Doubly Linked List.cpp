// https://www.scaler.com/problems/binary-tree-to-circular-doubly-linked-list/

/*
Given a binary tree convert it into circular doubly linked list based on the following rules:
a) The left and right pointers in nodes are to be used as previous and next pointers respectively in converted Circular Linked List.
b) The order of nodes in List must be same as Inorder of the given Binary Tree.
c) The first node of Inorder traversal must be the head node of the Circular List.

NOTE: You are expected to convert the binary tree into Doubly linked list in place.



Input:
      20 
     /  \
    8    22
    
Output:
     _____________
    |             |
    8 <-> 20 <-> 22
    |_____________|

*/



/*
Hint 1
Think of recursively concatenating the left and right subtree of the tree into a circular double linked list.

Given the root of the tree, we will try to form the circular double linked list for each left and right subtree seperately 
and then concatenate each circular double linked list.
We can do this recursively, first for left subtree and then for right subtree.

Now traverse the given tree:

-> Recursively convert left subtree to a circular DLL. Let the converted list be leftlist.
-> Recursively convert right subtree to a circular DLL. Let the converted list be rightlist.
-> Make a circular linked list of root of the tree, make left and right of root to point to itself.
-> Concatenate leftlist with list of single root node.
-> Concatenate the list produced in step above with rightList.

To Concatenate two circular DLLs, we will follow below steps:

-> Get the last node of the leftlist. Retrieving the last node is an O(1) operation, since the prev pointer of the head points to the last node of the list.
-> Connect it with the first node of the right list
-> Get the last node of the second list
-> Connect it with the head of the list.
*/




/*
Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

TreeNode *concatenate(TreeNode *leftList, TreeNode *rightList) {
    if (!leftList) return rightList;
    if (!rightList) return leftList;

    TreeNode *leftListLast = leftList->left;
    TreeNode *rightListLast = rightList->left;

    rightList->left = leftListLast;
    leftList->left = rightListLast;

    if (leftListLast) leftListLast->right = rightList;

    if (rightListLast) rightListLast->right = leftList;
    return leftList;
}

TreeNode *bTreeToCList(TreeNode *root) {
    if (!root) return root;

    TreeNode *leftList = bTreeToCList(root->left);
    TreeNode *rightList = bTreeToCList(root->right);

    // make root circular
    root->left = root->right = root;

    return concatenate(concatenate(leftList, root), rightList);
}

TreeNode *solve(TreeNode *A) {
    return bTreeToCList(A);
}
