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


struct trie {
    bool isLeaf;
    unordered_map<char, trie*> map;
    trie(){
        isLeaf=false;
    }
};

trie* head = nullptr;

void insert(trie*& head, string str){
    if(head == nullptr){
        head = new trie();
    }
    trie* curr = head;
    for(char x: str){
        if(!curr->map.count(x)){
            curr->map[x] = new trie();
        }
        curr = curr->map[x];
    }
    curr->isLeaf  =true;
}

bool search(trie* head, string str){
    if(head == nullptr) return false;
    trie* curr = head;
    for(char x: str){
        if(curr==nullptr || !curr->map.count(x)){
            return false;
        }
        curr = curr->map[x];
    }
    return curr->isLeaf;
}

bool haveChildren(trie const* curr){
    for(auto it: curr->map){
        if(it.second != nullptr){
            return true;
        }
    }
    return false;
}

bool deletion(trie*& curr, char* str){
    if(curr == nullptr) return false;

    if(*str){
        if(curr!=nullptr && curr->map.count(*str) && deletion(curr->map[*str], str+1) && curr->isLeaf==false){
            if(!haveChildren(curr)){
                delete curr;
                curr=nullptr;
                return true;
            }else{
                return false;
            }
        }
    }
    if(*str=='\0' && curr->isLeaf){
        if(!haveChildren(curr)){
            delete curr;
            curr=nullptr;
            return true;
        }else{
            curr->isLeaf=false;
            return false;
        }
    }
    return false;
}


int32_t main()
{
    IOS
    ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;
    cin>>n;
    string s;
    f(i,n){
        cin>>s;
        insert(head, s);
    }
    s="ashwani";
    cout<<(search(head, s)? "Found" : "Not Found")<<endl;
    deletion(head, const_cast<char*>(s.c_str()));
    cout<<(search(head, s)? "Found" : "Not Found")<<endl;
    s="killer";
    cout<<(search(head, s)? "Found" : "Not Found")<<endl;
    deletion(head, const_cast<char*>(s.c_str()));
    cout<<(search(head, s)? "Found" : "Not Found")<<endl;
}
