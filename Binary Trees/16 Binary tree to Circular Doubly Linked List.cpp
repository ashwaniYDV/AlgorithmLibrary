// https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1/

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



class Solution {
  public:
    
    Node *concatenate(Node *leftList, Node *rightList) {
        if (!leftList) return rightList;
        if (!rightList) return leftList;
    
        Node *leftListLast = leftList->left;
        Node *rightListLast = rightList->left;
    
        leftList->left = rightListLast;
        rightList->left = leftListLast;
    
        leftListLast->right = rightList;
        rightListLast->right = leftList;
          
        return leftList;
    }

    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root) {
        //add code here.
        if (!root) return root;
    
        Node *leftList = bTreeToCList(root->left);
        Node *rightList = bTreeToCList(root->right);
    
        // make root circular
        root->left = root->right = root;
    
        return concatenate(concatenate(leftList, root), rightList);
    }
};








// GFG practise soln
class Solution
{
  public:
    // A function that appends rightList at the end
    // of leftList.
    Node *concatenate(Node *leftList, Node *rightList)
    {
        // If either of the list is empty
        // then return the other list
        if (leftList == NULL)
            return rightList;
        if (rightList == NULL)
            return leftList;
      
        // Store the last Node of left List
        Node *leftLast = leftList->left;
      
        // Store the last Node of right List
        Node *rightLast = rightList->left;
      
        // Connect the last node of Left List
        // with the first Node of the right List
        leftLast->right = rightList;
        rightList->left = leftLast;
      
        // Left of first node points to
        // the last node in the list
        leftList->left = rightLast;
      
        // Right of last node refers to the first
        // node of the List
        rightLast->right = leftList;
      
        return leftList;
    }
  
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
    //add code here.
        if (root == NULL)
            return NULL;
      
        // Recursively convert left and right subtrees
        Node *left = bTreeToCList(root->left);
        Node *right = bTreeToCList(root->right);
      
        // Make a circular linked list of single node
        // (or root). To do so, make the right and
        // left pointers of this node point to itself
        root->left = root->right = root;
      
        // Step 1 (concatenate the left list with the list 
        //         with single node, i.e., current node)
        // Step 2 (concatenate the returned list with the
        //         right List)
        return concatenate(concatenate(left, root), right);
    }
};
