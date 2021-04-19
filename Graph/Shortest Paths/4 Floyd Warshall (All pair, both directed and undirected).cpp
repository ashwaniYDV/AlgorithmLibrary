// It's a dynamic programming solution

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize "03"
#pragma GCC target("sse4")
 
#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>=n;a<n?i+=1:i-=1)
#define loop(i,a, n) for(ll i = a; i <= n; i++)
#define loopb(i,a, n) for(ll i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setmem(x, k) memset(x, k, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<vector<ll>> matrix;
const ll N = 3e3+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

ll g[N][N], dis[N][N];

void solve() {
	ll k, x, y, u, v, p, q;
	cin >> n >> m;
	loop(i, 1, n){
		loop(j, 1, n){
			if(i == j)
				g[i][j] = 0;
			else
				g[i][j] = INT_MAX;
		}
	}
	f(i, m){
		cin >> u >> v >> x;
		g[u][v] = x;
		g[v][u] = x; // comment it if directed graph
	}
	loop(i, 1, n){
		loop(j, 1, n){
			dis[i][j] = g[i][j];
		}
	}
	loop(k, 1, n){
		loop(i, 1, n){
			loop(j, 1, n){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
			}
		}
	}
	loop(i, 1, n){
		loop(j, 1, n){
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
}
 
int32_t main() {
	IOS
	solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}
