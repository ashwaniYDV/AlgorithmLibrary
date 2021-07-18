/*
Preorder
--------

https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            auto it = st.top();
            st.pop();
            res.push_back(it->val);

            if(it->right) st.push(it->right);
            if(it->left) st.push(it->left);
        }

        return res;
    }
};





/*
Inorder
-------

https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> st;
        TreeNode* temp = root;

        while(!st.empty() || temp) {
            while(temp) {
                st.push(temp);
                temp = temp->left;
            }

            temp = st.top();
            st.pop();

            res.push_back(temp->val);

            temp = temp->right;
        }

        return res;
    }
};






/*
Postorder
--------

https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

// Using 2 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> st, st2;
        st.push(root);

        while(!st.empty()) {
            auto it = st.top();
            st.pop();

            st2.push(it);

            if(it->left) st.push(it->left);
            if(it->right) st.push(it->right);
        }

        while(!st2.empty()) {
            auto it = st2.top();
            st2.pop();
            res.push_back(it->val);
        }

        return res;
    }
};

// Using 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> st;
        TreeNode *temp = root, *temp2;

        while(!st.empty() || temp) {
            while(temp) {
                st.push(temp);
                temp = temp->left;
            }

            temp = st.top();

            if(!temp->right || temp->right == temp2){
                res.push_back(temp->val);
                st.pop();
                temp2 = temp;
                temp = NULL;
            } else {
                temp = temp->right;
            }
        }

        return res;
    }
};