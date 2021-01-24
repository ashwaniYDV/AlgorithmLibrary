// https://www.codechef.com/problems/MULTQ3
// https://youtu.be/jQ7sriMyrT4

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
const ll N = 1e5+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

// ar[0] -> num % 3 == 0
// ar[1] -> num % 3 == 1
// ar[2] -> num % 3 == 2
struct node{
    int ar[3];
};

node st[4*N];
int lazy[4*N], array[N];

// right shift by 1 unit (1, 2, 3 => 3, 1, 2)
void shift(int si){
    int temp = st[si].ar[2];
    st[si].ar[2] = st[si].ar[1];
    st[si].ar[1] = st[si].ar[0];
    st[si].ar[0] = temp;
}

void build(int si ,int ss, int se) {
    if(ss == se){
        // since initially all array elements are zero
        st[si].ar[0] = 1;
        st[si].ar[1] = 0;
        st[si].ar[2] = 0;
        return;
    }
    
    int mid = (ss + se) / 2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
    st[si].ar[0] = st[2*si].ar[0] + st[2*si+1].ar[0];
    st[si].ar[1] = st[2*si].ar[1] + st[2*si+1].ar[1];
    st[si].ar[2] = st[2*si].ar[2] + st[2*si+1].ar[2];
}

void update(int si , int ss , int se , int qs , int qe) {
    if(lazy[si] != 0){
        int add = lazy[si];
        lazy[si] = 0;
        if(ss != se){
            lazy[2*si] += add;
            lazy[2*si+1] += add;
        }
        add %= 3;
        for(int i = 0; i < add; i++){
            shift(si);
        }
    }
    if(ss > qe || se < qs) return;
    
    if(ss >= qs && se <= qe) {
        // updated only by 1
        int add = 1;
        shift(si);
        if(ss != se){
            lazy[2*si] += add;
            lazy[2*si+1] += add;
        }
        return;
    }
    
    int mid = (ss + se) / 2;
    update(2*si , ss , mid , qs , qe);
    update(2*si+1 , mid+1 , se , qs , qe);
    
    st[si].ar[0] = st[2*si].ar[0] + st[2*si+1].ar[0];
    st[si].ar[1] = st[2*si].ar[1] + st[2*si+1].ar[1];
    st[si].ar[2] = st[2*si].ar[2] + st[2*si+1].ar[2];
}

int query(int si , int ss , int se , int qs , int qe) {
    if(lazy[si] != 0){
        int add = lazy[si];
        lazy[si] = 0;
        if(ss != se){
            lazy[2*si] += add;
            lazy[2*si+1] += add;
        }
        add %= 3;
        for(int i=0;i<add;i++){
            shift(si);
        }
    }
    
    if(ss > qe || se < qs) {
        return 0;
    }
    
    if(ss >= qs && se <= qe){
        // 0 remainer when div by 3
        return st[si].ar[0];
    }
    
    int mid = (ss + se) / 2;
    int l = query(2*si , ss , mid , qs , qe);
    int r = query(2*si+1 , mid+1 , se , qs , qe);
    
    return l + r;
}

void solve() {
    int q , l , r , code;
    cin >> n >> q;
    build(1 , 1 , n);
    
    while(q--){
        cin >> code >> l >> r;
        if(code == 0){
            update(1 , 1 , n , l+1 , r+1);
        }else{
            cout<<query(1 , 1 , n , l+1 , r+1)<<endl;
        }
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
