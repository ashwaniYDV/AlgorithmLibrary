
/*
             7
            / \
           5   8
          / \   \
         4   6   9
*/

class BstNode {
private:
    int val;
    BstNode *left, *right;
public:
    BstNode() {
        this->val = 0; this->left = this->right = NULL;
    }
    BstNode(int data) {
        this->val = data; this->left = this->right = NULL;
    }
    BstNode(int data, BstNode *l, BstNode *r) {
        this->val = data; this->left = l; this->right = r;
    }

    BstNode* insert(int data, BstNode *root){
        if(root == NULL) {
            root = new BstNode(data);
            return root;
        }
        if(data <= root->val) {
            root->left = insert(data, root->left);
        } else {
            root->right = insert(data, root->right);
        }
        return root;
    }

    void preorder(BstNode* root) {
        cout << "Preorder:\n";
        if(!root) return;

        stack<BstNode*> s;
        s.push(root);

        BstNode *tempRoot;
        while(!s.empty()) {
            tempRoot = s.top();
            s.pop();
            cout << tempRoot->val << " ";
            if(tempRoot->right) s.push(tempRoot->right);
            if(tempRoot->left) s.push(tempRoot->left);
        }
        cout << endl;
    }

    void inorder(BstNode *root) {
        cout << "Inorder:\n";
        if(!root) return;

        stack<BstNode*> s;

        BstNode* tempRoot = root;
        while(tempRoot || !s.empty()) {
            while(tempRoot) {
                s.push(tempRoot);
                tempRoot = tempRoot->left;
            }
            tempRoot = s.top();
            s.pop();
            cout << tempRoot->val << " ";
            tempRoot = tempRoot->right;
        }
        cout << endl;
    }

    void postorder(BstNode *root) {
        cout << "Postorder:\n";
        if(!root) return;

        stack<BstNode*> s1, s2;
        s1.push(root);

        BstNode *tempRoot;
        while(!s1.empty()){
            tempRoot = s1.top();
            s1.pop();
            s2.push(tempRoot);
            if(tempRoot->left) s1.push(tempRoot->left);
            if(tempRoot->right) s1.push(tempRoot->right);
        }
        while(!s2.empty()){
            tempRoot = s2.top();
            s2.pop();
            cout << tempRoot->val << " ";
        }
        cout << endl;
    }

    void levelorder(BstNode* root) {
        cout << "Levelorder:\n";
        if(!root) return;

        queue<BstNode*> q;
        q.push(root);

        BstNode* tempRoot;
        while(!q.empty()) {
            tempRoot = q.front();
            q.pop();

            cout << tempRoot->val << " ";
            if(tempRoot->left) q.push(tempRoot->left);
            if(tempRoot->right) q.push(tempRoot->right);
        }
        cout << endl;
    }

    void rightView(BstNode *root) {
        cout << "Right View:\n";
        if(!root) return;
        
        queue<BstNode*> q;
        q.push(root);
        
        BstNode* temp;
        while(!q.empty()){
            int n = q.size();
            
            // print the last element of each level
            while(n){
                n--;
                temp = q.front();
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            cout << temp->val << " ";
        }
        cout << endl;
    }

    void leftView(BstNode *root) {
        cout << "Left View:\n";
        if(!root) return;
        
        queue<BstNode*> q;
        q.push(root);
        
        BstNode* temp;
        while(!q.empty()){
            int n = q.size();
            
            // print the first element of each level
            for(int i = 0; i < n; i++){
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

    void topView(BstNode *root) {
        cout << "Top View:\n";
        if(!root) return;

        // horizontal distance concept
        queue<pair<BstNode*, int>> q;
        q.push({root, 0});

        // it will be sorted by increasing hor_dist
        map<int, int> mp;

        while(!q.empty()) {
            auto i = q.front();
            q.pop();
            BstNode *temp = i.first;
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

    void bottomView(BstNode *root) {
        cout << "Bottom View:\n";
        if(!root) return;

        // horizontal distance concept
        queue<pair<BstNode*, int>> q;
        q.push({root, 0});

        // it will be sorted by increasing hor_dist
        map<int, int> mp;

        while(!q.empty()) {
            auto i = q.front();
            q.pop();
            BstNode *temp = i.first;
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

    int tree_height(BstNode *root) {
        if(!root) return 0;

        return 1 + max(tree_height(root->left), tree_height(root->right));
    }
};

void solve() {
    BstNode *root = NULL;
    root = root->insert(7, root);
    root = root->insert(5, root);
    root = root->insert(8, root);
    root = root->insert(4, root);
    root = root->insert(6, root);
    root = root->insert(9, root);
    root->preorder(root);
    root->inorder(root);
    root->postorder(root);
    root->levelorder(root);
    root->rightView(root);
    root->leftView(root);
    root->topView(root);
    root->bottomView(root);
    cout << "Tree height: ";
    cout << root->tree_height(root) << endl;
}

int32_t main() {
    IOS
    solve();
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}

/*
OUTPUT
------------
Preorder:
7 5 4 6 8 9 
Inorder:
4 5 6 7 8 9 
Postorder:
4 6 5 9 8 7 
Levelorder:
7 5 8 4 6 9 
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
