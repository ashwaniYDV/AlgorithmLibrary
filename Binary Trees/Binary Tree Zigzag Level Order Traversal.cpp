// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


// This solution is preferred when we want to stdout answer and not return the answer as vector<vector<int>>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        deque<TreeNode*> dq;
        dq.push_front(root);
        bool reverse = 0;

        while (!dq.empty()) {
            int n = dq.size();
            vector<int> temp;

            for (int i = 0; i < n; i++) {

                // If we are printing left to right
                // insert the child from the back of the deque (left child first)
                if (!reverse) {
                    auto it = dq.front();
                    dq.pop_front();
                    temp.push_back(it->val);

                    if (it->left)
                        dq.push_back(it->left);

                    if (it->right)
                        dq.push_back(it->right);
                }

                // If we are printing right to left
                // iterate the deque in reverse order and insert the children from the front
                else {
                    auto it = dq.back();
                    dq.pop_back();
                    temp.push_back(it->val);

                    // insert the child in the front of the deque (right child first)
                    if (it->right)
                        dq.push_front(it->right);

                    if (it->left)
                        dq.push_front(it->left);
                }

            }

            reverse = !reverse;
            res.push_back(temp);
        }

        return res;
    }
};



















// This solution is preferred when we want to return the answer as vector<vector<int>>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = 0;
            
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp(n);
            for(int i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();
                if(reverse) {
                    temp[n - 1 - i] = it->val;
                } else {
                    temp[i] = it->val;
                }
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            res.push_back(temp);
            reverse = !reverse;
        }
        
        return res;
    }
};
