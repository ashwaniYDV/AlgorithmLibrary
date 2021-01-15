// https://codeforces.com/blog/entry/84413
// O(2 ^ N * (N ^ 2))
// Credit: https://codeforces.com/profile/Not-Afraid

/*
You are given an array of size n (n is always even).
You have to perform n/2 moves and in each move, you can remove any two elements from the array 
and each move will contribute gcd(removed_val_1, removed_val_2) * move_number. 
So we have to maximize the score.

Constraints:-
n <= 20
arr[i] <= 10^5
*/

#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
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
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 20;
int n, m;


int dp[1 << 20];
vector<int> a;

int go(int mask) {
    int used = __builtin_popcount(mask);
    
    // all array elements are used
    if (used == n) {
        return 0;
    }

    if (dp[mask] != -1) { 
        return dp[mask];
    }

    int cur_move = (used / 2) + 1;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!((mask >> i) & 1) && !((mask >> j) & 1)) {
                int points = __gcd(a[i], a[j]) * cur_move;
                int rem = go(mask | (1 << i) | (1 << j));
                ans = max(ans, rem + points);
            }
        }
    }

    return dp[mask] = ans;
}


void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    a.resize(n);
    assert(n % 2 == 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    cout << go(0);
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
