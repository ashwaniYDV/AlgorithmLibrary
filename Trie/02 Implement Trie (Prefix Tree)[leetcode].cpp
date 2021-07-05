// https://leetcode.com/problems/implement-trie-prefix-tree/submissions/

class Trie {
    struct Trienode {
        char val;
        int count;
        int endsHere;
        Trienode *child[26];
    };
    
    Trienode *getNode(char value) {
        Trienode *newnode = new Trienode;
        newnode->val = value;
        newnode->count = newnode->endsHere = 0;
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
    
    Trienode *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = getNode('/');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode *curr = root;
        int index;
        for(char ch: word) {
            index = ch - 'a';
            if(!curr->child[index]) {
                curr->child[index] = getNode(ch);
            }
            curr->child[index]->count++;
            curr = curr->child[index];
        }
        curr->endsHere++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode *curr = root;
        int index;
        for(char ch: word) {
            index = ch - 'a';
            if(!curr->child[index]) {
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *curr = root;
        int index;
        for(char ch: prefix) {
            index = ch - 'a';
            if(!curr->child[index]){
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */














class Trie {
    struct Trienode {
        char val;
        int count;
        int endsHere;
        Trienode *child[26];
        
        Trienode(char value) {
            val = value;
            count = endsHere = 0;
            for(int i=0;i<26;++i)
                child[i] = NULL;
        }
    };
    
    Trienode *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Trienode('/');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode *curr = root;
        int index;
        for(char ch: word) {
            index = ch - 'a';
            if(!curr->child[index]) {
                curr->child[index] = new Trienode(ch);
            }
            curr->child[index]->count++;
            curr = curr->child[index];
        }
        curr->endsHere++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode *curr = root;
        int index;
        for(char ch: word) {
            index = ch - 'a';
            if(!curr->child[index]) {
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *curr = root;
        int index;
        for(char ch: prefix) {
            index = ch - 'a';
            if(!curr->child[index]){
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
