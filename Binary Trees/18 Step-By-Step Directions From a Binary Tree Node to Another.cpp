// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/


/*
=> See diagram from link.

You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. 
You are also given an integer startValue representing the value of the start node s, 
and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. 
Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. 
Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node s to node t.
*/





// Method 1:

/*
3 Steps:

1) Find LCA of given nodes

2) Build directions for both start and destination from the LCA.
Say we get "LRRL" and "RR".

2) Replace all steps in the start direction to "U" and add destination direction.
The result is "UUUU" + "RR".
*/

class Solution {
public:
    TreeNode* LCA(TreeNode* root, int p, int q) {
        // base case
        if (!root || root->val == p || root->val == q) {
            return root;
        }

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        // both left and right are not null, we found our result
        return root;
    }
    
    bool find(TreeNode* root, int val, string &path) {
        if (root->val == val)
            return true;
        
        if (root->left && find(root->left, val, path))
            path.push_back('L');
        
        else if (root->right && find(root->right, val, path))
            path.push_back('R');
        
        return !path.empty();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = LCA(root, startValue, destValue);
        string start_path, dest_path;
        
        find(root, startValue, start_path);
        find(root, destValue, dest_path);
        
        reverse(start_path.begin(), start_path.end());
        reverse(dest_path.begin(), dest_path.end());
        
        string res =  "";
        
        for(int i = 0; i < start_path.size(); i++) {
            res += 'U';
        }
        
        for(int j = 0; j < dest_path.size(); j++) {
            res += dest_path[j];
        }

        return res;   
    }
};












// Method 2:

/*
3 Steps:

1) Build directions for both start and destination from the root.
Say we get "LLRRL" and "LRR".

2) Remove common prefix path.
We remove "L", and now start direction is "LRRL", and destination - "RR"

3) Replace all steps in the start direction to "U" and add destination direction.
The result is "UUUU" + "RR".
*/

class Solution {
public:
    bool find(TreeNode* root, int val, string &path) {
        if (root->val == val)
            return true;
        
        if (root->left && find(root->left, val, path))
            path.push_back('L');
        
        else if (root->right && find(root->right, val, path))
            path.push_back('R');
        
        return !path.empty();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start_path, dest_path;
        
        find(root, startValue, start_path);
        find(root, destValue, dest_path);
        
        reverse(start_path.begin(), start_path.end());
        reverse(dest_path.begin(), dest_path.end());
        
        int i = 0, j = 0;
        int mn = min(start_path.size(), dest_path.size());
        
        while (i < mn && start_path[i] == dest_path[j]) {
            i++, j++;
        }

        string res =  "";
        
        for( ; i < start_path.size(); i++) {
            res += 'U';
        }
        
        for( ; j < dest_path.size(); j++) {
            res += dest_path[j];
        }

        return res;   
    }
};




// This solution gives MLE
class Solution {
public:
    string res_path;
    
    void go(TreeNode* root, int val, string path) {
        if(!root) return;
        
        if (root->val == val) {
            res_path = path;
            return;
        }
        
        if (root->left)
            go(root->left, val, path + 'L');
        
        if (root->right)
            go(root->right, val, path + 'R');
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start_path, dest_path;
        
        res_path = "";
        go(root, startValue, "");
        start_path = res_path;
        
        res_path = "";
        go(root, destValue, "");
        dest_path = res_path;
        
        int i = 0, j = 0;
        int mn = min(start_path.size(), dest_path.size());
        
        while (i < mn && start_path[i] == dest_path[j]) {
            i++, j++;
        }

        string res =  "";
        
        for( ; i < start_path.size(); i++) {
            res += 'U';
        }
        
        for( ; j < dest_path.size(); j++) {
            res += dest_path[j];
        }

        return res;  
    }
};
