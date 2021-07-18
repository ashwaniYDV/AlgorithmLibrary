// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
// https://youtu.be/lQIXz5NJYLs



/* BST Node
struct Node {
    int key;
    struct Node *left, *right;
};
*/

Node *inorderPredecessor(Node *root) {
    Node *p = root->left;
    while (p->right) {
        p = p->right;
    }
    return p;
}

Node *inorderSuccessor(Node *root) {
    Node *s = root->right;
    while (s->left) {
        s = s->left;
    }
    return s;
}

// This function finds predecessor and successor of key in BST and sets their value
void findPreSuc(Node* root, Node*& predecessor, Node*& successor, int key) {
    if (!root) return;

    if (root->key == key) {
        if (root->left) predecessor = inorderPredecessor(root);
        if (root->right) successor = inorderSuccessor(root);
        return;
    }

    if (key < root->key) {
        successor = root;
        findPreSuc(root->left, predecessor, successor, key);
    }

    if (key > root->key) {
        predecessor = root;
        findPreSuc(root->right, predecessor, successor, key);
    }
}
