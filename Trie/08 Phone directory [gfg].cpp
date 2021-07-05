// https://practice.geeksforgeeks.org/problems/phone-directory4628/1

class Solution{
public:
    struct TrieNode {
        map<char, TrieNode*> children;
        bool isLeaf;
        TrieNode() {
            isLeaf = false;
        }
    };
    
    void insert(TrieNode *root,  const string key) {
        TrieNode *cur = root;
        for (char ch: key) {
            if (!cur->children[ch]) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->isLeaf = true;
    }
    
    bool isLastNode(TrieNode* node) {
        return node->children.size() ? 0 : 1;
    }
    
    void suggestionsRec(TrieNode* root, string currPrefix, vector<string>& vec) {
        // found a string in Trie with the given prefix
        if (root->isLeaf) {
            vec.push_back(currPrefix);
        }
     
        for (auto it: root->children) {
            // append current character to currPrefix string
            currPrefix.push_back(it.first);
            // recur over the rest
            suggestionsRec(it.second, currPrefix, vec);
            // remove last character
            currPrefix.pop_back();
        }
    }

    int fun(TrieNode* root, string query, vector<string>& vec) {
        TrieNode* cur = root;

        for (char ch: query) {
            if (!cur->children[ch]) {
                return 0;
            }
            cur = cur->children[ch];
        }
     
        // If prefix is present as a word.
        bool isWord = (cur->isLeaf == true);
        // If prefix is last node of tree (has no children)
        bool isLast = isLastNode(cur);
     
        // If prefix is present as a word, 
        // but there is no subtree below the last matching node.
        if (isWord && isLast) {
            vec.push_back(query);
            return -1;
        }
     
        // If there are are nodes below last
        // matching character.
        if (!isLast) {
            string prefix = query;
            suggestionsRec(cur, prefix, vec);
            return 1;
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < n; i++) {
            insert(root, contact[i]);
        }
        
        vector<vector<string>> res;
        string temp;
        for(char ch: s) {
            temp.push_back(ch);
            vector<string> vec;
            int x = fun(root, temp, vec);
            if(x == 0) {
                vec.push_back("0");
            }
            res.push_back(vec);
        }
        
        return res;
    }
};
