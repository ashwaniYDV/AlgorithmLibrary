// https://youtu.be/TyWtx7q2D7Y

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
// The low - link value of a node is the smallest (in-time/low-link of a node) reachable from that node including self
int in[N], low[N], presentInStack[N];
stack<int> mystack;
int timer = 0, noOfSCC = 0;

void dfs(int u) {
    in[u] = low[u] = ++timer;
    mystack.push(u);
    presentInStack[u] = 1;

    for(int v: g[u]) {
        //If v is not visited
        if(in[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(presentInStack[v]) {
            low[u] = min(low[u], in[v]);
        }
    }

    //If u is head node of SCC
    if(low[u] == in[u]) {
        noOfSCC++;
        cout<<"SCC is: ";
        while(mystack.top() != u) {
            int node = mystack.top();
            mystack.pop();
            cout << node << " ";
            presentInStack[node] = 0;
        }
        int node = mystack.top();
        mystack.pop();
        cout << node << endl;
        presentInStack[node] = 0;
    }
}

void solve() {
    int u, v;
    cin >> n >> m;

    f(i, m) cin >> u >> v, g[u].pb(v);

    loop(i, 1, n) in[i] = -1, low[i] = -1, presentInStack[i] = 0;

    loop(i, 1, n) {
        if(in[i] == -1) {
            dfs(i);
        }
    }

    cout << "Total no. of SCC = " << noOfSCC << endl;
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
