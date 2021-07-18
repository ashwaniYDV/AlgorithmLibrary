// https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

/*
Normal Solution:
Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca) 

Better Solution: 
We first find the LCA of two nodes. Then we find the distance from LCA to two nodes. 
*/


class Solution {
public:
    Node* LCA(Node * root, int n1, int n2) {
        if (!root || root->data == n1 || root->data == n2) {
            return root;
        }

        Node* left = LCA(root->left, n1, n2);
        Node* right = LCA(root->right, n1, n2);

        if (!left) return right;
        if (!right) return left;
        return root;
    }

    // Returns level of data k if it is present in tree, otherwise returns -1
    int findLevel(Node *root, int k, int level) {
        if (!root) return -1;
        if (root->data == k) return level;

        int left = findLevel(root->left, k, level + 1);
        if (left == -1) return findLevel(root->right, k, level + 1);
        return left;
    }

    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root, a , b);
        int d1 = findLevel(lca, a, 0);
        int d2 = findLevel(lca, b, 0);
        return d1 + d2;
    }
};













class Solution {
public:
    unordered_map<Node*, Node*> parent;
    unordered_map<Node*, bool> vis;

    Node *src, *dest;

    void findParent(Node* node, int start, int end) {
        if (!node ) return;

        if (node->data == start) src = node;
        if (node->data == end) dest = node;

        if (node->left) {
            parent[node->left] = node;
            findParent(node->left, start, end);
        }
        if (node->right) {
            parent[node->right] = node;
            findParent(node->right, start, end);
        }
    }

    int bfs() {
        queue<pair<Node*, int>> q;
        q.push({src, 0});
        vis[src] = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node *temp = it.first;
            int dis = it.second;

            if (temp == dest) return dis;

            if (temp->left && !vis[temp->left]) {
                vis[temp->left] = 1;
                q.push({temp->left, dis + 1});
            }
            if (temp->right && !vis[temp->right]) {
                vis[temp->right] = 1;
                q.push({temp->right, dis + 1});
            }

            Node* par = parent[temp];
            if (par && !vis[par]) {
                vis[par] = 1;
                q.push({par, dis + 1});
            }
        }
    }

    int findDist(Node* root, int a, int b) {
        if ( !root ) return 0;
        findParent(root, a, b);
        return bfs();
    }
};
