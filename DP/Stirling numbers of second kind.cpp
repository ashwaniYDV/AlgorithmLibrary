// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/
// https://youtu.be/0Q_U9_gryRg

/*
1) Stirling number of second kind S(n,k) counts number of ways in which 
n distinguishible objects can be partitioned into k indistinguishible subsets 
when each subset has to contain atleast one object. [i.e Balls are distinct, boxes are identical]

S(n, k) = S(n - 1, k - 1) + k * S(n - 1, k)

Base Cases:
S(n, 0) = 0 (n different balls in 0 box in 0 way)
S(n, 1) = 1 (n balls in 1 box has only one i.e. all in one)
S(n, n) = 1 (n balls in n identical boxes in 1 way(no empty boxes))

2) How many ways are there to put n distinct objects into k distinct boxes such that every box contains at least one object?
Ans) S(n, k)*k!
So the k! factor is multiplied since now we have the k distinct boxes and not identical.

3) Interview question: Find number of ways to partition n unique elements into k number of sets. 
OR
Count number of ways to partition a set(it is a set hence all elements are unique) into k subsets.
Ans) S(n, k)

Quora links
https://qr.ae/pNsgKw
https://qr.ae/pNsgKO
https://www.quora.com/How-many-ways-are-there-to-put-n-distinct-objects-into-k-distinct-boxes-such-that-every-box-contains-at-least-one-object
*/


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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e5+1;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

// Returns count of different partitions of n elements in k subsets 
int StirlingIterative(int n, int k) { 
    // Base cases 
    if (n == 0 || k == 0 || k > n) return 0; 
    if (k == 1 || k == n) return 1; 

    // S(n, k) = k*S(n - 1, k) + S(n - 1, k - 1) 
    return k*countP(n-1, k) + countP(n-1, k-1); 
} 

int StirlingDP(int n, int k) { 
    int dp[n+1][k+1]; 

    // Base cases 
    for (int i = 0; i <= n; i++) dp[i][0] = 0; 
    for (int i = 0; i <= k; i++) dp[0][k] = 0; 

    // Fill rest of the entries in dp[][] in bottom up manner 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || i == j) 
                dp[i][j] = 1; 
            else
                dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1]; 
        }
    }

    return dp[n][k]; 
} 

void solve() {
    ll t, k, x, y, u, v;
    cout << StirlingIterative(5, 2) << endl;
    cout << StirlingDP(5, 2) << endl;
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
