// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/

/*
Given an array of N natural numbers and asks him to solve the following queries:-
Query 0:- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

input:
First line of the input contains the number N. 
Next line contains N natural numbers.
Next line contains an integer Q followed by Q queries.
0 x y - modify the number at index x to y.
1 x y - count the number of even numbers in range l to r inclusive.
2 x y - count the number of odd numbers in range l to r inclusive.
*/

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
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

// {odd, even}
pair<ll, ll> st[4*N];
ll arr[N];

void build(ll si , ll ss , ll se) {
	if(ss == se) {
		if(arr[ss] % 2 == 0) {
			st[si] = {1, 0};
		} else {
			st[si] = {0, 1};
		}
		return;
	}
 
	ll mid = (ss + se)/2;
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
 
	st[si].F = st[2*si].F + st[2*si+1].F;
	st[si].S = st[2*si].S + st[2*si+1].S;
}

void update(ll si , ll ss , ll se , ll qi, ll newVal) {
	if(ss == se) {
		// here ss == se == qi
		if(arr[ss] % 2 == 0){
			// reverse even to odd
			st[si] = {0, 1};
		} else {
			// reverse odd to even
			st[si] = {1, 0};
		}

		arr[qi] = newVal;
		return;
	}

	ll mid = (ss + se) / 2;

	if(qi <= mid) update(2*si, ss, mid, qi, newVal);
	else update(2*si + 1, mid + 1, se, qi, newVal);

	st[si].F = st[2*si].F + st[2*si + 1].F;
	st[si].S = st[2*si].S + st[2*si + 1].S;
}

ll query(ll si , ll ss , ll se , ll qs , ll qe, ll type) {
	if(qe < ss || qs > se)
		return 0;
 
	if(ss >= qs && se <= qe) {
		if(type == 1) return st[si].F;
		if(type == 2) return st[si].S;
	}
 
	ll mid = (ss + se)/2;
	ll l = query(2*si , ss , mid , qs , qe, type);
	ll r = query(2*si+1 , mid+1 , se , qs , qe, type);
 
	return l + r;
}

void solve() {
	ll t, q, x, y;
	cin >> n;
	loop(i, 1, n) cin >> arr[i];
	build(1 , 1 , n);

	cin >> t;
	while(t--) {
		cin >> q >> x >> y;
		if(q == 0) {
			if(arr[x] % 2 == y % 2) continue;
			else update(1, 1, n, x, y);
		} else {
			cout << query(1, 1, n, x, y, q) << endl;
		}
	}
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
