// https://practice.geeksforgeeks.org/problems/number-of-turns-in-binary-tree/1
// https://www.geeksforgeeks.org/number-turns-reach-one-node-binary-tree/


/*
=> Open link to see diagram.

Given a binary tree and data value of two of its nodes. 
Find the number of turns needed to reach from one node to another in the given binary tree.

Example 1:
Input:      
Tree = 
           1
        /    \
       2       3
     /  \     /  \
    4    5   6    7                        
   /        / \                        
  8        9   10   
first node = 5
second node = 10

Output: 4

Explanation: 
Turns will be at 2, 1, 3, 6.
*/


/*
We have to follow the step:

1) Find the LCA of the given two nodes
2) Store the path of two-node from LCA in strings S1 and S2, 
   that will store ‘l’  if we have to take a left turn in the path starting from LCA to that node 
   and ‘r’ if we take a right turn in the path starting from LCA.
3) Reverse s1 and concatenate both strings.
4) Count the number of time characters in our resultant string not equal to its adjacent character.
*/


class Solution{
  public:
        Node* LCA(Node* root, int p, int q) {
        // base case
        if (!root || root->data == p || root->data == q) {
            return root;
        }

        Node* left = LCA(root->left, p, q);
        Node* right = LCA(root->right, p, q);

        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        // both left and right are not null, we found our result
        return root;
    }
    
    bool find(Node* root, int val, string &path) {
        if (root->data == val)
            return true;
        
        if (root->left && find(root->left, val, path))
            path.push_back('L');
        
        else if (root->right && find(root->right, val, path))
            path.push_back('R');
        
        return !path.empty();
    }
    
    pair<string, string> getDirections(Node* root, int startValue, int destValue) {
        root = LCA(root, startValue, destValue);
        string start_path, dest_path;
        
        find(root, startValue, start_path);
        find(root, destValue, dest_path);
        
        reverse(start_path.begin(), start_path.end());
        reverse(dest_path.begin(), dest_path.end());
        
        return {start_path, dest_path};
    }
    
    int NumberOFTurns(struct Node* root, int first, int second)
    {
        pair<string, string> p = getDirections(root, first, second);
        string s1 = p.first, s2 = p.second;
        
        if(s1.length() == 0 && s2.length() == 0) {
           return -1;
        }
        
        reverse(s1.begin(), s1.end());
        s1+=s2;
        
        int cnt = 0;
        bool flag = false;
        for(int i = 0; i < (s1.length()-1); i++) {
            if(s1[i] != s1[i+1]) {
                flag = true;
                cnt += 1;
            }
        }
        
        if(!flag){
           return -1;
        }
        return cnt;
    }
};
