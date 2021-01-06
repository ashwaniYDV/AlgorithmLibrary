// https://blog.anudeep2011.com/mos-algorithm/

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
#define debug(x) cout << #x << " is: " << (x) << endl;
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
typedef long double ld;
typedef vector<vector<ll>> matrix;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
const ll N = 2e5+5;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

// sqrt(n)
ll BLOCK = 555;

struct query{
	ll l;
	ll r;
	ll i;
};
query Q[200001];
ll ar[30001] , ans[200001];
ll freq[1000001];
ll cnt = 0;


// struct query {
//     int l, r, i;
//     bool operator<(const query &o) const {
//         if((l / BLOCK) != (o.l / BLOCK))
//             return l < o.l;
//         return l / BLOCK & 1 ? r < o.r : r > o.r;
//     }
// } Q[200001];

bool compare(query a , query b) {
	if(a.l / BLOCK != b.l/BLOCK)
	return a.l/BLOCK < b.l/BLOCK;
 
	return a.r < b.r;
}

void add(ll pos) {
	freq[ar[pos]]++;
	if(freq[ar[pos]] == 1)
	cnt++;
}
 
void remove(ll pos) {
	freq[ar[pos]]--;
	if(freq[ar[pos]] == 0)
	cnt--;
}

 
void solve() {
	ll q;
	cin >> n;
	f(i, n) cin >> ar[i];
	cin >> q;
	f(i, q){
		cin >> Q[i].l >> Q[i].r;
		Q[i].i = i;
		Q[i].l--, Q[i].r--;
	}
	sort(Q, Q + q, compare);

	ll ML = 0 , MR = -1;
	f(i, q){
		ll L = Q[i].l;
		ll R = Q[i].r;
 		
 		// Its always suggested to use in this method : R A A R 

 		// contraction
		while(ML < L){
			remove(ML) , ML++;
		}
 		// expansion
		while(ML > L){
			ML-- , add(ML);
		}
		// expansion
		while(MR < R){
			MR++ , add(MR);
		}
 		// contraction
		while(MR > R){
			remove(MR) , MR--;
		}
 
		ans[Q[i].i] = cnt;
	}
 
	f(i, q) cout << ans[i] << endl;
}	
 
int32_t main() {
	IOS
	clock_t begin = clock();
	ll T = 1;
	// cin >> T;
	while(T--)
	solve();
	cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
	return 0;
}
