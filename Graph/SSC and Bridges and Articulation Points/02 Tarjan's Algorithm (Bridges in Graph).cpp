// https://youtu.be/Rhxs4k6DyMM

/*
The idea is similar to O(V+E) algorithm for Articulation Points. 
We do DFS traversal of the given graph. 
In DFS tree an edge (u, v) is bridge if there does not exist any other alternative to reach u or an ancestor of u from subtree rooted with v. 

The value low[v] indicates earliest visited vertex in-time reachable from subtree rooted with v. 
The condition for an edge (u, v) to be a bridge is, “low[v] > in-time[u]”.
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
#define MOD2 1000000007
#define MOD 998244353
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;


vector<int> g[N];
vector<pair<int, int>> bridge;
int in[N], low[N];
int timer;

void dfs(int u, int par) {
    in[u] = low[u] = ++timer;

    for(int v: g[u]) {
        if(v == par) continue;
        //If v is not visited (forward edge)
        if(in[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > in[u]) bridge.pb({u, v});
        }
        // back edge (for back edge v is ancestor; back edge introduces a cycle)
        else {
            low[u] = min(low[u], in[v]);
        }
    }
}

void solve() {
    int u, v;
    cin >> n >> m;

    // undirected graph
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    loop(i, 1, n) in[i] = -1, low[i] = -1;
    timer = 0;
    
    loop(i, 1, n) {
        if(in[i] == -1) {
            dfs(i, -1);
        }
    }

    cout<<"Bridges are: \n";
    for(auto i: bridge) {
        cout << i.F << " " << i.S << endl;
    }
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

/*
Input:
7 8
1 2
2 3
2 4
4 5
5 1
5 6
5 7
6 7
Output:
Bridges are: 
2 3
*/
