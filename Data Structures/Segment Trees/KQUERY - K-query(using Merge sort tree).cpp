
// Merge Sort Tree (Segment tree)
// https://www.spoj.com/problems/KQUERY
// https://youtu.be/R0KRKi_LL6c

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

ll arr[N];
vector<ll> st[4 * N];


void merge(vector<ll>& a, vector<ll>& b, vector<ll>& c) {
    int i = 0 , j = 0, n = a.size(), m = b.size();
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            c.push_back(a[i]) , i++;
        } else {
            c.push_back(b[j]) , j++;
        }
    }
 
    while(i < n) c.push_back(a[i]) , i++;
    while(j < m) c.push_back(b[j]) , j++;
}

void build(ll si , ll ss , ll se) {
    if(ss == se) {
        st[si].pb(arr[ss]);
        return;
    }
 
    ll mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    merge(st[2*si], st[2*si+1], st[si]);
}

ll query(ll si , ll ss , ll se , ll qs , ll qe, ll k) {
    if(qe < ss || qs > se) return 0;
 
    if(ss >= qs && se <= qe) {
        return st[si].end() - upper_bound(st[si].begin(), st[si].end(), k);
    };
 
    ll mid = (ss + se)/2;
    ll l = query(2*si , ss , mid , qs , qe, k);
    ll r = query(2*si+1 , mid+1 , se , qs , qe, k);
    
    return l + r;
}


void solve(){
    ll t, l, r, k;
    cin >> n;
    loop(i, 1, n) cin >> arr[i];
    build(1, 1, n);
    cin >> t;
    while(t--) {
        cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << endl;
    }
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
