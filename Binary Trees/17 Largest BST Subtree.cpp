// https://www.scaler.com/problems/largest-bst-subtree

/*
Given a Binary Tree A with N nodes.
Write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST).
If the complete Binary Tree is BST, then return the size of whole tree.

NOTE:
Largest subtree means subtree with most number of nodes.


Problem Constraints
1 <= N <= 10^5
*/



/*
Maintain a data structure that stores for every node 
(a) the maximum value in the subtree of node, 
(b) minimum value in the subtree of node,
(c) size of the subtree, 
(d) size of largest BST found in the subtree of node 
(e) flag to denote whether this subtree is bst or not.

Traverse the tree in bottom up manner.

A Tree is BST if following is true for every node X.
(a) The largest value in left subtree (of X) is smaller than value of X.
(b) The smallest value in right subtree (of X) is greater than value of X.
    update the details of the this nodes accordingly.
*/



struct Info {
    int sz;
    int mx;
    int mn;
    int ans;
    bool isBST;
};

Info largestBSTinBinaryTree(TreeNode * root) {
    if (root == NULL)
        return {
            0,
            INT_MIN,
            INT_MAX,
            0,
            true
        };

    if (root -> left == NULL && root -> right == NULL)
        return {
            1,
            root -> val,
            root -> val,
            1,
            true
        };

    Info l = largestBSTinBinaryTree(root -> left);
    Info r = largestBSTinBinaryTree(root -> right);

    Info ret;
    ret.sz = (1 + l.sz + r.sz);

    if (l.isBST && r.isBST && l.mx < root -> val && r.mn > root -> val) {
        ret.mn = min(l.mn, min(r.mn, root -> val));
        ret.mx = max(r.mx, max(l.mx, root -> val));
        ret.ans = ret.sz;
        ret.isBST = true;
        return ret;
    }

    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
    return ret;
}

int Solution::solve(TreeNode * A) {
    Info res = largestBSTinBinaryTree(A);
    return res.ans;
}
