// https://www.geeksforgeeks.org/auto-complete-feature-using-trie/

// Preorder traversal is used to print lexicographically


// Method 1
#define ALPHABET_SIZE (26)

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isWordEnd;
    TrieNode() {
        isWordEnd = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = NULL;
        }
    }
};
 

void insert(TrieNode *root,  const string key) {
    TrieNode *cur = root;
    for (char ch: key) {
        int index = ch - 'a';
        if (!cur->children[index]) {
            cur->children[index] = new TrieNode();
        }
        cur = cur->children[index];
    }
    cur->isWordEnd = true;
}
 
// Returns true if key presents in trie, else false
bool search(TrieNode *root, const string key) {
    TrieNode *cur = root;
    for (char ch: key) {
        int index = ch - 'a';
        if (!cur->children[index]) {
            return false;
        }
        cur = cur->children[index];
    }
 
    return (cur != NULL && cur->isWordEnd);
}
 
// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool isLastNode(TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) return 0;
    }
    return 1;
}
 
// Recursive function to print auto-suggestions for given node.
void suggestionsRec(TrieNode* root, string currPrefix) {
    // found a string in Trie with the given prefix
    if (root->isWordEnd) {
        cout << currPrefix << endl;
    }
 
    // All children struct node pointers are NULL
    if (isLastNode(root)) return;
 
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            // append current character to currPrefix string
            currPrefix.push_back(i + 'a');
 
            // recur over the rest
            suggestionsRec(root->children[i], currPrefix);
            // remove last character
            currPrefix.pop_back();
        }
    }
}
 
// print suggestions for given query prefix.
int printAutoSuggestions(TrieNode* root, const string query) {
    TrieNode* cur = root;
 
    // Check if prefix is present and 
    // find the node with last character of given string.
    for (char ch: query) {
        int index = ch - 'a';
        // no string in the Trie has this prefix
        if (!cur->children[index]) {
            return 0;
        }
        cur = cur->children[index];
    }
 
    // If prefix is present as a word.
    bool isWord = (cur->isWordEnd == true);
 
    // If prefix is last node of tree (has no children)
    bool isLast = isLastNode(cur);
 
    // If prefix is present as a word, 
    // but there is no subtree below the last matching node.
    if (isWord && isLast) {
        cout << query << endl;
        return -1;
    }
 
    // If there are are nodes below last
    // matching character.
    if (!isLast) {
        string prefix = query;
        suggestionsRec(cur, prefix);
        return 1;
    }
}
 
void solve() {
    TrieNode* root = new TrieNode();
    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");
    int comp = printAutoSuggestions(root, "hel");
 
    if (comp == -1)
        cout << "No other strings found with this prefix\n";
 
    else if (comp == 0)
        cout << "No string found with this prefix\n";
}






























// Method 2

struct TrieNode {
    map<char, TrieNode*> children;
    bool isWordEnd;
    TrieNode() {
        isWordEnd = false;
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
    cur->isWordEnd = true;
}
 
// Returns true if key presents in trie, else false
bool search(TrieNode *root, const string key) {
    TrieNode *cur = root;
    for (char ch: key) {
        if (!cur->children[ch]) {
            return false;
        }
        cur = cur->children[ch];
    }
    return (cur && cur->isWordEnd);
}
 
// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool isLastNode(TrieNode* node) {
    return node->children.size() ? 0 : 1;
}
 
// Recursive function to print auto-suggestions for given node.
void suggestionsRec(TrieNode* root, string currPrefix) {
    // found a string in Trie with the given prefix
    if (root->isWordEnd) {
        cout << currPrefix << endl;
    }
 
    for (auto it: root->children) {
        // append current character to currPrefix string
        currPrefix.push_back(it.first);

        // recur over the rest
        suggestionsRec(it.second, currPrefix);
        // remove last character
        currPrefix.pop_back();
    }
}
 
// print suggestions for given query prefix.
int printAutoSuggestions(TrieNode* root, const string query) {
    TrieNode* cur = root;
 
    // Check if prefix is present and 
    // find the node with last character of given string.
    for (char ch: query) {
        // no string in the Trie has this prefix
        if (!cur->children[ch]) {
            return 0;
        }
        cur = cur->children[ch];
    }
 
    // If prefix is present as a word.
    bool isWord = (cur->isWordEnd == true);
    // If prefix is last node of tree (has no children)
    bool isLast = isLastNode(cur);
 
    // If prefix is present as a word, 
    // but there is no subtree below the last matching node.
    if (isWord && isLast) {
        cout << query << endl;
        return -1;
    }
 
    // If there are are nodes below last matching character.
    if (!isLast) {
        string prefix = query;
        suggestionsRec(cur, prefix);
        return 1;
    }
}
 
void solve() {
    TrieNode* root = new TrieNode();
    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");
    int comp = printAutoSuggestions(root, "hel");
 
    if (comp == -1)
        cout << "No other strings found with this prefix\n";
 
    else if (comp == 0)
        cout << "No string found with this prefix\n";
}
