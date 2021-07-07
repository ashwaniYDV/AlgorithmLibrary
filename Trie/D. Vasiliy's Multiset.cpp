// https://codeforces.com/contest/706/problem/D


// Method 1
const int N = 1e5+5;
int n, m;

string numTo32BitBinaryString(ll x){
    string s;
    while(x){
        s.pb((char)(x % 2 + 48));
        x /= 2;
    }
    ll l = s.size();
    for(ll i = 0; i < 32-l; i++){
        s.pb('0');
    }
    reverse(all(s));
    return s;
}

struct TrieNode{
    map<char,TrieNode*> children;
    int count;
    TrieNode(){
        count=0;
    }
};

TrieNode *root = new TrieNode();

void insert(string word){
    TrieNode *current = root;
    for(char ch: word){
        TrieNode *node = current->children[ch];
        if(!node){
            node = new TrieNode();
            current->children[ch] = node;
        }
        current = node;
        current->count++;
    }
}

void deletion(string word){
    TrieNode *current = root;
    for(char ch: word){
        TrieNode *node = current->children[ch];
        TrieNode *prev = current;

        current = node;
        current->count--;
        if(current->count == 0){
            prev->children[ch] = NULL;
        }
    }
}

string maXOR(string word){
    TrieNode *current = root;
    string s;
    for(int i = 0; i < word.size(); i++){
        TrieNode *node;

        if(word[i] == '0'){
            node = current->children['1'];
            if(!node){
                node = current->children['0'];
                s.pb('0');
            }else{
                s.pb('1');
            }
        }else{
            node = current->children['0'];
            if(!node){
                node=current->children['1'];
                s.pb('0');
            }else{
                s.pb('1');
            }
        }
        current=node;
    }
    return s;
}

void solve() {
    ll t, k, d, x, y, z;
    string s;
    f(i, 32){
        s.pb('0');
    }
    insert(s);
    cin >> n;
    while(n--){
        char ch;
        cin >> ch >> x;
        string s = numTo32BitBinaryString(x);
        if(ch == '+'){
            insert(s);
        }else if(ch == '-'){
            deletion(s);
        }else{
            ll ans = 0;
            s = maXOR(s);
            for(ll i = 0; i < 32; i++){
                ans += (s[i] == '1') ? (1 << (31-i)) : 0;
            }
            cout<< ans << endl;
        }
    }
}



































// Method 2
const int N = 1e5+5;
int n, m;
 
typedef struct trie {
    typedef struct node {
        node* nxt[2];
        int cnt = 0;
        node() {
            nxt[0] = nxt[1] = NULL;
            cnt = 0;
        }
 
    } Node;
 
    Node* head;
 
    trie() {
        head = new Node();
    }
 
    void insert(int x) {
        Node* cur = head;
        for(int i = 30; i >= 0; i--) {
            int b = (x >> i) & 1;
            if(!cur -> nxt[b])
                cur -> nxt[b] = new Node();
            cur = cur -> nxt[b];
            cur -> cnt++;
        }
    }
 
    void remove(int x) {
        Node* cur = head;
        for(int i = 30; i >= 0; i--) {
            int b = (x >> i) & 1;
            cur = cur -> nxt[b];
            cur -> cnt--;
        }
    }
 
    int maxxor(int x) {
        Node* cur = head;
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int b = (x >> i) & 1;
            if(cur -> nxt[!b] && cur -> nxt[!b] -> cnt > 0) {
                ans += (1LL << i);
                cur = cur -> nxt[!b];
            } else {
                cur = cur -> nxt[b];
            }
        }
        return ans;
    }
} Trie;
 
 
Trie t;
 
void solve() {
    int x, q;
    cin >> q;
    t.insert(0);
 
    while(q--) {
        char ch;
        cin >> ch;
        cin >> x;
        if(ch == '+')
            t.insert(x);
        else if(ch == '-')
            t.remove(x);
        else
            cout << t.maxxor(x) << endl;
    }
}



































// Method 3
const int N = 1e5+5;
int n, m;

struct Trie {
    struct Node {
        Node* nxt[2];
        int cnt = 0;
        Node() {
            nxt[0] = nxt[1] = NULL;
            cnt = 0;
        }
    };

    Node* head;

    Trie() {
        head = new Node();
    }

    void insert(int x) {
        Node* cur = head;
        for(int i = 30; i >= 0; i--) {
            int b = (x >> i) & 1;
            if(!cur -> nxt[b])
                cur -> nxt[b] = new Node();
            cur = cur -> nxt[b];
            cur -> cnt++;
        }
    }

    void remove(int x) {
        Node* cur = head;
        for(int i = 30; i >= 0; i--) {
            int b = (x >> i) & 1;
            cur = cur -> nxt[b];
            cur -> cnt--;
        }
    }

    int maxxor(int x) {
        Node* cur = head;
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int b = (x >> i) & 1;
            if(cur -> nxt[!b] && cur -> nxt[!b] -> cnt > 0) {
                ans += (1LL << i);
                cur = cur -> nxt[!b];
            } else {
                cur = cur -> nxt[b];
            }
        }
        return ans;
    }
};

void solve() {
    int x, q;
    cin >> q;
    Trie t = Trie();
    t.insert(0);

    while(q--) {
        char ch;
        cin >> ch;
        cin >> x;
        if(ch == '+')
            t.insert(x);
        else if(ch == '-')
            t.remove(x);
        else
            cout << t.maxxor(x) << endl;
    }
}
