// https://www.spoj.com/problems/PHONELST/

/*
Given a list of phone numbers, determine if it is consistent in the sense that no number is the prefix of another. 
Let’s say the phone catalogue listed these numbers:

Emergency = 911
Alice = 97625999
Bob = 91125426
In this case, it’s not possible to call Bob, because the central would direct your call to the emergency line 
as soon as you had dialled the first three digits of Bob’s phone number. So this list would not be consistent.

Input
The first line of input gives a single integer, 1 <= t <= 40, the number of test cases. 
Each test case starts with n, the number of phone numbers, on a separate line, 1 <= n <= 10000. 
Then follows n lines with one unique phone number on each line. A phone number is a sequence of at most ten digits.

Output
For each test case, output “YES” if the list is consistent, or “NO” otherwise.
*/




/*
Two checks required:
Case 1: 
If current inserted number is bigger in number of digits than already inserted ones.
Case 2: 
If current inserted number is smaller in number of digits than already inserted ones.
*/

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
        // Case 1 check
        if(cur->children[ch] && cur->children[ch]->isLeaf) {
            check = 0;
        }
        if (!cur->children[ch]) {
            cur->children[ch] = new TrieNode();
        }
        cur = cur->children[ch];
    }
    cur->isLeaf = true;
    // Case 2 check
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
