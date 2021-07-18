// https://leetcode.com/problems/maximum-width-of-binary-tree/
// https://youtu.be/ZbybYvcVLks

/*
Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes are also counted into the length calculation.
*/


/*
int cur_id = q.front().second - mn;
here mn is used to normalize node index to 0 in each level to prevent integer overflow for deeper nodes sice 2*i+1 will increase exponentially.

If mn is not used then indexing would be like this
                         0
                        / \
                      1     2
                    /  \   / \
                   3    4  5   6
                   
When mn is used then indexing would be like this
                         0
                        / \
                      0     1
                    /  \   / \
                   0    1  2   3

*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int res = 0;
        
        while(!q.empty()){
            int size = q.size();
            // to make the id starting from zero
            int mn = q.front().second;
            int first, last;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                int cur_id = q.front().second - mn;
                q.pop();
                
                if(i == 0) first = cur_id;
                if(i == size - 1) last = cur_id;
                
                if(node->left)
                    q.push({node->left, cur_id * 2 + 1});
                if(node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }
            
            res = max(res, last - first + 1);
        }
        
        return res;
    }
};
