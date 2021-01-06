// https://www.codechef.com/problems/GCDMOD
// https://youtu.be/rXnS4nf0T0M

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

ll modexp(ll a, ll n , ll d) {
    ll res = 1;
    while(n){
        if(n % 2 == 1){
            res = ((res % d) * (a % d)) % d;
            n--;
        }else{
            a = ((a % d) * (a % d)) % d;
            n /= 2;
        }
    }
    return res;
}

void getDivisors(ll x, vl& divisors){
    for(ll i = 1; i * i <= x; i++){
        if(x % i == 0){
            divisors.pb(i);
            if(x/i != i) {
                divisors.pb(x/i);
            }
        }
    }
}

void solve() {
    ll a, b, x;
    cin >> a >> b >> n;
    if(a == b) {
        cout << (modexp(a, n, MOD) + modexp(b, n, MOD)) % MOD << endl;
        return;
    }
    ll num = a - b, gcdAns = 1;
    // store potentials gcd in divisors
    vl divisors;
    getDivisors(num, divisors);
    for(ll d: divisors){
        x = (modexp(a, n, d) + modexp(b, n, d)) % d;
        if(x == 0)
            gcdAns = max(gcdAns, d);

    }
    cout << gcdAns % MOD << endl;
} 
 
int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}
