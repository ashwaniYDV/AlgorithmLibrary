// https://www.geeksforgeeks.org/clone-binary-tree-random-pointers/
// https://www.codingninjas.com/codestudio/problems/clone-a-binary-tree-with-random-pointers_982797

/*
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *random;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
        random = NULL;
    }
};
*/


unordered_map<TreeNode<int>*, TreeNode<int>*> vis;

TreeNode<int>* dfs(TreeNode<int>* root) {
  if (!root) return root;

  if (vis[root]) return vis[root];

  TreeNode<int>* cloned = new TreeNode<int>(root->data);
  vis[root] = cloned;

  cloned->left = dfs(root->left);
  cloned->right = dfs(root->right);
  cloned->random = dfs(root->random);

  return cloned;
}

TreeNode<int> *cloneBinaryTreeRandomPointer(TreeNode<int> *root) {
  vis.clear();
  return dfs(root);
}











unordered_map<TreeNode<int>*, TreeNode<int>*> vis;

TreeNode<int>* dfs(TreeNode<int>* root) {
    if (!root) return root;

    if (vis[root]) return vis[root];

    TreeNode<int>* cloned = new TreeNode<int>(root->data);
    vis[root] = cloned;

    cloned->left = dfs(root->left);
    cloned->right = dfs(root->right);

    return cloned;
}

void copyRandomNode(TreeNode<int>* root, TreeNode<int>* clonedRoot) {
    if (!root) return;

    clonedRoot->random =  vis[root->random];

    copyRandomNode(root->left, clonedRoot->left);
    copyRandomNode(root->right, clonedRoot->right);
}

TreeNode<int> *cloneBinaryTreeRandomPointer(TreeNode<int> *root) {
    vis.clear();
    TreeNode<int> *cloned = dfs(root);
    copyRandomNode(root, cloned);
    return cloned;
}
