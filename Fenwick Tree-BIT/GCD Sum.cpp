// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
typedef long long int ll;
#define int long long int
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
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e6+5;
const ll MAXN = 5e5 + 5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

ll phi[MAXN + 1], pillai[MAXN + 1];
ll a[N], BIT[N];

ll inline mod(ll x) {
    return (x % MOD + MOD) % MOD;
}

// Euler Phi Function in O(Nlog(logN)) [preprocessing time]
void init_phi() {
    for(ll i = 1; i <= MAXN; i++) {
        phi[i] = i;
    }

    for(ll i = 2; i <= MAXN; i++) {
        if(phi[i] == i) {
            for(ll j = i; j <= MAXN; j += i) {
            phi[j] *= (i - 1);
            phi[j] /= i;
           } 
        }
    }
}

void init_pillai() {
    for(ll i = 1; i <= MAXN; i++)
        for(ll j = i; j <= MAXN; j += i) {
            pillai[j] += i * phi[j / i];
            pillai[j] = mod(pillai[j]);
        }
}

void update(ll i, ll val) {
    for(; i <= n; i += i&-i) {
        BIT[i] += val;
    }
}

ll query(ll i) {
    ll sum = 0;
    for(; i > 0; i -= i&-i) {
        sum += BIT[i];
    }
    return sum;
}


void solve() {
    ll t, x, y;
    init_phi();
    init_pillai();
    cin >> n;
    loop(i, 1, n) {
        cin >> a[i];
        update(i, pillai[a[i]]);
    }
    cin >> t;
    while(t--){
        char c;
        cin >> c >> x >> y;
        if (c == 'U') {
            // increment is added as update
            update(x, pillai[y] - pillai[a[x]]);
            a[x] = y;
        } else if (c == 'C') {
            cout << mod(query(y) - query(x - 1)) << '\n';
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
