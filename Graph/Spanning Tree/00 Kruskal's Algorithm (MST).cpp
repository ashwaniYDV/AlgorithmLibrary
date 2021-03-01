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
const int N = 2e3+5;
int n, m;

/*--------------------DSU BEGIN----------------------------------*/
int par[N];
void initialize() {
    for(int i = 0; i < N; i++) {
        par[i] = -1;
    }
}
int findParent(int a) {
    if(par[a] < 0)
        return a;
    return par[a] = findParent(par[a]);
}
void unionSet(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a == b) return;
    if(par[a] > par[b]) swap(a,b);
    par[a] += par[b];
    par[b] = a;
}
/*--------------------DSU END------------------------------------*/


/*--------------------KRUSKAL'S BEGIN-----------------------------*/
struct Edge {
    int src;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

vector<Edge> input;
vector<Edge> result;

void kruskals() {
    sort(input.begin(), input.end(), compare);
    initialize();

    int cost = 0;
    for(Edge currEdge: input) {
        int srcParent = findParent(currEdge.src);
        int destParent = findParent(currEdge.dest);
        if(srcParent != destParent) {
            result.pb(currEdge);
            unionSet(srcParent, destParent);
        }
    }
}
/*--------------------KRUSKAL'S END------------------------------*/


void solve() {
    int u, v, x, y;
    cin >> n >> m;
    f(i, m) {
        cin >> u >> v >> x;
        Edge edg = {u, v, x};
        input.pb(edg);
    }
    kruskals();
    int cost = 0;
    for(Edge e: result){
        cout << e.src << " " << e.dest << " " << e.weight << endl;
        cost += e.weight;
    }
    cout << "Min cost: " << cost;
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
