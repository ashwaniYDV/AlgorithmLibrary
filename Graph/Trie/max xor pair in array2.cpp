#include<bits/stdc++.h>
using namespace std;
typedef long long ll;             
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
const ll inf = 1e18, mod = 1e9+7;

struct trie {
    string str;
    bool eow;
    map<char, trie*> mp;
    trie() {
        eow = false;
    }
};

void insert(trie* root, string s) {  
    for(int i = 0; i < s.length(); ++i){
        if(root->mp[s[i]] == NULL){
            root->mp[s[i]] = new trie();
        }
        root = root->mp[s[i]];
    }
    root->str = s;
    root->eow = true;
} 

string fun(trie *root, string s, int idx){
    if(root->eow){
        return root->str;
    }
    if(s[idx] == '0' && root->mp['1']) {
        return fun(root->mp['1'], s, idx + 1);
    } else if(s[idx] == '1' && root->mp['0']) {
        return fun(root->mp['0'], s, idx + 1);
    }
    return fun(root->mp[s[idx]], s, idx + 1);
}

int findMaximumXOR(vector<int> a) {
    int n(a.size());
    int ans = 0, mask = 0;
    trie *root = new trie();
    for(auto x: a){
        string s = bitset<32>(x).to_string();
        insert(root, s);
    }
    int mx = 0;
    for(auto x: a){
        string s = bitset<32>(x).to_string();
        string str = fun(root, s, 0);
        int xr = stoi(str, 0, 2);
        mx = max(mx, (xr ^ x));
    }
    return mx;
}
int main(){
    fast;
    vector<int> a = {2,3,5,8,10,25};
    cout<<findMaximumXOR(a) ;
    return 0;
}
