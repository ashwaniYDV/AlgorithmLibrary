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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e5+2;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

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

string maxXORfun(string word){
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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    string s = bitset<32>(a[0]).to_string();
    insert(s);

    int mxXor = 0;
    for(int i = 1; i < n; i++) {
        s = bitset<32>(a[i]).to_string();
        s = maxXORfun(s);
        int num = 0;
        for(ll i = 0; i < 32; i++){
            num += (s[i] == '1') ? (1 << (31-i)) : 0;
        }
        mxXor = max(mxXor, num);

        s = bitset<32>(a[i]).to_string();
        insert(s);
    }
    cout << mxXor << endl;
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
