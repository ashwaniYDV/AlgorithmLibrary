#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>n;a<n?i+=1:i-=1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
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

const ll mod = 1000000007;
const ll N = 1e6+5, M = N, ninf = -2e5, inf = 10000000;
vl g[N], dist;
ll a[N], b[N], dp[N], in[N], out[N], level[N];
ll n, m;



int32_t main()
{
	IOS
	ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;

	ll n=8;
	ll stages=4;
	vector<pair<ll,ll>> g[n+1];
	g[1].pb({2,2});
	g[1].pb({3,1});
	g[1].pb({4,3});
	g[2].pb({5,2});
	g[2].pb({6,3});
	g[3].pb({5,6});
	g[3].pb({6,7});
	g[4].pb({5,6});
	g[4].pb({6,8});
	g[4].pb({7,9});
	g[5].pb({8,6});
	g[6].pb({8,4});
	g[7].pb({8,5});

	ll mn;
	ll cost[n+1], d[n+1], path[n+1];
	cost[n]=0;
	for(ll i=n-1; i>=1; i--){
		mn=INT_MAX;
		for(pair<ll,ll>pp: g[i]){
			if(pp.S+cost[pp.F] < mn){
				mn=pp.S+cost[pp.F];
				d[i]=pp.F;
			}
		}
		cost[i]=mn;
	}
	// min cost
	cout<<cost[1]<<endl;

	path[1]=1, path[stages]=n;
	for(ll i=2; i<stages; i++){
		path[i]=d[path[i-1]];
	}
	
	// possible path
	for(ll i=1; i<=stages; i++) cout<<path[i]<<" ";
}
