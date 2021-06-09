// https://codeforces.com/problemset/problem/471/D
// https://youtu.be/GFFum0JXmjo

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define debug cout << "debug" << endl;
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
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 1e5+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

auto z_algo(vector<ll> s) {
	ll n = s.size();
	ll l = 0, r = 0;
	vector<ll> z(n);
	z[0] = 0;
	for(ll i = 1; i < n; i++) {
		if(i > r) {
			l = r = i;
			while(r < n and s[r] == s[r - l]) {
				r++;
			}
			z[i] = r - l;
			r--;
		}else{
			ll idx = i - l;
			if(i + z[idx] <= r) {
				z[i] = z[idx];
			}else{
				l = i;
				while(r < n and s[r] == s[r - l]) {
					r++;
				}
				z[i] = r - l;
				r--;
			}
		}
	}
	return z;
}

void solve() {
	ll w;
	cin >> n >> w;
	vector<ll> str(n), pat(w);
	f(i, n) cin >> str[i];
	f(i, w) cin >> pat[i];
	vector<ll> s, p;
	for(ll i = 0; i < n-1; i++) {
		s.pb(str[i+1] - str[i]);
	}
	for(ll i = 0; i < w-1; i++) {
		p.pb(pat[i+1] - pat[i]);
	}

	vector<ll> tot;
	for(ll x: p) tot.pb(x);

	// special character 1e10
	tot.pb(10000000000);

	for(ll x: s) tot.pb(x);

	auto z = z_algo(tot);
	ll ans = 0;
	for(auto x: z) {
		if(x == p.size()) ans++;
	}
	cout << ans << endl;
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
