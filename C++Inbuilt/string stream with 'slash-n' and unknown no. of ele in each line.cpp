// https://www.codechef.com/problems/TSHIRTS

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
const int N = 20;
int n, m;

set<int> a[N];
int dp[1 << 11][105];

int go(int mask, int tshirt) {
    int totalPeopleUsed = __builtin_popcount(mask);
    if(totalPeopleUsed == n) return 1;

    if(tshirt > 100) return 0;

    if(dp[mask][tshirt] != -1) return dp[mask][tshirt];

    int res = 0;

    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i)) && a[i].count(tshirt) == 1) {
            res += go(mask | (1 << i), tshirt + 1);
            res %= MOD;
        }
    }
    
    res += go(mask, tshirt + 1);
    res %= MOD;

    return dp[mask][tshirt] = res % MOD;
}

void solve() {
    int x;
    cin >> n;

    f(i, n) a[i].clear();
    memset(dp, -1, sizeof dp);

    string s;
    cin.ignore();

    f(i, n) {
        getline(cin, s, '\n');
        stringstream in (s);
        while(in >> x) a[i].insert(x);
    }

    cout << go(0, 1) << endl;

}
 
int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
