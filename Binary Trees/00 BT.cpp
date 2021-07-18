#include <bits/stdc++.h>
using namespace std;

/*
             7
            / \
           5   8
          / \   \
         4   6   9
*/

class TreeNode {
private:
    int val;
    TreeNode *left, *right;
public:
    TreeNode() {
        this->val = 0; this->left = this->right = NULL;
    }
    TreeNode(int data) {
        this->val = data; this->left = this->right = NULL;
    }
    TreeNode(int data, TreeNode *l, TreeNode *r) {
        this->val = data; this->left = l; this->right = r;
    }

    TreeNode* insert(int data, TreeNode *root){
        if(root == NULL) {
            root = new TreeNode(data);
            return root;
        }
        if(data <= root->val) {
            root->left = insert(data, root->left);
        } else {
            root->right = insert(data, root->right);
        }
        return root;
    }

    void rightView(TreeNode *root) {
        cout << "Right View:\n";
        if(!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* temp;
        while(!q.empty()){
            int n = q.size();
            
            // print the last element of each level
            while(n--){
                temp = q.front();
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            cout << temp->val << " ";
        }
        cout << endl;
    }

    void leftView(TreeNode *root) {
        cout << "Left View:\n";
        if(!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* temp;
        while(!q.empty()){
            int n = q.size();
            
            // print the first element of each level
            for(int i = 0; i < n; i++) {
                temp = q.front();
                q.pop();

                if(i == 0) {
                    cout << temp->val << " ";
                }
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        cout << endl;
    }

    void topView(TreeNode *root) {
        cout << "Top View:\n";
        if(!root) return;

        // horizontal distance concept
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        // it will be sorted by increasing hor_dist
        map<int, int> mp;

        while(!q.empty()) {
            auto i = q.front();
            q.pop();
            TreeNode *temp = i.first;
            int horz_dist = i.second;

            // we want the first node of each vertical level for top view
            if(mp.count(horz_dist) == 0) {
                mp[horz_dist] = temp->val;
            }

            if(temp->left) {
                q.push({temp->left, horz_dist - 1});
            }
            if(temp->right) {
                q.push({temp->right, horz_dist + 1});
            }
        }

        for(auto i: mp) {
            cout << i.second << " ";
        }
        cout << endl;
    }

    void bottomView(TreeNode *root) {
        cout << "Bottom View:\n";
        if(!root) return;

        // horizontal distance concept
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        // it will be sorted by increasing hor_dist
        map<int, int> mp;

        while(!q.empty()) {
            auto i = q.front();
            q.pop();
            TreeNode *temp = i.first;
            int horz_dist = i.second;

            // we want the last node of each vertical level for top view (therefore we override every time)
            mp[horz_dist] = temp->val;

            if(temp->left) {
                q.push({temp->left, horz_dist - 1});
            }
            if(temp->right) {
                q.push({temp->right, horz_dist + 1});
            }
        }

        for(auto i: mp) {
            cout << i.second << " ";
        }
        cout << endl;
    }

    int tree_height(TreeNode *root) {
        if(!root) return 0;

        return 1 + max(tree_height(root->left), tree_height(root->right));
    }
};

int main() {
    TreeNode *root = NULL;
    root = root->insert(7, root);
    root = root->insert(5, root);
    root = root->insert(8, root);
    root = root->insert(4, root);
    root = root->insert(6, root);
    root = root->insert(9, root);

    root->rightView(root);
    root->leftView(root);
    root->topView(root);
    root->bottomView(root);
    cout << "Tree height: ";
    cout << root->tree_height(root) << endl;
}

/*
Right View:
7 8 9 
Left View:
7 5 4 
Top View:
4 5 7 8 9 
Bottom View:
4 5 6 8 9 
Tree height: 3
*/
