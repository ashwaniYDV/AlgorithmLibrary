// https://www.spoj.com/problems/GOT/
// https://youtu.be/Psfxu9E6jtw

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


const int BLK = 700;
const int height = 21;
vector<int> g[N];
 
int nodeF[N], eleF[N], level[N];
int LCA[N][height+5], val[N], res[2*N];
 
int S[N], T[N], FT[2*N];
int timer;
 
struct query {
    int l, r, idx, c, lca;
    bool operator<(const query &o) const {
        if((l / BLK) != (o.l / BLK))
            return l < o.l;
        return ((l / BLK) & 1) ? r < o.r : r > o.r;
    }
};
query Q[2*N];
 
void dfs(int u, int par, int lvl) {
	level[u] = lvl;
	LCA[u][0] = par;

	S[u] = timer;
	FT[timer] = u;
	timer++;
	
	for(int v : g[u]) {
		if(v != par)
			dfs(v, u, lvl+1);
	}
	
	T[u] = timer;
	FT[timer] = u;
	timer++;
}
 

// generating sparse table
void init() {
    // initializing parent and level of each node
    dfs(1, 0, -1);

    for(int i = 1; i <= height; i++) {
        for(int node = 1; node <= n; node++) {
            if(LCA[node][i-1] != -1) {
                // for 2^i node, first getting 2^(i - 1)th node
                int parNode = LCA[node][i - 1];
                // 2^(i)th node = 2^(i - 1)th + 2^(i - 1)th node
                LCA[node][i] = LCA[parNode][i - 1];
            } 
            else {
                LCA[node][i] = -1;
            }
        }
    }
} 

// binary lifting
int getLCA(int a, int b) {
    if(level[b] < level[a]) swap(a, b);

    int d = level[b] - level[a];

    for(int i = height; i >= 0; i--) {
     if(d & (1<<i)) b = LCA[b][i];
    }

    if(a == b) return a;

    for(int i = height; i >= 0; i--){
        if(LCA[a][i] != LCA[b][i]){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    // parent of a or b
    return LCA[a][0];
}
 
void add(int idx) {
	int node = FT[idx];
	nodeF[node]++;
	int c = val[node];
 
	if(nodeF[node] == 1) {
		eleF[c]++;
	} else {
		eleF[c]--;
	}
}
 
void remove(int idx) {
	int node = FT[idx];
	nodeF[node]--;
	int c = val[node];
 
	if(nodeF[node] == 1) {
		eleF[c]++;
	} else {
		eleF[c]--;
	}
}
 
void solve() {
	int u, v, a, b, c, q;
	cin >> q;
 
	//initialize
	for(int i = 0; i <= n; i++) {
		g[i].clear(), eleF[i] = 0, nodeF[i] = 0;
	}

	for(int i = 1; i <= q; i++) 
		res[i] = 0;

	for(int i = 1; i <= n; i++) 
		cin >> val[i];

	for(int i = 1; i <= n-1 ;i++) 
		cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

	timer = 1;
	memset(LCA, -1, sizeof LCA);
	init();

	for(int i=1; i <= q; i++) {
		cin >> a >> b >> c;
		
		if(S[a] > S[b]) swap(a , b);

		int lca = getLCA(a , b);

		//first type of query
		if(a == lca) {
			Q[i].l = S[a], Q[i].r = S[b], Q[i].lca = -1;
		}
		//second type of query
		else {
			Q[i].l = T[a], Q[i].r = S[b], Q[i].lca = lca;
		}

		Q[i].idx = i , Q[i].c = c;
	}

	// sort(Q, Q + q);
	sort(Q + 1, Q + q + 1);

	// int ML = 0 , MR = -1;
	int ML = 1 , MR = 0;
	for(int i = 1; i <= q; i++) {
		int L = Q[i].l;
		int R = Q[i].r;
		int c = Q[i].c;
		int lca = Q[i].lca;
		int idx = Q[i].idx;

		while(MR < R)
		MR++ , add(MR);

		while(ML > L)
		ML-- , add(ML);

		while(MR > R)
		remove(MR) , MR--;

		while(ML < L)
		remove(ML) , ML++;

		if(eleF[c] > 0) {
			res[idx] = 1;
		}
		if((lca != -1) && (val[lca] == c)) {
			res[idx] = 1;
		}
	}

	for(int i=1; i<=q; i++)
		if(res[i] == 1)
			cout<<"Find"<<endl;
		else
			cout<<"NotFind"<<endl;
}

signed main() {
	IOS
	int t = 0;
	// cin >> t;
	while(cin >> n) {
		if(t > 0) cout << endl;
		solve();
		t++;
	}
} 
