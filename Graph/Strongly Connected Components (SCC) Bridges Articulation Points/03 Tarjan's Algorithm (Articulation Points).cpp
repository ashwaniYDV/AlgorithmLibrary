// https://youtu.be/64KK9K4RpKE

/*
A O(V+E) algorithm to find all Articulation Points (APs)
In DFS, we follow vertices in tree form called DFS tree.

In DFS tree, a vertex u is parent of another vertex v, if v is discovered by u (obviously v is an adjacent of u in graph). 

In DFS tree, a vertex u is articulation point if one of the following two conditions is true:-
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.
Children = no pf sub-graphs of that node when we do DFS call
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
int in[N], low[N], isArticulation[N];
int timer;

void dfs(int u, int par) {
    in[u] = low[u] = ++timer;
    int children = 0;

    for(int v: g[u]) {
        if(v == par) continue;
        //If v is not visited
        if(in[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            //Case-2: Atleast 1 component will get separated
            if(low[v] >= in[u] && par != -1) isArticulation[u] = 1;

            children++;
        } else {
            low[u] = min(low[u], in[v]);
        }
    }

    //Case-1: u is root
    if(par == -1 && children >= 2) isArticulation[u] = 1;
}

void solve() {
    int u, v;
    cin >> n >> m;

    // undirected graph
    f(i, m) cin >> u >> v, g[u].pb(v), g[v].pb(u);

    loop(i, 1, n) in[i] = -1, low[i] = -1, isArticulation[i] = 0;
    timer = 0;

    loop(i, 1, n) {
        if(in[i] == -1) {
            dfs(i, -1);
        }
    }

    cout<<"Articulation Points are: \n";
    loop(i, 1, n) {
        if(isArticulation[i]) cout << i <<" ";
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
7 9
1 2
2 3
2 4
4 5
5 1
5 6
5 7
6 7
7 6
Output:
Articulation Points are: 
2 5 
*/
