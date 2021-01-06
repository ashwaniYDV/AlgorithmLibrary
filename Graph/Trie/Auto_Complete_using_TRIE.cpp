// https://youtu.be/DfkLGiW8vNA

// Preorder traversal is used to print lexicographically

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug(x) cout << #x << " is: " << (x) << endl;
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;i<n;i++)
#define loop(i,a, n) for(ll i = a; i <= n; i++)
#define loopb(i,a, n) for(ll i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setmem(x, k) memset(x, k, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e5+1;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

// trie node 
struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];

    // isWordEnd is true if the node represents end of a word 
    bool isWordEnd;
}; 

// Returns new trie node (initialized to NULLs) 
TrieNode *getNode(void) { 
    TrieNode *pNode = new TrieNode; 
    pNode->isWordEnd = false; 

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL;
    }

    return pNode;
} 

// If not present, inserts key into trie. If the 
// key is prefix of trie node, just marks leaf node 
void insert(TrieNode *root, const string key) { 
    TrieNode *pCrawl = root; 

    for (int level = 0; level < key.length(); level++) { 
        int index = CHAR_TO_INDEX(key[level]); 
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode(); 
        }

        pCrawl = pCrawl->children[index]; 
    } 

    // mark last node as leaf 
    pCrawl->isWordEnd = true; 
} 

// Returns true if key presents in trie, else false 
bool search(TrieNode *root, const string key) { 
    int length = key.length(); 
    TrieNode *pCrawl = root; 
    for (int level = 0; level < length; level++) { 
        int index = CHAR_TO_INDEX(key[level]); 

        if (!pCrawl->children[index]) {
            return false; 
        }

        pCrawl = pCrawl->children[index]; 
    } 

    return (pCrawl != NULL && pCrawl->isWordEnd); 
} 

// Returns 0 if current node has a child 
// If all children are NULL, return 1. 
bool isLastNode(TrieNode* root) { 
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) 
            return 0; 
    }
    return 1; 
} 

// Recursive function to print auto-suggestions for given node. 
void suggestionsRec(TrieNode* root, string currPrefix) { 
    // found a string in Trie with the given prefix 
    if (root->isWordEnd) { 
        cout << currPrefix << endl;
    } 

    // All children struct node pointers are NULL 
    if (isLastNode(root)) 
        return; 

    for (int i = 0; i < ALPHABET_SIZE; i++) { 
        if (root->children[i]) { 
            // append current character to currPrefix string 
            currPrefix.push_back(97 + i); 

            // recur over the rest 
            suggestionsRec(root->children[i], currPrefix); 
        } 
    } 
} 

// print suggestions for given query prefix. 
int printAutoSuggestions(TrieNode* root, const string query) { 
    TrieNode* pCrawl = root; 

    // Check if prefix is present and find the 
    // the node (of last level) with last character 
    // of given string. 
    int level; 
    int n = query.length(); 
    for (level = 0; level < n; level++) { 
        int index = CHAR_TO_INDEX(query[level]); 

        // no string in the Trie has this prefix 
        if (!pCrawl->children[index]) 
            return 0; 

        pCrawl = pCrawl->children[index]; 
    } 

    // If prefix is present as a word. 
    bool isWord = (pCrawl->isWordEnd == true); 

    // If prefix is last node of tree (has no children) 
    bool isLast = isLastNode(pCrawl); 

    // If prefix is present as a word, but 
    // there is no subtree below the last 
    // matching node. 
    if (isWord && isLast) { 
        cout << query << endl; 
        return -1; 
    } 

    // If there are are nodes below last 
    // matching character. 
    if (!isLast) { 
        string prefix = query; 
        suggestionsRec(pCrawl, prefix); 
        return 1; 
    } 
} 


void solve() {
    ll t, k, d, x, y, z;
    TrieNode* root = getNode(); 
    insert(root, "hello"); 
    insert(root, "dog"); 
    insert(root, "hell"); 
    insert(root, "cat"); 
    insert(root, "a"); 
    insert(root, "hel"); 
    insert(root, "help"); 
    insert(root, "helps"); 
    insert(root, "helping"); 
    int comp = printAutoSuggestions(root, "hel"); 

    if (comp == -1) 
        cout << "No other strings found with this prefix\n"; 

    else if (comp == 0) 
        cout << "No string found with this prefix\n"; 
}


int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    // cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}
