// https://youtu.be/7CTpoVNIc8o

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
const ll N = 1e5+5;	
// ll a[N], b[N], dp[N], level[N], vis[N];

ll in[N], out[N];
vl g[N];
ll n, m;
vector<ll> res;

void kahn_in_sorted_order1(ll n) {
	priority_queue<ll, vector<ll>, greater<ll>> q;
	for(ll i=1; i<=n; i++){
		if(in[i] == 0) q.push(i);
	}

	while(!q.empty()){
		ll u = q.top();
		q.pop();
		res.pb(u);
		for(ll v: g[u]){
			in[v]--;
			if(in[v] == 0) q.push(v);
		}
	}

	if(res.size() < n) {
		cout << "Sandro fails.\n";
		return;
	}
	for(ll x: res) {
		cout << x << " ";
	}
}

void kahn_in_sorted_order2(ll n) {
	set<ll> q;
	for(ll i=1; i<=n; i++){
		if(in[i] == 0) q.insert(i);
	}

	while(!q.empty()){
		ll u = *(q.begin());
		q.erase(q.begin());
		res.pb(u);
		for(ll v: g[u]){
			in[v]--;
			if(in[v] == 0) q.insert(v);
		}
	}

	cout << "Topological sort: \n";
	for(ll x: res) {
		cout << x << " ";
	}
}

void kahn(ll n) {
	queue<ll> q;
	for(ll i=1; i<=n; i++){
		if(in[i] == 0) q.push(i);
	}

	while(!q.empty()){
		ll u = q.front();
		q.pop();
		res.pb(u);
		for(ll v: g[u]){
			in[v]--;
			if(in[v] == 0) q.push(v);
		}
	}

	cout << "Topological sort: \n";
	for(ll x: res) {
		cout << x << " ";
	}
}

void solve() {
	ll x, y, z, p, q, r, u, v;
	cin >> n >> m;
	f(i, m) {
		cin >> u >> v;
		g[u].pb(v);
		in[v]++;
	}
	kahn(n);
}

int32_t main() {
	IOS
	ll T;
	// cin >> T;
	// while(T--)
		solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}
