// https://practice.geeksforgeeks.org/problems/burning-tree/1

/*
You have been given a binary tree of unique nodes and a Start node from where the tree will start to burn. 
Given that the Start node will always exist in the tree, your task is to print the time (in minutes) that it will take to burn the whole tree.
It is given that it takes 1 minute for the fire to travel from the burning node to its adjacent node and burn down the adjacent node.
For Example :
For the given binary tree: [1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1]
Start Node: 3

    1
   / \
  2   3
     / \
    4   5

Output: 2
*/



// Using: Max dis bw given node to any other node concept

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


    int minTime(Node* root, int target) {
        int maxx = 0;
        burn_tree(root, target, maxx);
        return maxx;
    }
};













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

    array<int, 3> leftV = burn_tree(root->left, start, maxx);
    array<int, 3> rightV = burn_tree(root->right, start, maxx);

    if (root->val == start) {
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
         / \
        4   5
    */
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    cout << "Start = " << 1 << ", time = " << solve(root, 1) << endl;
    cout << "Start = " << 2 << ", time = " << solve(root, 2) << endl;
    cout << "Start = " << 3 << ", time = " << solve(root, 3) << endl;
    cout << "Start = " << 4 << ", time = " << solve(root, 4) << endl;
    cout << "Start = " << 5 << ", time = " << solve(root, 5) << endl;
}


















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

int res;   
map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
map<BinaryTreeNode<int>*, int> vis;

BinaryTreeNode<int>* x;

void findParent(BinaryTreeNode<int>* node, int start) {
    if(!node ) return;
    
    if(node->data == start) x = node;

    if(node->left) {
        parent[node->left] = node;
        findParent(node->left, start);
    }
    if(node->right) {
        parent[node->right] = node;
        findParent(node->right, start);
    }
}

void bfs() {
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({x, 0});
    vis[x] = 1;
    
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int> *temp = it.first;
        int dis = it.second;
        res = max(res, dis);
        
        if(temp->left && !vis[temp->left]) {
            vis[temp->left] = 1;
            q.push({temp->left, dis + 1});
        }
        if(temp->right && !vis[temp->right]) {
            vis[temp->right] = 1;
            q.push({temp->right, dis + 1});
        }
        BinaryTreeNode<int>* par = parent[temp];
        if(par && !vis[par]) {
            vis[par] = 1;
            q.push({par, dis + 1});
        }
    }
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    if( !root ) return 0;
    findParent(root, start);
    res = 0;
    bfs();
    return res;
}


void solve() {
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    cout << timeToBurnTree(root, 2) << endl;
}
