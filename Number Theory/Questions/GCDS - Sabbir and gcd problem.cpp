// https://www.spoj.com/problems/GCDS/

#include<bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define kickstart(testcase, res) cout << "Case #" << testcase << ": " << res << endl;
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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e7+5;
int n, m;
 
/*------------------------------------------------------*/
bool prime[N+5]; 
vector<int> primesVec;
void SieveOfEratosthenes(ll n) {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(ll p=2; p*p<=n; p++){ 
        if (prime[p] == true){
            for(ll i=p*p;i<=n;i+=p) 
            prime[i] = false; 
        } 
    } 
    for(ll p=2; p<=n; p++){
        if (prime[p]) {
            primesVec.push_back(p);
        }
    }
}
 
ll spf[N];
void SPF() { 
    spf[1] = 1; 
    // marking smallest prime factor for every number to be itself.
    for (ll i = 2; i < N; i++) spf[i] = i; 
  
    // separately marking spf for every even number as 2 
    for (ll i=4; i<N; i+=2) spf[i] = 2;
  
    for (ll i=3; i*i<N; i++) { 
        // checking if i is prime 
        if (spf[i] == i) { 
            // marking SPF for all numbers divisible by i 
            for (ll j=i*i; j<N; j+=i) 
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) spf[j] = i; 
        } 
    } 
}
 
/*------------------------------------------------------*/
 
int check[N];
 
void getFactorization(int x) { 
    while (x != 1) { 
        check[spf[x]] = 1;
        x = x / spf[x]; 
    }
} 
 
void solve() {
    ll x, y, z, k, sum = 0, d;
    memset(check, 0, sizeof check);
 
    cin >> n;
    f(i, n) {
        cin >> x;
        getFactorization(x);
    }
 
    for(int p: primesVec) {
        if(check[p] == 0) {
            cout << p << endl;
            return;
        }
    }
}
 
 
int32_t main() {
    IOS
    int T = 1;
    SieveOfEratosthenes(N);
    SPF();
    cin >> T;
    while(T--)
    solve();
    return 0;
} 
