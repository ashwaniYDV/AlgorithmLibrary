// https://www.geeksforgeeks.org/rank-element-stream/

/*
DS design for getRank(x) of elements x in a stream.
Note: Rank is 0 based
*/

/*
Given a stream of integers, lookup the rank of a given integer x. 
Rank of an integer in-stream is “Total number of elements less than or equal to x (not including x)”.
If an element is not found in the stream or is smallest in stream, return -1. 
*/


/*
Method 1.1:
An efficient way is to use a Binary Search Tree. 
Each Node will hold the data value and size of its left subtree.
We traverse the tree from root and compare the root values to x. 
 
If root->data == x, return size of left subtree of root.
If x < root->data, return getRank(root->left)
If x > root->data, return size of leftSubtree + 1 + getRank(root->right).
*/


#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    int data, leftSize;
    Node *left, *right;
public:
    Node(int d) {
        data = d;
        leftSize = 0;
        left = right = NULL;
    }

    Node* insert(Node* root, int data) {
        if (!root)
            return new Node(data);

        if (data <= root->data) {
            root->left = insert(root->left, data);
            // Updating size of left subtree.
            root->leftSize++;
        } else {
            root->right = insert(root->right, data);
        }

        return root;
    }

    // Function to get Rank of a Node x.
    int getRank(Node* root, int x) {
        if(!root) return -1;

        if (root->data == x) return root->leftSize;

        if (x < root->data) {
            return getRank(root->left, x);
        } else {
            int rightSize = getRank(root->right, x);
            if(rightSize == -1 ) return -1;
            return (root->leftSize + 1 + rightSize);
        }
    }
};

// Driver code
int main() {
    int arr[] = { 1, 3, 4, 4, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = root->insert(root, arr[i]);
    }

    int x = 4;
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    x = 13;
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    x = 13;
    root = root->insert(root, x);
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    x = 3;
    root = root->insert(root, x);
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    root = root->insert(root, 15);
    x = 15;
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;
}



/*
Method 1.2
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    int data, subTreeSize;
    Node *left, *right;
public:
    Node(int d) {
        data = d;
        subTreeSize = 1;
        left = right = NULL;
    }

    int getSubTreeSize(Node* node) {
        if(!node) return 0;
        return node->subTreeSize;
    }

    Node* insert(Node* root, int data) {
        if (!root)
            return new Node(data);

        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        // Updating subTreeSize.
        root->subTreeSize = 1 + getSubTreeSize(root->left) + getSubTreeSize(root->right);

        return root;
    }

    // Function to get Rank of a Node x.
    int getRank(Node* root, int x) {
        if(!root) return -1;

        if (root->data == x) return getSubTreeSize(root->left);

        if (x < root->data) {
            return getRank(root->left, x);
        } else {
            int rightSize = getRank(root->right, x);
            if(rightSize == -1 ) return -1;
            int leftSize = getSubTreeSize(root->left);
            return (leftSize + 1 + rightSize);
        }
    }
};

// Driver code
int main() {
    int arr[] = { 1, 3, 4, 4, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = root->insert(root, arr[i]);
    }

    int x = 4;
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    x = 13;
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    x = 13;
    root = root->insert(root, x);
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    x = 3;
    root = root->insert(root, x);
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;

    root = root->insert(root, 15);
    x = 15;
    cout << "Rank of " << x << " in stream is: " << root->getRank(root, x) << endl;
}






/*
Method 2: Use BIT if elements range is <= 1e6
*/
