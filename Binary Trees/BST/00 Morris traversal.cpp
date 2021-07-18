// https://youtu.be/wGXB9OWhPTg?si=rsrSwdIuh6Mces61
// https://youtu.be/80Zug6D1_r4?si=Wphdcp2OodJ9Nb4a

/*
Threaded binary tree
*/


/*
Inorder Traversal
*/
class Solution {
public:
    TreeNode* getPredecessor(TreeNode* cur) {
        TreeNode* temp = cur;

        // no need to check this condition as it will lways be satisfied
        // since it is the first condition inside while loop
        // if(!temp->left) return temp;

        temp = temp->left;

        while(temp->right) {
            // check if there is a thread bw predecessor and cur
            if(temp->right == cur) return temp;
            
            temp = temp->right;
        }
        return temp;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        TreeNode* cur = root;

        while(cur) {
            // left subtree is not there
            // visit the current node and move to right subtree
            if(!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* predecessor = getPredecessor(cur);
                
                // there is no thread bw predecessor and cur 
                if(!predecessor->right) {
                    // make a thread bw predecessor and cur
                    predecessor->right = cur;

                    // visit cur's left subtree
                    cur = cur->left;
                } 
                // there is a thread bw predecessor and cur
                // this means left subtree is fully visited
                // visit the current node and move to right subtree
                else {
                    // remove the thread (its work is done)
                    predecessor->right = NULL;
                    // visit cur
                    res.push_back(cur->val);
                    // move to right subtree
                    cur = cur->right;
                }
            }
        }

        return res;
    }
};

/*
Inorder Traversal
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        TreeNode* cur = root;

        while(cur) {
            if(!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* predecessor = cur->left;
                while(predecessor->right && predecessor->right != cur) {
                    predecessor = predecessor->right;
                }
                
                if(!predecessor->right) {
                    predecessor->right = cur;
                    cur = cur->left;
                } 
                // predecessor->right == cur
                else {
                    predecessor->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return res;
    }
};



/*
Preorder Traversal
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        TreeNode* cur = root;

        while(cur) {
            if(!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* predecessor = cur->left;
                while(predecessor->right && predecessor->right != cur) {
                    predecessor = predecessor->right;
                }
                
                if(!predecessor->right) {
                    predecessor->right = cur;
                    res.push_back(cur->val);
                    cur = cur->left;
                } else {
                    predecessor->right = NULL;
                    cur = cur->right;
                }
            }
        }

        return res;
    }
};