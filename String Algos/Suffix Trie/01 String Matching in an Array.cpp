// https://leetcode.com/problems/string-matching-in-an-array/editorial/

/*
Given an array of string words, return all strings in words that is a substring of another word. 
You can return the answer in any order.

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
 

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.
*/


// Method 1: Suffix Trie
class Solution {
public:
    struct TrieNode {
        int freq;
        unordered_map<char, TrieNode*> child;
        TrieNode() {
            freq = 0;
        }
    };

    // Function to insert a word (or suffix) into the Trie.
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (!temp->child.count(c)) {
                temp->child[c] =  new TrieNode();
            }
            temp = temp->child[c];
            // Increment the frequency of the node.
            temp->freq++;
        }
    }

    // Function to check if a word exists as a substring in the Trie.
    bool isSubstring(TrieNode* root, string& word) {
        TrieNode* temp = root;
        for (char c : word) {
            temp = temp->child[c];
        }
        // A word is a substring or a different string if its frequency in the Trie is greater than 1.
        return temp->freq > 1;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        TrieNode* root = new TrieNode();

        // Insert all suffixes of each word into the Trie.
        for (const auto& word : words) {
            for (int startIndex = 0; startIndex < word.size(); startIndex++) {
                // Insert each suffix starting from index `startIndex`.
                insertWord(root, word.substr(startIndex));
            }
        }

        for (auto word : words) {
            if (isSubstring(root, word)) {
                res.push_back(word);
            }
        }

        return res;
    }
};



// Method 2: KMP
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        
        for(int i = 0; i < n; i++) {
            bool flag = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                if(words[j].find(words[i]) < words[j].size()) {
                    cout << i << " " << j << endl;
                    flag = 1;
                    break;
                }
            }

            if(flag) res.push_back(words[i]);
        }

        return res;
    }
};
