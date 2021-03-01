#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>n;a<n?i+=1:i-=1)
#define pb push_back
#define F first
#define S second
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
 
const ll mod = 1000000007;
const ll N = 3e5, M = N;
vl g[N];
ll a[N], dp[N], in[N], out[N];

ll n;

void dfs(ll u, ll par) {
    in[u] = 0;
    for (ll v : g[u]) {
        if (v == par) continue;
        dfs(v, u);
        in[u] = max(in[u], 1 + in[v]);
    }
}

void dfs2(ll u, ll par) {
    ll mx1(-1), mx2(-1);
    for (ll v : g[u]) {
        if (v == par) continue;
        if (in[v] >= mx1) mx2 = mx1, mx1 = in[v];
        else if (in[v] > mx2) mx2 = in[v];
    }

    for (ll v : g[u]) {
        if (v == par) continue;
        ll use = mx1;
        if (use == in[v]) use = mx2;
        out[v] = max(1 + out[u], 2 + use);

        dfs2(v, u);
    }
}
 
int32_t main()
{
	IOS
	FRE
	ll t,m,k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n;
	f(i,n-1) cin>>u>>v, g[u].pb(v), g[v].pb(u);
	dfs(1, 0);
    dfs2(1, 0);
    ll diameter=0;
    for (ll i = 1; i <= n; i++) {
        diameter=max(diameter,in[i]+out[i]);
    }
    cout<<diameter;
}
