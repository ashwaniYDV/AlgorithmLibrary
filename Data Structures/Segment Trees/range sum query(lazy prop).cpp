// https://youtu.be/wQSnKUs93DU

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
const ll N = 1e6+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

ll st[4*N], lazy[4*N], arr[N];

void build(ll si , ll ss , ll se) {
	if(ss == se) {
		st[si] = arr[ss];
		return;
	}
 
	ll mid = (ss + se)/2;
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
 
	st[si] = st[2*si] + st[2*si+1];
}

void update(ll si , ll ss , ll se , ll qs, ll qe, ll val) {
	if(lazy[si] != 0){
		ll dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);

		if(ss != se){
			lazy[2*si] += dx;
			lazy[2*si + 1] += dx;
		}
	}

	if(qe < ss || qs > se) return;

	if(ss >= qs && se <= qe){
		ll dx = (se - ss + 1)*val;
		st[si] += dx;

		if(ss != se){
			lazy[2*si] += val;
			lazy[2*si + 1] += val;
		}
		return;
	}

	ll mid = (ss + se) / 2;
	
	update(2*si, ss, mid, qs, qe, val);
	update(2*si + 1, mid + 1, se, qs, qe, val);

	st[si] = st[2*si] + st[2*si + 1];
}

ll query(ll si , ll ss , ll se , ll qs , ll qe) {
	if(lazy[si] != 0){
		ll dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);

		if(ss != se){
			lazy[2*si] += dx;
			lazy[2*si + 1] += dx;
		}
	}

	if(qe < ss || qs > se) return 0;
 
	if(ss >= qs && se <= qe) return st[si];
 
	ll mid = (ss + se)/2;
	ll l = query(2*si , ss , mid , qs , qe);
	ll r = query(2*si+1 , mid+1 , se , qs , qe);
 	
	return l + r;
}

void solve() {
	ll q, t, l, r, val;
	cin >> n >> q;
	build(1 , 1 , n);

	while(q--) {
		cin >> t >> l >> r;
		if (t == 1){
			cout << query(1 , 1 , n , l , r)<<endl;
		} else {
			cin >> val;
			update(1, 1, n, l, r, val);
		}
	}
}

int32_t main() {
	IOS
	solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}
