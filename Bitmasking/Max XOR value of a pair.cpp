// https://www.geeksforgeeks.org/maximum-xor-of-two-numbers-in-an-array/

const int N = 5e5+5;
int n, m;

// string numTo32BitBinaryString(ll x){
//     string s;
//     while(x){
//         s.pb((char)(x % 2 + 48));
//         x /= 2;
//     }
//     ll l = s.size();
//     for(ll i = 0; i < 32-l; i++){
//         s.pb('0');
//     }
//     reverse(all(s));
//     return s;
// }

struct TrieNode {
    map<char, TrieNode*> children;
    int count;
    TrieNode() {
        count = 0;
    }
};

TrieNode *root = new TrieNode();

void insert(string word) {
    TrieNode *current = root;
    for(char ch: word) {
        if(!current->children[ch]) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
        current->count++;
    }
}

string maxXORfun(string word) {
    TrieNode *current = root;
    string s;
    for(char ch: word) {
        TrieNode *node;

        if(ch == '0') {
            node = current->children['1'];
            if(!node) {
                node = current->children['0'];
                s.pb('0');
            } else {
                s.pb('1');
            }
        } else {
            node = current->children['0'];
            if(!node) {
                node = current->children['1'];
                s.pb('0');
            } else {
                s.pb('1');
            }
        }
        current = node;
    }
    return s;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    string s = bitset<32>(a[0]).to_string();
    insert(s);

    int mxXor = 0;
    for(int i = 1; i < n; i++) {
        s = bitset<32>(a[i]).to_string();
        string xorsStr = maxXORfun(s);
        int num = 0;
        for(ll i = 0; i < 32; i++){
            num += (xorsStr[i] == '1') ? (1 << (31-i)) : 0;
        }
        mxXor = max(mxXor, num);
        insert(s);
    }
    cout << mxXor << endl;
}
