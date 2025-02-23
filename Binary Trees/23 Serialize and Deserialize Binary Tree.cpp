// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// https://youtu.be/-YbXySKJsX8?si=hIUx2Nj865WdY6ky

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            
            if(node) {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                s += "null,";
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream str(data);
        string s;
        getline(str, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            
            getline(str, s, ',');
            if(s == "null") {
                node->left = NULL;
            } else {
               TreeNode* leftNode = new TreeNode(stoi(s));
               node->left = leftNode;
               q.push(leftNode);
            }

            getline(str, s, ',');
            if(s == "null") {
               node->right = NULL;
            } else {
               TreeNode* rightNode = new TreeNode(stoi(s));
               node->right = rightNode;
               q.push(rightNode);
            }
        }

        return root;
    }
};
