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

struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* GetNewNode(int data) {
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Insert(BstNode*& root, int data) {
    if(root == NULL) {
        root = GetNewNode(data);
    }else if(data <= root->data) {
        Insert(root->left, data);
    }else {
        Insert(root->right,data);
    }
}

bool Search(BstNode* root, int data) {
    if(root == NULL) {
        return false;
    }else if(root->data == data) {
        return true;
    }else if(data <= root->data) {
        return Search(root->left,data);
    }else{
        return Search(root->right,data);
    }
}

int maximum_number(BstNode* root) {
    BstNode *tempRoot = root, *tempRoot_value = NULL;
    while(tempRoot != NULL){
        tempRoot_value = tempRoot;
        tempRoot = tempRoot->right;
    }
    return tempRoot_value->data;
}

int minimum_number(BstNode* root) {
    BstNode *tempRoot = root, *tempRoot_value = NULL;
    while(tempRoot!=NULL){
        tempRoot_value = tempRoot;
        tempRoot = tempRoot->left;
    }
    return tempRoot_value->data;
}

void BFS_traversal(BstNode* root) {
    //check if root is empty or not
    if(root == NULL) return;

    queue<BstNode*> q;
    q.push(root);

    BstNode* tempRoot;

    while(!q.empty()) {
        tempRoot = q.front();
        q.pop();

        cout << tempRoot->data << "\t";
        if(tempRoot->left != NULL) q.push(tempRoot->left);
        if(tempRoot->right != NULL) q.push(tempRoot->right);
    }
    cout << endl;
}

void DFS_traversal_preorder(BstNode* root) {
    //check if root is empty or not
    if(root == NULL) return;

    stack<BstNode*> s;
    s.push(root);

    while(!s.empty()) {
        BstNode *tempRoot = s.top();
        s.pop();
        cout << tempRoot->data << "\t";
        if(tempRoot->right != NULL) s.push(tempRoot->right);
        if(tempRoot->left != NULL) s.push(tempRoot->left);
    }
    cout << endl;
}

void DFS_traversal_inorder(BstNode* root) {
    //check if root is empty or not
    if(root == NULL) return;

    stack<BstNode*> s;
    BstNode* tempRoot = root;

    while(tempRoot != NULL || !s.empty()) {
        while(tempRoot != NULL) {
            s.push(tempRoot);
            tempRoot = tempRoot->left;
        }
        tempRoot = s.top();
        s.pop();
        cout << tempRoot->data << "\t";
        tempRoot = tempRoot->right;
    }
    cout << endl;
}

void DFS_traversal_postorder_using_1Stack(BstNode* root) {
    
}

void DFS_traversal_postorder_using_2Stacks(BstNode* root) {
    stack<BstNode*> s1;
    s1.push(root);

    stack<BstNode*> s2;

    BstNode *tempRoot;

    while(!s1.empty()){
        tempRoot = s1.top();
        s1.pop();
        s2.push(tempRoot);
        if(tempRoot->left!=NULL) s1.push(tempRoot->left);
        if(tempRoot->right!=NULL) s1.push(tempRoot->right);
    }
    while(!s2.empty()){
        tempRoot = s2.top();
        s2.pop();
        cout << tempRoot->data << "\t";
    }
    cout << endl;
}

bool IsBST(BstNode* root) {
    if(root == NULL) return false;

    // 1. do inorder traversal
    vector<int> result;
    stack<BstNode*> s;
    BstNode* tempRoot = root;

    while(tempRoot != NULL || !s.empty()) {
        while(tempRoot != NULL) {
            s.push(tempRoot);
            tempRoot = tempRoot->left;
        }
        tempRoot = s.top();
        s.pop();
        result.pb(tempRoot->data);
        tempRoot = tempRoot->right;
    }

    // 2. if arr is sorted then it is a binary tree  else not 
    for(int i=0; i < result.size() - 1; i++){
        if(result[i] > result[i+1]) return false;
    }
    return true;
}


void solve() {
    ll t, k, d, x, y, z;
    BstNode* root = NULL;
    Insert(root, 15);
    Insert(root, 10);
    Insert(root, 20);
    Insert(root, 25);
    Insert(root, 8);
    Insert(root, 12);

    if(Search(root, 8)) cout << "Found\n";
    else cout << "Not Found\n";

    cout << maximum_number(root) << endl;

    cout << minimum_number(root) << endl;

    BFS_traversal(root);

    DFS_traversal_preorder(root);

    DFS_traversal_inorder(root);

    DFS_traversal_postorder_using_1Stack(root);

    DFS_traversal_postorder_using_2Stacks(root);

    cout << IsBST(root) << endl;
    
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
