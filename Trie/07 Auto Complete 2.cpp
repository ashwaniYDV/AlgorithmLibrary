/*
Design “Ls” command (search function) given a list of files in an array.
Hint: use tries.
Input: [“fun”, “funny”, “foo”, “spam”, “set”]

4
“Ls f”
“Ls fu”
“Ls s”
“Ls r”

Output: 
fun funny foo
fun funny
spam set
-1
*/

#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    int isWordEnd;
    TrieNode() {
        isWordEnd = 0;
    }
};

void insert(TrieNode *root,  const string key) {
    TrieNode *cur = root;
    for (char ch : key) {
        if (!cur->children[ch]) {
            cur->children[ch] = new TrieNode();
        }
        cur = cur->children[ch];
    }
    cur->isWordEnd = 1;
}

TrieNode* search(TrieNode *root, string key) {
    TrieNode *cur = root;
    for (char ch : key) {
        if (!cur->children[ch]) {
            return NULL;
        }
        cur = cur->children[ch];
    }
    return cur;
}

void findAutoComplete(TrieNode *root, string prefix) {
    if (!root) return;

    if (root->isWordEnd == 1) {
        cout << prefix << " ";
    }

    for (auto it : root->children) {
        if (it.second) {
            prefix.push_back(it.first);
            findAutoComplete(it.second, prefix);
            prefix.pop_back();
        }
    }
}

void solve() {
    vector<string> a = {"fun", "funny", "foo", "spam", "set"};

    TrieNode* root = new TrieNode();
    for (string s : a) {
        insert(root, s);
    }

    vector<string> queries = {"f", "fu", "s", "r"};

    for (string s : queries) {
        TrieNode *r = search(root, s);
        if (r) {
            findAutoComplete(r, s);
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
