// https://codeforces.com/contest/52/problem/C

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

int arr[N], tree[4 * N], lazy[4 * N];
 
void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
 
void update(int node, int start, int end, int l, int r, int val) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node];
        if(start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(l > end || r < start || l > r) return;

    if(l <= start && end <= r) {
        tree[node] += val;
        if(start != end) {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        lazy[node] = 0;
        return;
    }
    int mid = (start + end) / 2;
    update(2*node, start, mid, l, r, val);
    update(2*node+1, mid+1, end, l, r, val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
 
int query(int node, int start, int end, int l, int r) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node];
        if(start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(l > end || r<start || l > r)return INT_MAX;

    if(l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return min(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
}


void solve() {
    int q, t, x, y, l, r, v;
    cin >> n;
    loop(i, 1, n) cin >> arr[i];
    build(1, 1, n);

    cin >> q;

    string s;
    cin.ignore();
    int a[3];
    while(q--) {
        getline(cin, s, '\n');
        stringstream in (s);
        in >> a[0] >> a[1];
        if(in >> a[2]) {
            if(a[0] > a[1]) {
                update(1, 1, n, 1, a[1] + 1, a[2]);
                update(1, 1, n, a[0] + 1, n, a[2]);
            } else {
                update(1, 1, n, a[0] + 1, a[1] + 1, a[2]);
            }
        } else {
            if(a[0] > a[1]) {
                cout << min(query(1, 1, n, 1, a[1] + 1), query(1, 1, n, a[0] + 1, n)) << endl;
            }else{
                cout << query(1, 1, n, a[0] + 1, a[1] + 1) << endl;
            }
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
