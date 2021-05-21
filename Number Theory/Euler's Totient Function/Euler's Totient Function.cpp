
/*
Que: Find number of co-primes of n from 1...n
(Coprime of n is x if gcd(n, x) = 1)
Euler's Totient Function (Phi Function) in O(sqrt(N))
Φ(n) = n * [1 - (1/p1)] * [1 - (1/p2)] * [1 - (1/p3)] * ...
Φ(n) = n * [(p1 - 1)/p1] * [(p2 - 1)/p2] * [(p3 - 1)/p3] * ...
where n = p1^x1 * p2^x2 * p3^x3 * ...
NOTE:
O(sqrt(N)) -> Problems involving single query
O(Nlog(logN)) -> Problems involving multiple query where each queriy can be answered in O(1) after precalculation
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


// Euler Phi Function in O(sqrt(N))
ll phi(ll n) {
    ll res = n;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            res *= (i - 1);
            res /= i;

            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        res *= (n - 1);
        res /= n;
    }
    return res;
}

void solve() {
    ll t, r;
    cin >> n;
    cout << phi(n);
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
