// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/

/*
You are given the root of a binary tree with n nodes. 
Each node is assigned a unique value from 1 to n. 
You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:
a) Remove subtree rooted at node with value queries[i] from the tree. 
   It is guaranteed that queries[i] will not be equal to the value of the root.
b) Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

Note:
The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
*/



// TLE
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        auto f = [&](int x, TreeNode* root, auto&& f) -> int {
            if(!root) return 0;
            if(root->val == x) return 0;
            int l = f(x, root->left, f);
            int r = f(x, root->right, f);

            return 1 + max(l, r);
        };

        vector<int> res;

        for(int x: queries) {
            res.push_back(f(x, root, f) - 1);
        }
        return res;
    }
};



/*
Approach One and Right Traversal
--------------------------------
* The problem asks us to find the height of a tree after removing a subtree rooted at nodes listed in queries.
* A brute force solution would process each query separately by removing the specified subtree and recalculating the height of the remaining tree. 
  However, this approach is inefficient due to its high time complexity.
* To optimize, we can track the tree's height as we traverse from the root. 
  For any node, the height after removing its subtree is simply the height of the tree before reaching that node. 
  This allows us to avoid recalculating the height repeatedly.
* We’ll perform a preorder traversal, tracking the max distance from the root. 
  However, if max height is achieved in the right subtree, we may miss it when traversing the left. 
  To address this, we perform a second traversal in reverse preorder (root, right, left).
* We maintain an array heights where heights[i] stores the tree height after removing the subtree rooted at node i. 
  During the first traversal, we update heights with the height at each node as we explore its left and right subtrees. 
  In the reverse traversal, we update heights if the current height is greater than the stored value.
* Finally, we iterate over queries and return the corresponding heights for each specified node.
*/
class Solution {
public:
    // Left to right traversal (Preorder)
    void traverseLeftToRight(TreeNode* node, int curHeight) {
        if (!node) return;

        // Store the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] = height;

        // Update the current maximum height
        height = max(height, curHeight);

        // Traverse left subtree first, then right
        traverseLeftToRight(node->left, curHeight + 1);
        traverseLeftToRight(node->right, curHeight + 1);
    }

    // Right to left traversal (Reverse Preorder)
    void traverseRightToLeft(TreeNode* node, int curHeight) {
        if (!node) return;

        // Update the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] = max(maxHeightAfterRemoval[node->val], height);

        // Update the current maximum height
        height = max(height, curHeight);

        // Traverse right subtree first, then left
        traverseRightToLeft(node->right, curHeight + 1);
        traverseRightToLeft(node->left, curHeight + 1);
    }

    // Array to store the maximum height of the tree after removing each node
    int maxHeightAfterRemoval[100001];
    int height;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height = 0;
        traverseLeftToRight(root, 0);

        height = 0;  // Reset for the second traversal
        traverseRightToLeft(root, 0);

        vector<int> res;
        for (int q: queries) {
            res.push_back(maxHeightAfterRemoval[q]);
        }

        return res;
    }
};





/*
Approach 2: One Traversal
-------------------------
* Let's optimize our solution to use just one traversal. 
  We'll perform a preorder traversal starting from the root, similar to our previous approach. 
  During this traversal, we’ll track a variable maxVal representing the maximum height encountered so far.
* For each node, we store its corresponding answer (maxVal at that point) in a resultMap for quick lookups during queries. 
  We’ll also keep track of the depth as we traverse.
* To determine the max height if a node is removed, we consider two values:
  a) The current maxVal on the path from the root to the node.
  b) The node’s depth + one (to include itself) + height of its sibling subtree.
* To calculate the height of a sibling subtree, we’ll use a memoized helper function that finds the maximum distance from a given node to its leaf nodes.
* Starting the DFS from the root, we populate resultMap with heights for each node. 
*/
class Solution {
public:
    // Function to calculate the height of the tree
    int height(TreeNode* node, unordered_map<TreeNode*, int>& heightCache) {
        if (!node) return -1;

        // Return cached height if already calculated
        if (heightCache.count(node)) return heightCache[node];

        int l = height(node->left, heightCache);
        int r = height(node->right, heightCache);

        return heightCache[node] = 1 + max(l, r);
    }

    // DFS to precompute the maximum values after removing the subtree
    void dfs(TreeNode* node, int depth, int maxVal,
             unordered_map<int, int>& resultMap,
             unordered_map<TreeNode*, int>& heightCache) {
        if (!node) return;

        resultMap[node->val] = maxVal;

        // Traverse left and right subtrees while updating max values
        dfs(node->left, depth + 1,
            max(maxVal, depth + 1 + height(node->right, heightCache)),
            resultMap, heightCache);
        dfs(node->right, depth + 1,
            max(maxVal, depth + 1 + height(node->left, heightCache)), resultMap,
            heightCache);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> resultMap;
        unordered_map<TreeNode*, int> heightCache;

        // Run DFS to fill resultMap with maximum heights after each query
        dfs(root, 0, 0, resultMap, heightCache);

        vector<int> res;
        for (int q: queries) {
            res.push_back(resultMap[q]);
        }

        return res;
    }
};