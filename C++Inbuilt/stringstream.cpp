// https://codeforces.com/contest/52/problem/C

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
const ll N = 2e5+2;
// ll a[N], b[N], dp[N], level[N], vis[N], in[N], out[N];
// vl g[N];
ll n, m;

ll arr[N], tree[4 * N], lazy[4 * N];
 
void build(ll node, ll start, ll end) {
    if(start == end){
    	tree[node] = arr[start];
    	return;
    }
    ll mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
 
void update(ll node, ll start, ll end, ll l, ll r, ll val){
    if(lazy[node] != 0){
	tree[node] += lazy[node];
	if(start != end){
		lazy[2*node] += lazy[node];
		lazy[2*node+1] += lazy[node];
	}
	lazy[node] = 0;
    }
    if(l>end || r<start || l>r) return;
    if(l<=start && end<=r){
    	tree[node]+=val;
	if(start != end){
		lazy[2*node] += val;
		lazy[2*node+1] += val;
	}
	lazy[node]=0;
	return;
    }
    ll mid=(start+end)/2;
    update(2*node,start,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
 
ll query(ll node, ll start, ll end, ll l, ll r){
    if(lazy[node] != 0){
	tree[node] += lazy[node];
	if(start != end){
		lazy[2*node] += lazy[node];
		lazy[2*node+1] += lazy[node];
	}
	lazy[node] = 0;
    }
    if(l>end || r<start || l>r)return INT_MAX;
    if(l<=start && end<=r) return tree[node];
    ll mid=(start+end)/2;
    return min(query(2*node,start,mid,l,r), query(2*node+1,mid+1,end,l,r));
}


void solve() {
	ll q, t, x, y, l, r, v;
	cin >> n;
	loop(i, 1, n) cin >> arr[i];
	build(1, 1, n);
	cin >> q;
	string s;
    cin.ignore();
    ll a[3];
	while(q--){
		getline(cin, s, '\n');
        stringstream in (s);
		in >> a[0] >> a[1];
		if(in >> a[2]){
	        if(a[0] > a[1]){
	        	update(1, 1, n, a[0]+1,n,a[2]);
	           	update(1, 1, n, 1,a[1]+1,a[2]);
	        }else{
	        	update(1, 1, n, a[0]+1,a[1]+1,a[2]);
	        }
        }else{
        	if(a[0] > a[1]){
        		cout<<min(query(1, 1, n, a[0]+1,n), query(1, 1, n, 1,a[1]+1))<<endl;
        	}else{
        		cout<<query(1, 1, n, a[0]+1,a[1]+1)<<endl;
        	}
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
