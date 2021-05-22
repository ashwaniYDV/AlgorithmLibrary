// https://www.spoj.com/problems/PRIME1/
// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#toc-tgt-7

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_map;
// methods: find_by_order(k); & order_of_key(k); To make it an ordered_multiset, use pairs of (value, time_of_insertion) to distinguish values which are similar
 
typedef long long int ll;
#define int long long int
#define ld long double
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define UNIQUE(a) sort(a.begin(), a.end() ); a.erase( unique( a.begin(), a.end() ), a.end() );
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debug2(x,y) cout << (#x) <<", "<<(#y)<< " are: " << (x) <<", "<<(y)<< endl;
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
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
// #define endl "\n"
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e7+5;
int n, m;

// Time = (R-L+1)loglog(R) + √R.loglog(√R)
vector<bool> segmentedSieve(int L, int R) {
    // generate all primes up to sqrt(R)
    int lim = sqrt(R);
    vector<bool> mark(lim + 1, true);
    mark[0] = mark[1] = false;
    vector<int> primes;
    for (int i = 2; i <= lim; ++i) {
        if (mark[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= lim; j += i)
                mark[j] = false;
        }
    }

    vector<bool> isPrime(R - L + 1, true);

    for (int i : primes)
        for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;

    if (L == 1)
        isPrime[0] = false;

    return isPrime;
}

void solve() {
    int x, y, z, l, r;
    cin >> l >> r;
    vector<bool> isPrime = segmentedSieve(l, r);
    f(i, isPrime.size()) {
        if(isPrime[i])
            cout << i + l << endl;
    }
    cout << endl;
}
 
signed main() {
    IOS
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
} 
