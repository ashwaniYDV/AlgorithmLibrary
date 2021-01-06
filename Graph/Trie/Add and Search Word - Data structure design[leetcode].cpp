// https://leetcode.com/problems/add-and-search-word-data-structure-design/

class WordDictionary {
public:
    struct TrieNode{
        unordered_map<char, TrieNode*> mp;
        bool eow;
        TrieNode(){
            eow = false;
        }
    };
    
    TrieNode *root = nullptr;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *current = root;
        for(char ch: word){
            if(!current->mp[ch]){
                current->mp[ch] = new TrieNode();
            }
            current = current->mp[ch];
        }
        current->eow = true;
    }
    
    bool searchFun(string word, int pos, TrieNode *root){  
        if(pos == word.size()){
            if(root->eow == true)
                return true;
            return false;
        }
        if(word[pos] != '.'){
            if(!root->mp.count(word[pos]))
                return false;
            return searchFun(word, pos + 1, root->mp[word[pos]]);
        }

        for(auto x: root->mp){
            if(searchFun(word, pos + 1, x.second)) {
                return true;
            }
        }
        return false;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchFun(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
