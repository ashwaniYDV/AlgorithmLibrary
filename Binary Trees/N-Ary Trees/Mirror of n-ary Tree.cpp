// Method 1
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    vector<Node *>child;
    Node(int data) {
        key = data;
    }
};

void mirrorTree(Node * root) {
    // Base case: Nothing to do if root is NULL
    if (root == NULL) return;

    // Number of children of root
    int n = root->child.size();

    // Calling mirror function for each child
    for (int i = 0; i < n; i++)
        mirrorTree(root->child[i]);

    // Reverse vector (variable sized array) of child pointers
    reverse(root->child.begin(), root->child.end());
}

// Prints the n-ary tree level wise
void printNodeLevelWise(Node * root) {
    if (root == NULL) return;

    queue<Node *>q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node * p = q.front();
            q.pop();
            cout << p->key << " ";

            for (int i = 0; i < p->child.size(); i++)
                q.push(p->child[i]);
        }
        cout << endl;
    }
}

int main() {
    Node *root = new Node(10);
    (root->child).push_back(new Node(2));
    (root->child).push_back(new Node(34));
    (root->child).push_back(new Node(56));
    (root->child).push_back(new Node(100));
    (root->child[2]->child).push_back(new Node(1));
    (root->child[3]->child).push_back(new Node(7));
    (root->child[3]->child).push_back(new Node(8));
    (root->child[3]->child).push_back(new Node(9));

    cout << "Level order traversal Before Mirroring\n";
    printNodeLevelWise(root);

    mirrorTree(root);

    cout << "\nLevel order traversal After Mirroring\n";
    printNodeLevelWise(root);

    return 0;
}














// Method 2
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    vector<Node *>child;
    Node(int data) {
        key = data;
    }
};

void mirrorTree(Node * root) {
    // Base case: Nothing to do if root is NULL
    if (root == NULL) return;

    // Number of children of root
    int n = root->child.size();

    // Reverse vector (variable sized array) of child pointers
    reverse(root->child.begin(), root->child.end());

    // Calling mirror function for each child
    for (int i = 0; i < n; i++)
        mirrorTree(root->child[i]);
}

// Prints the n-ary tree level wise
void printNodeLevelWise(Node * root) {
    if (root == NULL) return;

    queue<Node *>q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node * p = q.front();
            q.pop();
            cout << p->key << " ";

            for (int i = 0; i < p->child.size(); i++)
                q.push(p->child[i]);
        }
        cout << endl;
    }
}

int main() {
    Node *root = new Node(10);
    (root->child).push_back(new Node(2));
    (root->child).push_back(new Node(34));
    (root->child).push_back(new Node(56));
    (root->child).push_back(new Node(100));
    (root->child[2]->child).push_back(new Node(1));
    (root->child[3]->child).push_back(new Node(7));
    (root->child[3]->child).push_back(new Node(8));
    (root->child[3]->child).push_back(new Node(9));

    cout << "Level order traversal Before Mirroring\n";
    printNodeLevelWise(root);

    mirrorTree(root);

    cout << "\nLevel order traversal After Mirroring\n";
    printNodeLevelWise(root);

    return 0;
}
