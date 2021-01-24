// https://codeforces.com/contest/145/problem/E

#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for(int i=a;i<n;i++)
#define loop(i,a, n) for(int i = a; i <= n; i++)
#define loopb(i,a, n) for(int i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 5e5+5;
const int N = 1e6+5;
int n, m;

struct data{
    int n4;
    int n7;
    int n47;
    int n74;
    data() : n4(0), n7(0), n47(0), n74(0) {};
};

char arr[N];
ll lazy[4 * N];
data tree[4 * N];
 
void build(ll node, ll start, ll end) {
    if(start == end){
        if(arr[start] == '4'){
            tree[node].n4 = 1;
            tree[node].n7 = 0;
        }
        if(arr[start] == '7'){
            tree[node].n7 = 1;
            tree[node].n4 = 0;
        }
        tree[node].n47 = 1;
        tree[node].n74 = 1;
        return;
    }
    ll mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node].n4 = tree[2*node].n4 + tree[2*node+1].n4;
    tree[node].n7 = tree[2*node].n7 + tree[2*node+1].n7;
    tree[node].n47 = max(tree[2*node].n4 + tree[2*node+1].n47, tree[2*node].n47 + tree[2*node+1].n7);
    tree[node].n74 = max(tree[2*node].n7 + tree[2*node+1].n74, tree[2*node].n74 + tree[2*node+1].n4);
}
 
void update(ll node, ll start, ll end, ll l, ll r){
    if(lazy[node] % 2 == 1){
        swap(tree[node].n4, tree[node].n7);
        swap(tree[node].n47, tree[node].n74);
        if(start != end){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l>end || r<start || l>r) return;
    if(l<=start && end<=r){
        swap(tree[node].n4, tree[node].n7);
        swap(tree[node].n47, tree[node].n74);
        if(start != end){
            lazy[2*node] += 1;
            lazy[2*node+1] += 1;
        }
        lazy[node]=0;
        return;
    }

    ll mid=(start+end)/2;

    update(2*node,start,mid,l,r);
    update(2*node+1,mid+1,end,l,r);

    tree[node].n4 = tree[2*node].n4 + tree[2*node+1].n4;
    tree[node].n7 = tree[2*node].n7 + tree[2*node+1].n7;
    tree[node].n47 = max(tree[2*node].n4 + tree[2*node+1].n47, tree[2*node].n47 + tree[2*node+1].n7);
    tree[node].n74 = max(tree[2*node].n7 + tree[2*node+1].n74, tree[2*node].n74 + tree[2*node+1].n4);
}
 
ll query(ll node, ll start, ll end){
    if(lazy[node] % 2 == 1) {
        swap(tree[node].n4, tree[node].n7);
        swap(tree[node].n47, tree[node].n74);
        if(start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    return tree[node].n47;
}


void solve() {
    ll q, t, x, y, l, r, v;
    cin >> n >> m;
    loop(i, 1, n) cin >> arr[i];
    build(1, 1, n);
    string s;
    while(m--){
        cin >> s;
        if(s == "count"){
            cout << query(1, 1, n) << endl;
        }else{
            cin >> l >> r;
            update(1, 1, n, l, r);
        }
    }
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
