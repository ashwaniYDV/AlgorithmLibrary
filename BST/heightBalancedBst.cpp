// https://youtu.be/lbxvfL1Oxlk

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
typedef long long int ll;
// #define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
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
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 3e4+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

class BstNode {
private:
    int val;
    BstNode *left, *right;
public:
    BstNode() {
        this->val = 0; this->left = this->right = NULL;
    }
    BstNode(int data) {
        this->val = data; this->left = this->right = NULL;
    }
    BstNode(int data, BstNode *l, BstNode *r) {
        this->val = data; this->left = l; this->right = r;
    }

    BstNode* insert(int data, BstNode *root){
        if(root == NULL) {
            root = new BstNode(data);
            return root;
        }
        if(data <= root->val) {
            root->left = insert(data, root->left);
        } else {
            root->right = insert(data, root->right);
        }
        return root;
    }

    void inorder(BstNode *root) {
        cout << "Inorder:\n";
        if(!root) return;

        stack<BstNode*> s;

        BstNode* tempRoot = root;
        while(tempRoot || !s.empty()) {
            while(tempRoot) {
                s.push(tempRoot);
                tempRoot = tempRoot->left;
            }
            tempRoot = s.top();
            s.pop();
            cout << tempRoot->val << " ";
            tempRoot = tempRoot->right;
        }
        cout << endl;
    }

    BstNode *sortedArrayToHeightBalancedBst(vector<int> a, int l, int r) {
        // base case
        if(l > r) return NULL;

        int mid = ((l + r) >> 1);
        BstNode *root = new BstNode(a[mid]);
        root->left = sortedArrayToHeightBalancedBst(a, l, mid - 1);
        root->right = sortedArrayToHeightBalancedBst(a, mid + 1, r);

        return root;
    }

};

void solve() {
    // sorted array
    vector<int> a {1, 2, 3, 4, 5};
    BstNode *root = NULL;
    root = root->sortedArrayToHeightBalancedBst(a, 0, a.size() - 1);
    root->insert(100, root);
    root->inorder(root);
}

int32_t main() {
    IOS
    solve();
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}

/*
OUTPUT
---------
Inorder:
1 2 3 4 5 100 

*/
