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
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5;
int n, m;

const int p = 31;
const int mod = 1e9 + 9;
vector<int> p_pow;

string s, s_rev;
int st[4*N];
int st_rev[4*N];

void build(int si, int ss, int se) {
    if(ss == se) {
        st[si] = s[ss] - 'a' + 1;
        return;
    }
 
    int mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);

    st[si] = (st[2*si] + (st[2*si+1] * p_pow[mid - ss + 1]) % mod + mod) % mod;
}

void build_rev(int si, int ss, int se) {
    if(ss == se) {
        st_rev[si] = s_rev[ss] - 'a' + 1;
        return;
    }
 
    int mid = (ss + se)/2;
    build_rev(2*si , ss , mid);
    build_rev(2*si+1 , mid+1 , se);
 
    st_rev[si] = (st_rev[2*si] + (st_rev[2*si+1] * p_pow[mid - ss + 1]) % mod + mod) % mod;
}


int query(int si , int ss , int se , int qs , int qe) {
    if(qe < ss || qs > se)
        return 0;
 
    if(ss >= qs && se <= qe)
        return st[si];
 
    int mid = (ss + se)/2;
    int l = query(2*si , ss , mid , qs , qe);
    int r = query(2*si+1 , mid+1 , se , qs , qe);

    l %= mod, r %= mod;

    return (l + (r * p_pow[mid - ss + 1]) % mod + mod) % mod;
}

int query_rev(int si , int ss , int se , int qs , int qe) {
    if(qe < ss || qs > se)
        return 0;
 
    if(ss >= qs && se <= qe)
        return st_rev[si];
 
    int mid = (ss + se)/2;
    int l = query_rev(2*si , ss , mid , qs , qe);
    int r = query_rev(2*si+1 , mid+1 , se , qs , qe);

    l %= mod, r %= mod;

    return (l + (r * p_pow[mid - ss + 1]) % mod + mod) % mod;
}

void hash_init() {
    p_pow.resize(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i-1] * p) % mod;
    }
}

int getHash(int i, int j) {
    return query(1, 1, n, i+1, j+1);
}

int getHashRev(int x, int y) {
    int i = n - y - 1, j = n - x - 1;
    return query_rev(1, 1, n, i+1, j+1);
}

void solve() {
    int x, y, q;
    cin >> s;
    n = s.size();
    s_rev = s;
    reverse(s_rev.begin(), s_rev.end());
    s = "#" + s;
    s_rev = "#" + s_rev;

    hash_init();
    build(1, 1, n);
    build_rev(1, 1, n);

    cin >> q;
    while(q--) {
        // 0 based indexing of x, y
        cin >> x >> y;
        if(getHash(x, y) == getHashRev(x, y)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
