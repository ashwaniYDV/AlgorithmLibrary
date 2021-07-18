// https://en.wikipedia.org/wiki/Pillai%27s_arithmetical_function

/*
Given multiple queries, compute 
gcd(1,n)+gcd(2,n)+gcd(3,n)+...+gcd(n,n)
for each query n
             n
Pillai(n) =  Σ  gcd(k, n) = gcd(1,n)+gcd(2,n)+gcd(3,n)+...+gcd(n,n)
            k=1
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
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

ll phi[N + 1], pillai[N + 1];

ll inline mod(ll x) {
    return (x % MOD + MOD) % MOD;
}

// Euler Phi Function in O(Nlog(logN)) [preprocessing time]
void init_phi() {
    for(ll i = 1; i <= N; i++) {
        phi[i] = i;
    }

    for(ll i = 2; i <= N; i++) {
        if(phi[i] == i) {
            for(ll j = i; j <= N; j += i) {
            phi[j] *= (i - 1);
            phi[j] /= i;
           } 
        }
    }
}

void init_pillai() {
    for(ll i = 1; i <= N; i++)
        for(ll j = i; j <= N; j += i) {
            pillai[j] += i * phi[j / i];
            // uncomment if answer is large and thus MOD 10^9+7 is used
            // pillai[j] = mod(pillai[j]);
        }
}

void solve() {
    ll t;
    init_phi();
    init_pillai();
    cin >> t;
    while(t--){
        cin >> n;
        cout << pillai[n] << endl;
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

/*
Input:
5
1 2 3 4 5
Output:
1
3
5
8
9
*/
