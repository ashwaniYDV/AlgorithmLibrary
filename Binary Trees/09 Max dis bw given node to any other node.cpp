// https://practice.geeksforgeeks.org/problems/burning-tree/1


#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *left, *right;
    int val;
    Node(int d) {
        val = d;
        left = right = NULL;
    }
};


// returns -> { start node present in root's subtree or not (1 or 0), height of subtree, distance to the given node having value start }
array<int, 3> burn_tree(Node* root, int start, int &maxx) {
    if (!root) return {0, 0, 0};

    array<int, 3> v1 = burn_tree(root->left, start, maxx);
    array<int, 3> v2 = burn_tree(root->right, start, maxx);

    if (root->val == start) {
        maxx = max(maxx, max(v1[1], v2[1]));
        return {1, max(v1[1], v2[1]) + 1, 0 + 1};
    }

    if (v1[0] && !v2[0]) {
        maxx = max(maxx, v1[2] + v2[1]);
        return {1, max(v1[1], v2[1]) + 1, v1[2] + 1};
    }
    if (!v1[0] && v2[0]) {
        maxx = max(maxx, v2[2] + v1[1]);
        return {1, max(v1[1], v2[1]) + 1, v2[2] + 1};
    }
    return {0, max(v1[1], v2[1]) + 1, 0};
}

int solve(Node* root, int start) {
    int maxx = 0;
    burn_tree(root, start, maxx);
    return maxx;
}

int main() {
    /*
               1
          / \
         2   3
        / \  / \
       4   5 6  7
              \
               8
    */
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    cout << 1 << " " << solve(root, 1) << endl;
    cout << 2 << " " << solve(root, 2) << endl;
    cout << 3 << " " << solve(root, 3) << endl;
    cout << 4 << " " << solve(root, 4) << endl;
    cout << 5 << " " << solve(root, 5) << endl;
    cout << 6 << " " << solve(root, 6) << endl;
    cout << 7 << " " << solve(root, 7) << endl;
    cout << 8 << " " << solve(root, 8) << endl;
}















class Solution {
public:
    // returns -> { start node present in root's subtree or not (1 or 0), height of subtree, distance to the given node having value start }
    array<int, 3> burn_tree(Node* root, int start, int &maxx) {
        if (!root) return {0, 0, 0};

        array<int, 3> leftV = burn_tree(root->left, start, maxx);
        array<int, 3> rightV = burn_tree(root->right, start, maxx);

        if (root->data == start) {
            maxx = max(maxx, max(leftV[1], rightV[1]));
            return {1, max(leftV[1], rightV[1]) + 1, 0 + 1};
        }

        if (leftV[0] && !rightV[0]) {
            maxx = max(maxx, leftV[2] + rightV[1]);
            return {1, max(leftV[1], rightV[1]) + 1, leftV[2] + 1};
        }
        if (!leftV[0] && rightV[0]) {
            maxx = max(maxx, rightV[2] + leftV[1]);
            return {1, max(leftV[1], rightV[1]) + 1, rightV[2] + 1};
        }
        return {0, max(leftV[1], rightV[1]) + 1, 0};
    }


    int minTime(Node* root, int target)
    {
        // Your code goes here
        int maxx = 0;
        burn_tree(root, target, maxx);
        return maxx;
    }
};
