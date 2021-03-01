// https://codeforces.com/contest/1245/problem/D

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

/*--------------------DSU--------------------------------------*/
int par[N];
void initialize() {
    for(int i = 0; i < N; i++){
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
/*--------------------DSU End----------------------------------*/


/*--------------------KRUSKAL'S----------------------------------*/
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

int kruskals() {
    sort(input.begin(), input.end(), compare);
    initialize();

    int cost = 0;
    for(Edge currEdge: input) {
        int srcParent = findParent(currEdge.src);
        int destParent = findParent(currEdge.dest);
        if(srcParent != destParent) {
            result.pb(currEdge);
            cost += currEdge.weight;
            unionSet(srcParent, destParent);
        }
    }

    return cost;
}
/*--------------------KRUSKAL'S END------------------------------*/

int x[N], y[N], c[N], k[N];

int distance(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}


void solve() {
    cin >> n;
    loop(i, 1, n) cin >> x[i] >> y[i];

    loop(i, 1, n) cin >> c[i];
    loop(i, 1, n) cin >> k[i];

    loop(i, 1, n) {
        Edge e = {0, i, c[i]};
        input.pb(e);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <=n ; j++) {
            Edge e = {i, j, (k[i] + k[j]) * distance(i, j)};
            input.pb(e);
        }
    }

    int res = kruskals();

    cout << res << endl;

    vector<int> v1;
    vector<pair<int, int>> v2;
    for(Edge i: result) {
        if(i.src == 0) {
            v1.pb(i.dest);
        } else {
            v2.pb({i.src, i.dest});
        }
    }

    cout << v1.size() << endl;
    for(int i: v1) cout << i << " ";
    cout << endl;
    
    cout << v2.size() << endl;
    for(auto i: v2) cout << i.F << " " << i.S << endl;
}   
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
