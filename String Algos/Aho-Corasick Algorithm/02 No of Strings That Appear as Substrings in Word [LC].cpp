// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/

/*
Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.
 

Example 1:
Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.

Constraints:
1 <= patterns.length <= 100
1 <= patterns[i].length <= 100
1 <= word.length <= 100
patterns[i] and word consist of lowercase English letters.
*/

class Solution {
public:
    struct Node {
        Node* child[26];
        Node* fail;
        vector<int> output;

        Node() {
            memset(child, 0, sizeof(child));
            fail = nullptr;
        }
    };

    Node* root = new Node();

    void insert(const string& s, int id) {
        Node* cur = root;

        for (char c : s) {
            int idx = c - 'a';

            if (!cur->child[idx])
                cur->child[idx] = new Node();

            cur = cur->child[idx];
        }

        cur->output.push_back(id);
    }

    void build() {
        queue<Node*> q;

        root->fail = root;

        // First level
        for (int c = 0; c < 26; c++) {
            if (root->child[c]) {
                root->child[c]->fail = root;
                q.push(root->child[c]);
            } else {
                root->child[c] = root;
            }
        }

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for (int c = 0; c < 26; c++) {
                if (cur->child[c]) {
                    Node* f = cur->fail;

                    while (!f->child[c])
                        f = f->fail;

                    cur->child[c]->fail = f->child[c];

                    // inherit outputs
                    for (int id : f->child[c]->output)
                        cur->child[c]->output.push_back(id);

                    q.push(cur->child[c]);
                } else {
                    cur->child[c] = cur->fail->child[c];
                }
            }
        }
    }

    int numOfStrings(vector<string>& patterns, string word) {

        for (int i = 0; i < patterns.size(); i++)
            insert(patterns[i], i);

        build();

        vector<bool> found(patterns.size(), false);

        Node* cur = root;

        for (char ch : word) {
            int idx = ch - 'a';

            cur = cur->child[idx];

            for (int id : cur->output)
                found[id] = true;
        }

        int ans = 0;
        for (bool x : found)
            ans += x;

        return ans;
    }
};
