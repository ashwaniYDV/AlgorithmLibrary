// https://youtu.be/Lxpr5OpeNa8
/*
Here P is a prime greater than n.
NOTE:
(a + b) % P = ((a % P) + (b % P)) % P
(a * b) % P = ((a % P) * (b % P)) % P
But
(a / b) % P is not = to ((a % P) / (b % P)) % P
It is calculated using inverse modulo
(a / b) % P = ((a % P) * inverse_modulo(b, P)) % P

Fermat's little theorem:
inverse_modulo(x, P) = modular(x, P- 2);
*/

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
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

ll F[N];

ll factorial(){
    F[0] = F[1] = 1;
    fa(i, 2, N){
        F[i] = ((F[i - 1] % MOD) * (i % MOD)) % MOD;
    }
}

ll modular_exp(ll a, ll n, ll mod) {
    ll res = 1;
    while(n) {
        if(n % 2 == 1) {
            res = ((res % mod) * (a % mod)) % mod;
            n--;
        }
        a = ((a % mod) * (a % mod)) % mod;
        n /= 2;
    }
    return res;
}

// fermat's little theorem
ll inverse_modulo(ll base, ll mod) {
    return modular_exp(base, mod-2, mod);
}

ll nCr(ll n, ll r) {
    if(r > n) return 0;
    // nCr = n!%P / ((r!)%P * (n-r!)%P) = n!%P * (inverse_mod(r!)%P * inverse_mod(n-r!)%P)
    ll res = F[n];
    res = (1LL * res * inverse_modulo(F[r], MOD)) % MOD;
    res = (1LL * res * inverse_modulo(F[n - r], MOD)) % MOD;

    return res;
}

void solve() {
    ll t, r;
    factorial();
    cin >> t;
    while(t--) {
        cin >> n >> r;
        cout << nCr(n, r) << endl;
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
