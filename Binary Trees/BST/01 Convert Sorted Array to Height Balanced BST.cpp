// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/

class Solution {
public:
    TreeNode* fun(int l, int r, vector<int>& nums) {
        // base case
        if(l > r) return NULL;

        int mid = ((l + r) >> 1);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = fun(l, mid - 1, nums);
        root->right = fun(mid + 1, r, nums);

        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(0, nums.size() - 1, nums);
    }
};
















class BstNode {
private:
    int val;
    BstNode *left, *right;
public:
    BstNode() {
        this->val = 0; this->left = this->right = NULL;
    }
    BstNode(int data) {
        this->val = data; this->left = this->right = NULL;
    }
    BstNode(int data, BstNode *l, BstNode *r) {
        this->val = data; this->left = l; this->right = r;
    }

    BstNode* insert(int data, BstNode *root){
        if(root == NULL) {
            root = new BstNode(data);
            return root;
        }
        if(data <= root->val) {
            root->left = insert(data, root->left);
        } else {
            root->right = insert(data, root->right);
        }
        return root;
    }

    void inorder(BstNode *root) {
        cout << "Inorder:\n";
        if(!root) return;

        stack<BstNode*> s;

        BstNode* tempRoot = root;
        while(tempRoot || !s.empty()) {
            while(tempRoot) {
                s.push(tempRoot);
                tempRoot = tempRoot->left;
            }
            tempRoot = s.top();
            s.pop();
            cout << tempRoot->val << " ";
            tempRoot = tempRoot->right;
        }
        cout << endl;
    }

    BstNode *sortedArrayToHeightBalancedBst(vector<int> a, int l, int r) {
        // base case
        if(l > r) return NULL;

        int mid = ((l + r) >> 1);
        BstNode *root = new BstNode(a[mid]);
        root->left = sortedArrayToHeightBalancedBst(a, l, mid - 1);
        root->right = sortedArrayToHeightBalancedBst(a, mid + 1, r);

        return root;
    }

};

void solve() {
    // sorted array
    vector<int> a {1, 2, 3, 4, 5};
    BstNode *root = NULL;
    root = root->sortedArrayToHeightBalancedBst(a, 0, a.size() - 1);
    root->insert(100, root);
    root->inorder(root);
}

/*
OUTPUT
---------
Inorder:
1 2 3 4 5 100 

*/
