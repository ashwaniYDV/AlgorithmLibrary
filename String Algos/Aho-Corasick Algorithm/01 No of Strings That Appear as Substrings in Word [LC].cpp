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

// Method 1: aho corasick
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





// Method 2: Suffix Tree / Suffix Trie
class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];

        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    void insertSuffixes(const string& word) {
        int n = word.size();

        for (int i = 0; i < n; i++) {
            TrieNode* cur = root;

            for (int j = i; j < n; j++) {
                int idx = word[j] - 'a';

                if (cur->child[idx] == nullptr)
                    cur->child[idx] = new TrieNode();

                cur = cur->child[idx];
            }
        }
    }

    bool search(const string& pat) {
        TrieNode* cur = root;

        for (char c : pat) {
            int idx = c - 'a';

            if (cur->child[idx] == nullptr)
                return false;

            cur = cur->child[idx];
        }

        return true;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        insertSuffixes(word);

        int ans = 0;

        for (const string& pat : patterns) {
            if (search(pat))
                ans++;
        }

        return ans;
    }
};




// Method 3: Rabin carp
class Solution {
public:
    using ll = long long;

    const ll base = 256;
    const ll mod = 1000000009LL;

    ll binpow(ll a, ll b) {
        a %= mod;
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    bool check(int start, const string &word, const string &pat) {
        for (int i = 0; i < pat.size(); i++) {
            if (word[start + i] != pat[i]) return false;
        }
        return true;
    }

    bool contains(const string &word, const string &pat) {
        int n = word.size(), m = pat.size();

        if (m > n) return false;

        ll hashWord = 0, hashPat = 0;
        ll base_pow = binpow(base, m - 1);

        // First window
        for (int i = 0; i < m; i++) {
            hashPat = (hashPat * base + pat[i]) % mod;
            hashWord = (hashWord * base + word[i]) % mod;
        }

        if (hashPat == hashWord && check(0, word, pat))
            return true;

        // Sliding window
        for (int i = m; i < n; i++) {
            hashWord =
                ((hashWord - (ll)word[i - m] * base_pow) * base + word[i]) % mod;

            if (hashWord < 0)
                hashWord += mod;

            int start = i - m + 1;

            if (hashPat == hashWord && check(start, word, pat))
                return true;
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (const string &pat : patterns) {
            if (contains(word, pat))
                ans++;
        }

        return ans;
    }
};




// Method 4: Brute force
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();

        unordered_set<string> st;

        for (int i = 0; i < n; i++) {
            string cur;
            for (int j = i; j < n; j++) {
                cur += word[j];
                st.insert(cur);
            }
        }

        int res = 0;
        for (auto &p: patterns)
            res += st.count(p);

        return res;
    }
};
