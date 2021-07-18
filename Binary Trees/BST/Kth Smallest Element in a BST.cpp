// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*Using inorder traversal*/


// recursive
class Solution {
public:
    int res, cnt, k;
    
    void find(TreeNode* node) {
        if(!node) return;
        
        find(node->left);
        
        // inorder part of pushing in vector starts 
        // instead of pushing in inorder vector, we are maintaining cnt of elements in inorder vector and returning the kth element
        cnt++;
        if(cnt == k) {
            res = node->val;
            return;
        }
        // ends
        
        find(node->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        cnt = 0;
        find(root);
        return res;
    }
};




// recursive
class Solution {
public:
    int res = 0;
    
    void find(TreeNode* node, int& k) {
        if(!node) return;
        
        find(node->left, k);
        
        k--;
        if(k == 0) {
            res = node->val;
            return;
        }
        
        find(node->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return res;
    }
};





// iterative
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while(cur || !st.empty()) {
            while(cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            k--;
            if(k == 0) {
                return cur->val;
            }
            cur = cur->right;
        }
        return -1;
    }
};
