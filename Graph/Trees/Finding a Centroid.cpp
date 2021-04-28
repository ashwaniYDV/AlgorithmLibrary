// https://cses.fi/problemset/task/2079/
// https://youtu.be/0DJwKePjweQ

/*
Centroid of a Tree is a node which if removed from the tree would split it into a 'forest', 
such that any tree in the forest would have at most half the number of vertices in the original tree. 

NOTE: 
1) A tree may have one centroid or may have two centroids (at most 2 centroids). 
If it has two centroids, they are always connected (otherwise, the tree can't have n vertices).

2) In a tree only two Centroid possible (from Jordan Theorem). 
If there are two centroids you can take any cause those two centroids will look like the same.
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
const int MAXN = 1e4+5;
const int N = 2e5+5;
int n, m;

vector < int > g[N];
int subtreeSize[N];

void getSubtreeSize(int u, int par) {
    subtreeSize[u] = 1;
    for (int v: g[u]) {
        if (v == par) continue;
        getSubtreeSize(v, u);
        subtreeSize[u] += subtreeSize[v];
    }
}

int centroid(int u, int par) {
    for (int v: g[u]) {
        if (v != par && subtreeSize[v] > (n / 2)) return centroid(v, u);
    }
    return u;
}

void solve() {
    int u, v;
    cin >> n;
    f(i, n - 1) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    getSubtreeSize(1, -1);
    cout << centroid(1, -1) << endl;
}

signed main() {
    IOS
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
