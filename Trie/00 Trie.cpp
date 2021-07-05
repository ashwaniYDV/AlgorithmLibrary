struct TrieNode{
    map<char,TrieNode*> children;
    int prefixes;
    bool endofword;
    TrieNode(){
        prefixes=0;
        endofword=false;
    }
};

void insert(TrieNode *root, string word){
    TrieNode *current=root;
    for(char ch: word){
        if(!current->children.count(ch)){
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
        current->prefixes++;
    }
    current->endofword=true;
}

bool search(TrieNode *root, string word){
    TrieNode *current=root;
    for(char ch: word){
        TrieNode *node = current->children[ch];
        if(!node)
            return false;
        current=node;
    }
    return current->endofword;
}

int count_prefix(TrieNode *root, string word){
    TrieNode *current=root;
    for(char ch: word){
        TrieNode *node=current->children[ch];
        if(!node){
            return 0;
        }
        current = node;
    }
    return current->prefixes;
}

int32_t main()
{
    IOS
    ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;

    TrieNode *root=new TrieNode();
    insert(root,"shaishta");
    insert(root,"harsh");
    insert(root,"sharmila");
    insert(root,"harry");
    string str;
    cout<<"Enter the prefix :"<<endl;
    cin>>str;
    cout<<count_prefix(root, str)<<endl;
}






















// https://www.geeksforgeeks.org/trie-insert-and-search/


#include <bits/stdc++.h>
using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    // isLeaf is true if the node represents end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
TrieNode *getNode(void) {
    TrieNode *pNode = NULL;
    pNode = (TrieNode *) malloc(sizeof(struct TrieNode));
    if (pNode) {
        int i;
        pNode->isLeaf = false;
        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }
    return pNode;
}

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key) {
    TrieNode *current = root;
    for(char ch: key) {
        int idx = ch - 'a';
        if(!current->children[idx]){
            current->children[idx] = new TrieNode();
        }
        current = current->children[idx];
    }
    current->isLeaf = 1;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) {
    TrieNode *current=root;
    for(char ch: key){
        int idx = ch - 'a';
        TrieNode *node = current->children[idx];
        if(!node)
            return false;
        current=node;
    }
    return current->isLeaf;
}

// Driver
int main() {
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}
