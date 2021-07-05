// https://leetcode.com/problems/group-anagrams/
// https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together-set-2/

/*
Insert the sorted order of each word in the trie. Since all the anagrams will end at the same leaf node. 
We can start a linked list at the leaf nodes where each node represents the index of the original array of words. 
Finally, traverse the Trie and while traversing the Trie, traverse each linked list one line at a time. 

Following are the detailed steps.
1) Create an empty Trie 
2) One by one take all words of input sequence. Do following for each word 
    a) Copy the word to a buffer. 
    b) Sort the buffer 
    c) Insert the sorted buffer and index of this word to Trie. Each leaf node of Trie is head of a Index list. 
       The Index list stores index of words in original sequence. If sorted buffer is already present, we insert index of this word to the index list. 
3) Traverse Trie. While traversing, if you reach a leaf node, traverse the index list. And print all words using the index obtained from Index list. 
*/

class Solution {
public:
    vector<vector<string>> res;
    
    // counting sort of string
    string strCountingSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
    
    struct TrieNode {
        map<char, TrieNode*> children;
        bool isWordEnd;
        vector<int> positions;
        TrieNode() {
            isWordEnd = false;
        }
    };


    void insert(TrieNode *root, string key, int pos) {
        TrieNode *cur = root;
        for (char ch: key) {
            if (!cur->children[ch]) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->isWordEnd = true;
        cur->positions.push_back(pos);
    }

    void go(TrieNode* root, vector<string>& strs) {
        if(!root) return;

        if (root->isWordEnd) {
            vector<string> temp;
            for(int pos: root->positions) {
                temp.push_back(strs[pos]);
            }
            res.push_back(temp);
        }

        for (auto it: root->children) {
            go(it.second, strs);
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < strs.size(); i++) {
            insert(root, strCountingSort(strs[i]), i);
        }
        
        go(root, strs);
        return res;
    }
};
