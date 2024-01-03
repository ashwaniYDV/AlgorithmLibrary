// https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
// https://www.geeksforgeeks.org/avl-tree-set-2-deletion/


/*
Insertion 
To make sure that the given tree remains AVL after every insertion, we must augment the standard BST insert operation to perform some re-balancing. 
Following are two basic operations that can be performed to re-balance a BST without violating the BST property (keys(left) < key(root) < keys(right)). 
1) Left Rotation 
2) Right Rotation


T1, T2 and T3 are subtrees of the tree rooted with y (on the left side) or x (on the right side)           
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
 
Keys in both of the above trees follow the following order:
 keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
So BST property is not violated anywhere.
*/



// Method 1

#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    int height;
    TreeNode(int d) {
        data = d;
        left = right = NULL;
        // new node is initially added at leaf
        height = 1;
    }
};

// A utility function to get height of the tree
int height(TreeNode *N) {
    if (!N) return 0;
    return N->height;
}

// A utility function to right rotate subtree rooted with y
TreeNode* rightRotate(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
TreeNode* leftRotate(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(TreeNode *N) {
    if (!N) return 0;
    return height(N->left) - height(N->right);
}

TreeNode* performrRotation(TreeNode *root) {
    // If the tree had only one node then return
    if (!root) return root;

    root->left = performrRotation(root->left);        
    root->right = performrRotation(root->right);

    // UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Imbalance
    if (balance > 1 && getBalance(root->left) >= 0) {
        root = rightRotate(root);
        return root;
    }

    // Left Right Imbalance
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
        return root;
    }

    // Right Right Imbalance
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
        return root;
    }

    // Right Left Imbalance
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
        return root;
    }

    /* return the (unchanged) node pointer */
    return root;
}

TreeNode* insert(TreeNode* root, int key) {
    /* Perform the normal BST rotation */
    if (!root) return new TreeNode(key);

    // Equal keys not allowed
    if (root->data == key) {
        return root;
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return performrRotation(root);
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Recursive function to delete a node with given key from subtree with given root.
// It returns root of the modified subtree.
TreeNode* deleteNode(TreeNode* root, int key) {
    // PERFORM STANDARD BST DELETE
    if (!root) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->data ) {
        root->left = deleteNode(root->left, key);
    }

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if ( key > root->data ) {
        root->right = deleteNode(root->right, key);
    }

    // if key is same as root's key, then this is the node to be deleted
    else {
        // Case 1: node has no child
        if (!root->left and !root->right) {
            root = NULL;
        }

        // Case 2: node with only one child
        else if (!root->left) {
            TreeNode* temp = root->right;
            *root = *temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            *root = *temp;
        }
        // Case 3: node with two children:
        else {
            // Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return performrRotation(root);
}

void preOrder(TreeNode *root) {
    if (!root) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    TreeNode *root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    /* The constructed AVL Tree would be
         9
        / \
        1 10
        / \ \
        0 5 11
        / / \
       -1 2 6
    */

    cout << "Preorder traversal of the constructed AVL tree is \n";
    inOrder(root);

    root = deleteNode(root, 10);

    /* The AVL Tree after deletion of 10
            1
           / \
           0 9
          / / \
        -1 5  11
          / \
          2 6
    */

    cout << "\nPreorder traversal after deletion of 10 \n";
    inOrder(root);
}

/*
Preorder traversal of the constructed AVL tree is 
9 1 0 -1 5 2 6 10 11 
Preorder traversal after deletion of 10 
1 0 -1 9 5 2 6 11 
*/















// Method 2

#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    int height;
    TreeNode(int d) {
        data = d;
        left = right = NULL;
        // new node is initially added at leaf
        height = 1;
    }
};

// A utility function to get height of the tree
int height(TreeNode *N) {
    if (!N) return 0;
    return N->height;
}

// A utility function to right rotate subtree rooted with y
TreeNode* rightRotate(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
TreeNode* leftRotate(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(TreeNode *N) {
    if (!N) return 0;
    return height(N->left) - height(N->right);
}

TreeNode* performrRotation(TreeNode *root) {
    // If the tree had only one node then return
    if (!root) return root;

    root->left = performrRotation(root->left);        
    root->right = performrRotation(root->right);

    // UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Imbalance
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Imbalance
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Imbalance
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Imbalance
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    /* return the (unchanged) node pointer */
    return root;
}

TreeNode* insert(TreeNode* root, int key) {
    /* Perform the normal BST rotation */
    if (!root) return new TreeNode(key);

    // Equal keys not allowed
    if (root->data == key) {
        return root;
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return performrRotation(root);
}

// Recursive function to delete a node with given key from subtree with given root.
// It returns root of the modified subtree.
TreeNode* deleteNode(TreeNode* root, int key) {
    // PERFORM STANDARD BST DELETE
    if (!root) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->data ) {
        root->left = deleteNode(root->left, key);
    }

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if ( key > root->data ) {
        root->right = deleteNode(root->right, key);
    }

    // if key is same as root's key, then this is the node to be deleted
    else {
        // Case 1: node has no child
        if (!root->left and !root->right) {
            root = NULL;
        }

        // Case 2: node with only one child
        else if (!root->left) {
            TreeNode* temp = root->right;
            *root = *temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            *root = *temp;
        }
        // Case 3: node with two children:
        else {
            // Get the inorder successor (smallest in the right subtree)
            TreeNode* succParent = root;

            // Find successor
            TreeNode* succ = root->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            // Delete successor.
            /*
            Since successor is always left child of its parent
            we can safely make successor's right
            right child as left of its parent.
            If there is no succ, then assign succ->right to succParent->right
            */
            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            // Copy Successor Data to root
            root->data = succ->data;

            // Delete Successor and return root
            delete succ;
        }
    }

    return performrRotation(root);
}

void inOrder(TreeNode *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    TreeNode *root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    /* The constructed AVL Tree would be
         9
        / \
        1 10
        / \ \
        0 5 11
        / / \
       -1 2 6
    */

    cout << "Inorder traversal of the constructed AVL tree is \n";
    inOrder(root);

    root = deleteNode(root, 10);

    /* The AVL Tree after deletion of 10
            1
           / \
           0 9
          / / \
        -1 5  11
          / \
          2 6
    */

    cout << "\nInorder traversal after deletion of 10 \n";
    inOrder(root);
}
