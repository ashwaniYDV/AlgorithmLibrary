// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

/*
We run a preorder depth-first search (DFS) on the root of a binary tree.
At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  
If the depth of a node is D, the depth of its immediate child is D + 1. 
The depth of the root node is 0.
If a node has only one child, that child is guaranteed to be the left child.
Given the output traversal of this traversal, recover the tree and return its root.

 
Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]

Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]

Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]

Constraints:
The number of nodes in the original tree is in the range [1, 1000].
1 <= Node.val <= 10^9
*/

class Solution {
public:
    int n;

    vector<array<int, 2>> parseData(string& s) {
        int n = s.size();
        vector<array<int, 2>> a;
        int i = 0;
        while(i < n) {
            int depth = 0;
            while(i < n && s[i] == '-') {
                depth++;
                i++;
            }
            int node = 0;
            while(i < n && s[i] != '-') {
                node = node * 10 + (s[i] - '0');
                i++;
            }
            a.push_back({node, depth});
        }
        return a;
    }

    TreeNode* f(int& i, int depth, vector<array<int, 2>>& a) {
        if(i == n) return nullptr;

        if(a[i][1] < depth) return nullptr;

        TreeNode* root = new TreeNode(a[i][0]);
        i++;
        root->left = f(i, depth + 1, a);
        root->right = f(i, depth + 1, a);
        return root;
    }

    TreeNode* recoverFromPreorder(string s) {
        vector<array<int, 2>> a = parseData(s);
        n = a.size();
        int i = 0;
        
        return f(i, 0, a);
    }
};