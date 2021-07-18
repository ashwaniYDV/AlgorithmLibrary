// https://youtu.be/5BzvEmscu-o

/*
We are basically implementing the idea of recursion in these solutions

1) preorder
-----------
fun(root) {
    root                                        cnt = 0
    fun(left)                                   cnt = 1
    fun(right)                                  cnt = 2

    // root gets popped out of process stack    cnt = 3
}

2) inorder
-----------
fun(root) {
    fun(left)                                   cnt = 0
    root                                        cnt = 1
    fun(right)                                  cnt = 2

    // root gets popped out of process stack    cnt = 3
}

3) postorder
-----------
fun(root) {
    fun(left)                                   cnt = 0
    fun(right)                                  cnt = 1
    root                                        cnt = 2

    // root gets popped out of process stack    cnt = 3
}
*/


// Method 1: Not space optimized
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        map<TreeNode*, int> mp;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            int cnt = mp[node];

            if(!node || cnt == 3) {
                continue;
            }

            // increment the state of current node
            st.push(node);
            mp[node] = cnt + 1;
            
            if(cnt == 0) {
                res.push_back(node->val);
            } else if(cnt == 1) {
                st.push(node->left);
            } else if(cnt == 2) {
                st.push(node->right);
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        map<TreeNode*, int> mp;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            int cnt = mp[node];

            if(!node || cnt == 3) {
                continue;
            }

            // increment the state of current node
            st.push(node);
            mp[node] = cnt + 1;
            
            if(cnt == 0) {
                st.push(node->left);
            } else if(cnt == 1) {
                res.push_back(node->val);
            } else if(cnt == 2) {
                st.push(node->right);
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        map<TreeNode*, int> mp;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            int cnt = mp[node];

            if(!node || cnt == 3) {
                continue;
            }

            // increment the state of current node
            st.push(node);
            mp[node] = cnt + 1;
            
            if(cnt == 0) {
                st.push(node->left);
            } else if(cnt == 1) {
                st.push(node->right);
            } else if(cnt == 2) {
                res.push_back(node->val);
            }
        }

        return res;
    }
};






// Methiod 2: Space optimized
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        while(!st.empty()) {
            auto it = st.top();
            st.pop();
            
            TreeNode* node = it.first;
            int cnt = it.second;

            if(!node || cnt == 3) {
                continue;
            }

            // increment the state of current node
            st.push({ node, cnt + 1 });
            
            if(cnt == 0) {
                res.push_back(node->val);
            } else if(cnt == 1) {
                st.push({ node->left, 0 });
            } else if(cnt == 2) {
                st.push({ node->right, 0 });
            }
        }

        return res;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        while(!st.empty()) {
            auto it = st.top();
            st.pop();
            
            TreeNode* node = it.first;
            int cnt = it.second;

            if(!node || cnt == 3) {
                continue;
            }

            // increment the state of current node
            st.push({ node, cnt + 1 });
            
            if(cnt == 0) {
                st.push({ node->left, 0 });
            } else if(cnt == 1) {
                res.push_back(node->val);
            } else if(cnt == 2) {
                st.push({ node->right, 0 });
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        while(!st.empty()) {
            auto it = st.top();
            st.pop();
            
            TreeNode* node = it.first;
            int cnt = it.second;

            if(!node || cnt == 3) {
                continue;
            }

            // increment the state of current node
            st.push({ node, cnt + 1 });
            
            if(cnt == 0) {
                st.push({ node->left, 0 });
            } else if(cnt == 1) {
                st.push({ node->right, 0 });
            } else if(cnt == 2) {
                res.push_back(node->val);
            }
        }

        return res;
    }
};