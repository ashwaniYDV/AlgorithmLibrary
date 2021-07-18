// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column 
and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.
*/


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        map<int, vector<int>> mp;
        
        while(!q.empty()) {
            int sz = q.size();
            map<int, vector<int>> mp2;
            for(int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                TreeNode *temp = it.first;
                int dist = it.second;
                mp2[dist].push_back(temp->val);
                
                if(temp->left) {
                    q.push({temp->left, dist - 1});
                }
                if(temp->right) {
                    q.push({temp->right, dist + 1});
                }
            }
            
            for(auto it: mp2) {
                sort(mp2[it.first].begin(), mp2[it.first].end());
            }
            for(auto it: mp2) {
                mp[it.first].insert(mp[it.first].end(), it.second.begin(), it.second.end());
            }
        }
        
        vector<vector<int>> res;
        for(auto it: mp) res.push_back(it.second);
        return res;
    }
};

















class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        map<int, vector<int>> mp;
        
        while(!q.empty()) {
            int sz = q.size();
            map<int, vector<int>> mp2;
            for(int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                TreeNode *temp = it.first;
                int dist = it.second;
                mp2[dist].push_back(temp->val);
                
                if(temp->left) {
                    q.push({temp->left, dist - 1});
                }
                if(temp->right) {
                    q.push({temp->right, dist + 1});
                }
            }
            
            for(auto &it: mp2) {
                sort(it.second.begin(), it.second.end());
            }
            for(auto it: mp2) {
                mp[it.first].insert(mp[it.first].end(), it.second.begin(), it.second.end());
            }
        }
        
        vector<vector<int>> res;
        for(auto it: mp) res.push_back(it.second);
        return res;
    }
};
