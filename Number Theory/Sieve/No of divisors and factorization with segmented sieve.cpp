// https://www.codechef.com/problems/PRETNUM
// Yet Another Cute Girl

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
const int N = 1e6+5;
int n, m;

bool isPrime[N+5]; // N = 1e5 order 
vector<int> primes;
void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int p = 2; p*p <= N; p++) { 
        if (isPrime[p] == true) {
            for(int i = p*p; i <= N; i+=p) 
                isPrime[i] = false; 
        } 
    } 
    for(int p=2; p <= N; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
}


void segmentedSieve(int L, int R) {
    int n = R - L + 1;
    int nums[n], divisors[n];
    for(int i = 0; i < n; i++) {
        nums[i] = i + L;
        divisors[i] = 1;
    }

    for (int p : primes) {
        if( p*p <= R) {
            for (int j = max(p * p, (L + p - 1) / p * p); j <= R; j += p) {
                int cnt = 0;
                while(nums[j - L] % p == 0) {
                    nums[j - L] /= p;
                    cnt++;
                }
                divisors[j - L] *= (cnt + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int d = divisors[i] * (nums[i] > 1 ? 2 : 1);
        if(isPrime[d]) 
            ans++;
    }
    cout << ans << endl;
}

void solve() {
    int l, r;
    cin >> l >> r;
    segmentedSieve(l, r);
}

signed main() {
    IOS
    sieve();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
} 
