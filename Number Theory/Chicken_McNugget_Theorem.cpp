// https://www.codechef.com/problems/COPR16G
// https://youtu.be/0Snuq77afU4
// https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem

/* Chicken_McNugget_Theorem
--------------------------------
The Chicken McNugget Theorem (or Postage Stamp Problem or Frobenius Coin Problem) 
states that for any two relatively prime positive integers a, b [i.e gcd(a, b) = 1], 
the greatest integer that cannot be written in the form ax + by for nonnegative integers x, y is = (a * b - a - b).

A consequence of the theorem is that there are exactly 
[(a - 1)*(b - 1) / 2] positive integers which cannot be expressed in the form a*x + b*y. 
The proof is based on the fact that in each pair of the form (k, a*b-a-b-k), exactly one element is expressible.
*/


#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
#define int long long int
#define ld long double
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
const int N = 2e5+5;
int n, m;


void solve() {
    int a, b;
    cin >> a >> b;
    int g = __gcd(a, b);
    if(g != 1) {
        cout << -1 << endl;
        return;
    }
    n = a*b - a - b + 1;
    cout << n << endl;
}
 
int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
