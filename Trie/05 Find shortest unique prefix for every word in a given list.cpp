// https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/

/*
Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

Examples:
Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z

Explanation: dog   => dog
             dove  => dov 
             duck  => du
             zebra => z 

Input: arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
Output: geeksf, geeksg, geeksq
*/

/*
An Efficient Solution is to use Trie. The idea is to maintain a count in every node. Below are steps.
1) Construct a Trie of all words. Also maintain frequency of every node (Here frequency is number of times node is visited during insertion). 
   Time complexity of this step is O(N) where N is total number of characters in all words.
2) Now, for every word, we find the character nearest to the root with frequency as 1. 
   The prefix of the word is path from root to this character. To do this, we can traverse Trie starting from root. 
   For every node being traversed, we check its frequency. If frequency is one, we print all characters from root to this node and don’t traverse down this node.
*/


struct TrieNode {
    map<char, TrieNode*> children;
    int freq, isWordEnd;
    TrieNode() {
        freq = isWordEnd = 0;
    }
};

void insert(TrieNode *root,  const string key) {
    TrieNode *cur = root;
    for (char ch: key) {
        if (!cur->children[ch]) {
            cur->children[ch] = new TrieNode();
        }
        cur = cur->children[ch];
        cur->freq++;
    }
    cur->isWordEnd++;
}

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

void findPrefixes(TrieNode *root, string prefix) {
    // Corner case
    if (!root) return;
  
    // Base case
    if (root->freq == 1) {
       cout << prefix << " ";
       return;
    }
  
    for(auto it: root->children) {
       if (it.second) {
           prefix.push_back(it.first);
           findPrefixes(it.second, prefix);
           prefix.pop_back();
       }
    }
}
 
void solve() {
    vector<string> a = {"zebra", "dog", "duck", "dove"};

    TrieNode* root = new TrieNode();
    for(string x: a) {
        insert(root, x);
    }
    
    string prefix;
    findPrefixes(root, prefix);
}
