// https://youtu.be/gGhQRhVbu2E
// https://codeforces.com/problemset/problem/375/D

/*
Subtree query question
*/

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
 
 
// sqrt(n)
int BLK = 555;
 
struct query {
    int l, r, i, k;
    bool operator<(const query &o) const {
        if((l / BLK) != (o.l / BLK))
            return l < o.l;
        return ((l / BLK) & 1) ? r < o.r : r > o.r;
    }
};
 
query Q[N];
vector<int> g[N];
 
// strt time, terminating time, flat tree, color
int S[N], T[N], FT[2*N], col[N];
// node freq, color freq, freq of freq, sqrtDecomp Array
int nodeF[N], colorF[N], FF[N], sqrtDecomp[N];
int ans[N];
int timer = 1;
 
int getBlock(int idx) {
	// using 1 based index otherwise, return idx / BLK;
	return (idx + BLK - 1) / BLK;
}
 
void dfs(int u, int par) {
	S[u] = timer;
	FT[timer] = u;
	timer++;
	
	for(int v : g[u]) {
		if(v != par)
			dfs(v, u);
	}
	
	T[u] = timer;
	FT[timer] = u;
	timer++;
}
 
void add(int idx) {
	int node = FT[idx];
	int c = col[node];
	nodeF[node]++;
	
	if(nodeF[node] == 2) {
		FF[colorF[c]]--;
		sqrtDecomp[getBlock(colorF[c])]--;
 
		colorF[c]++;
 
		FF[colorF[c]]++;
		sqrtDecomp[getBlock(colorF[c])]++;
	}
	
}
 
void remove(int idx) {
	int node = FT[idx];
	int c = col[node];
	nodeF[node]--;
	
	if(nodeF[node] == 1) {
		FF[colorF[c]]--;
		sqrtDecomp[getBlock(colorF[c])]--;
 
		colorF[c]--;
		
		FF[colorF[c]]++;
		sqrtDecomp[getBlock(colorF[c])]++;
	}
	
}
 
int sqrtDecompQuery(int l, int r) {
	int res = 0;
	int LB = getBlock(l), RB = getBlock(r);
	
	if(LB == RB) {
		for(int i=l;i<=r;i++)
		res += FF[i];
	} else {
		for(int i=l;i<=LB*BLK;i++)
		res += FF[i];
		
		for(int i=LB+1;i<RB;i++)
		res += sqrtDecomp[i];
		
		for(int i=RB*BLK+1;i<=r;i++)
		res += FF[i];
	}
	
	return res;
}
 
void solve() {
	int u, v, q, k;
	cin >> n >> q;
 
	for(int i = 1; i <= n; i++) cin >> col[i];
	for(int i = 1; i <= n-1; i++) cin >> u >> v, g[u].pb(v), g[v].pb(u);
 
	dfs(1, -1);
 
	for(int i = 1; i <= q; i++) {
		cin >> u >> k;
		Q[i].l = S[u];
		Q[i].r = T[u];
		Q[i].k = k;
		Q[i].i = i;
	}
	// sort(Q, Q + q);
	sort(Q + 1, Q + q + 1);
 
	// int ML = 0 , MR = -1;
	int ML = 1 , MR = 0;
	for(int i = 1; i <= q; i++) {
		int L = Q[i].l;
		int R = Q[i].r;
 		k = Q[i].k;
 
 		// expansion
		while(ML > L)
		ML-- , add(ML);
 	
 		// expansion
		while(MR < R)
		MR++ , add(MR);
 
 		// contraction
		while(ML < L)
		remove(ML) , ML++;
 
 		// contraction
		while(MR > R)
		remove(MR) , MR--;
 
 
 		ans[Q[i].i] = sqrtDecompQuery(k, n);
	}
 
	for(int i = 1; i <= q; i++) cout << ans[i] << endl;
}
 
signed main() {
	IOS
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
} 
