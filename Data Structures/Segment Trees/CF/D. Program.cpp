// https://codeforces.com/contest/1473/problem/D

#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
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
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MOD2 998244353
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 2e5+5;
int n, m;


struct node {
    int mn;
    int mx;
};
node st[4*N];

int arr[N];


void build(int si , int ss , int se) {
    if(ss == se) {
        st[si].mn = arr[ss];
        st[si].mx = arr[ss];
        return;
    }
 
    int mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    st[si].mn = min(st[2*si].mn , st[2*si+1].mn);
    st[si].mx = max(st[2*si].mx , st[2*si+1].mx);
}

int queryMin(int si , int ss , int se , int qs , int qe) {
    if(qe < ss || qs > se)
        return INF;
 
    if(ss >= qs && se <= qe)
        return st[si].mn;
 
    int mid = (ss + se)/2;
    int l = queryMin(2*si , ss , mid , qs , qe);
    int r = queryMin(2*si+1 , mid+1 , se , qs , qe);
 
    return min(l , r);
}

int queryMax(int si , int ss , int se , int qs , int qe) {
    if(qe < ss || qs > se)
        return -INF;
 
    if(ss >= qs && se <= qe)
        return st[si].mx;
 
    int mid = (ss + se)/2;
    int l = queryMax(2*si , ss , mid , qs , qe);
    int r = queryMax(2*si+1 , mid+1 , se , qs , qe);
 
    return max(l , r);
}
 
void solve() {
    int x, y, l, r;
    cin >> n >> m;
    string s;
    cin >> s;
    s = "#" + s;

    x = 0;
    loop(i, 1, n) {
        if(s[i] == '+') {
            x++;
        } else {
            x--;
        }
        arr[i] = x;
    }

    build(1, 1, n);

    int mx, mn;
    while(m--) {
        cin >> l >> r;
        int exclude = arr[r] - arr[l-1];

        if(r < n) {
            mx = max(queryMax(1, 1, n, 1, l-1), queryMax(1, 1, n, r+1, n) - exclude);
            mn = min(queryMin(1, 1, n, 1, l-1), queryMin(1, 1, n, r+1, n) - exclude);
        } else {
            mx = queryMax(1, 1, n, 1, l-1);
            mn = queryMin(1, 1, n, 1, l-1);
            if(mx == -INF) {
                mx = mn = 0;
            }
        }

        // i.e. mx and mn are of same sign
        if(mx*mn > 0) {
            cout << mx - mn + 2 << endl;
        } else {
            cout << mx - mn + 1 << endl;
        }
    }
    
}   
 
int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
