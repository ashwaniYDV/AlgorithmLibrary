#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>n;a<n?i+=1:i-=1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;

const ll mod = 1000000007;
const ll N = 1e6+5, M = N, ninf = -2e5, inf = (int)1e9;
vl g[N], dist;
ll a[N], b[N], dp[N], in[N], out[N], vis[N], level[N];
ll n, m;


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
