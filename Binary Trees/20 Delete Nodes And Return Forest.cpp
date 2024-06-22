// https://leetcode.com/problems/delete-nodes-and-return-forest/

/*
Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, 
we are left with a forest (a disjoint union of trees).
Return the roots of the trees in the remaining forest. 
You may return the result in any order.
*/

// My first solution: not time / space optimised
// You can look the optimised solution below
class Solution {
public:
    void fun(TreeNode* root, int node, TreeNode* par, vector<pair<TreeNode*, TreeNode*>>& v) {
        if(!root) return;

        if(root->val == node) {
            v.push_back({ root, par });
            return;
        }

        fun(root->left, node, root, v);
        fun(root->right, node, root, v);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<pair<TreeNode*, TreeNode*>> v;
        for(int node: to_delete) {
            fun(root, node, NULL, v);
        }

        unordered_set<TreeNode*> resSt, deletedSt;
        resSt.insert(root);

        for(auto it: v) {
            TreeNode* root = it.first;
            TreeNode* par = it.second;
            if(par) {
                if(par->left == root) {
                    par->left = NULL;
                }
                if(par->right == root) {
                    par->right = NULL;
                }
            }

            resSt.erase(root);

            if(root->left && !deletedSt.count(root->left)) {
                resSt.insert(root->left);
            }
            if(root->right && !deletedSt.count(root->right)) {
                resSt.insert(root->right);
            }
            deletedSt.insert(root);
        }

        vector<TreeNode*> res(resSt.begin(), resSt.end());
        return res;
    }
};



// Optimal solution
class Solution {
public:
    void fun(TreeNode* root, TreeNode* par, unordered_set<int>toDelete, vector<TreeNode*>&res){
        if(!root) return;

        /*
        we call the left and right childs recursively first instead of processing the root first
        this ensures that bottom nodes are processed first (i.e. deleted) and 
        we do not have any issue in traversing the tree for deleting top nodes later 
        */
        fun(root->left, root, toDelete, res);
        fun(root->right, root, toDelete, res);

        if(toDelete.count(root->val)) {
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);

            if(par && par->left == root) par->left = NULL;
            if(par && par->right == root) par->right = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;

        fun(root, NULL, toDelete, res);
        
        if(!toDelete.count(root->val)) res.push_back(root);
        
        return res;
    }
};




class Solution {
public:
    /* 
        Note: root is taken as referece
        thus if we do (root = NULL), this will make par->(child=root) as NULL
    */
    void fun(TreeNode* &root,  unordered_set<int>toDelete, vector<TreeNode*>&res){
        if(!root) return;

        fun(root->left, toDelete, res);
        fun(root->right, toDelete, res);

        if(toDelete.count(root->val)) {
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            
            root = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;

        fun(root, toDelete, res);
        
        if(root) res.push_back(root);
        
        return res;
    }
};