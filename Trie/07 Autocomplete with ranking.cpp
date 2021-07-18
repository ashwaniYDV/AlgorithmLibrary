// https://www.scaler.com/hire/test/problem/auto-complete/

/*
There is a dictionary A of N words and ith word has a unique weight Wi.
An another string array B of size M contains the prefixes. 
For every prefix B[i], output atmost 5 words from the dictionary A which start with same prefix.
Output the words in decreasing order of their weight.
NOTE: If there is no word which start with the given prefix output -1.
*/

/*
Create a prefix Trie, but the Node of a Trie will also contain an array that will denote the answer for each prefix B[i].
How?
Sort the given dictionary in decreasing order of its weight. 
Now insert the word in the Trie and update the answer array if its size is less than 5 (Since we need to output atmost 5 words).
For each query, search for the prefix. 
If no word exists in the trie with the given prefix output -1.
Else, the answer array at the end of prefix will be the answer.
Print the answer in the given format.
*/

#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode * child[26];
    vector < int> idx_ans;
    bool isend;
};

TrieNode * getNode() {
    TrieNode * pNode = new TrieNode;
    pNode -> isend = false;
    for (int i = 0; i < 26; i++)
        pNode -> child[i] = NULL;
    return pNode;
}

void insert(TrieNode * root, string word, int idx) {
    TrieNode * temp = root;
    for (int i = 0; i < word.size(); i++) {
        int chr_val = word[i] - 'a';
        if (temp -> child[chr_val] == NULL) {
            temp -> child[chr_val] = getNode();
        }
        temp = temp -> child[chr_val];
        if (temp -> idx_ans.size() < 5) {
            temp -> idx_ans.push_back(idx);
        }
    }
    temp -> isend = true;
}

vector <int> query(TrieNode * root, string prefix, vector < int > & W) {
    TrieNode * temp = root;
    for (int i = 0; i < prefix.size(); i++) {
        int chr_val = prefix[i] - 'a';
        if (temp -> child[chr_val] == NULL) {
            temp = temp -> child[chr_val];
            break;
        }
        temp = temp -> child[chr_val];
    }
    if (temp == NULL) {
        return {};
    }
    return temp -> idx_ans;
}

void solve(vector < string > & A, vector < int > & W, vector < string > & B) {
    TrieNode * root = getNode();
    vector < pair < int, int > > v;
    for (int i = 0; i < A.size(); i++) {
        v.push_back({W[i], i});
    }
    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--) {
        insert(root, A[v[i].second], v[i].second);
    }

    for (int i = 0; i < B.size(); i++) {
        vector < int> ans = query(root, B[i], W);
        if (ans.size() == 0) {
            cout << "-1 " << endl;
        } else {
            for (int j = 0; j < ans.size(); j++) {
                cout << A[ans[j]] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector < string > A(n);
        vector < int > W(n);
        vector < string > B(m);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> W[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> B[i];
        }
        solve(A, W, B);
    }
}
