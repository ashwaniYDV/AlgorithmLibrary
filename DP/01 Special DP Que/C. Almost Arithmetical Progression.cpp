// https://codeforces.com/contest/255/problem/C

/*
The problem asks to compute the length of the longest subsequence in the form of a, b, a, b, ....
 
You can map A[1..n] values to 0..n-1
Once, the values are mapped, fill an array dp[i][j] which contains the max subsequence length 
ending with a[i] and previous element being a[j].
 
We have to find the longest subsequence of A,B,A,B,A,B,... Type. 
Since in an array of size n, we cant have more than n different numbers, 
we map the numbers accordingly. 
For example, a = [ 10 , 20 , 30 , 20 , 30 ] --> a = [ 0 , 1 , 2 , 1 , 2 ] 
We updated the initial array!
 
Now we create dp[n][n], where dp[ i ][ j ] means length of longest subsequence 
ending at i th element (a[ i ]) and j th element (a[j]) being the previous element in subsequence! 
Here's the tricky part: For every (i,j) , we dont update dp[ i ][ j ], 
Instead we update dp[ i ][ a[ j ] ]. 
(Yes, some dp[ i ][ j ] may never be updated , if array elements repeat , 
but we just have to find the maximum length. It'll make sense soon! )
*/
 
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
#define endl "\n"
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;
 
 
void solve() {
    int x, y, z;
 
    cin >> n;
    int a[n];
 
    f(i, n) 
        cin >> a[i];
 
    // map all elements from 0 to n-1 range
    map<int, int> mp;
    int idx = 0;
    f(i, n) {
        if(mp.count(a[i]) == 0)
            mp[a[i]] = idx++;
    }
    f(i, n) {
        a[i] = mp[a[i]];
    }
 
    int dp[n][n];
    int ans = 0;
 
    f(i, n) {
        f(j, n) {
            dp[i][j] = 1;
        }
    }
 
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) { 
            dp[i][a[j]] = max(1 + dp[j][a[i]], dp[i][a[j]]);
        }
    }
 
    f(i, n) {
        f(j, n) {
            ans = max(ans, dp[i][j]);
        }
    }
 
    cout << ans << endl;
}
 
signed main() {
    IOS
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
} 
