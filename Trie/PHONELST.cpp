// https://www.spoj.com/problems/PHONELST/


int check = 1;

struct TrieNode {
    map<char, TrieNode*> children;
    bool isLeaf;
    TrieNode() {
        isLeaf = false;
    }
};

void insert(TrieNode *root,  string word) {
    TrieNode *cur = root;
    for (char ch: word) {
        if(cur->children[ch] && cur->children[ch]->isLeaf) {
            check = 0;
        }
        if (!cur->children[ch]) {
            cur->children[ch] = new TrieNode();
        }
        cur = cur->children[ch];
    }
    cur->isLeaf = true;
    if(cur->children.size()) {
        check = 0;
    }
}

void solve() {
    check = 1;
    TrieNode* root = new TrieNode();
    cin >> n;
    string s;
    f(i, n) {
        cin >> s;
        insert(root, s);
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}
