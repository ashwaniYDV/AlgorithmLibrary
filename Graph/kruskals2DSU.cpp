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
const ll N = 1e6+5, M = N, ninf = -2e5, inf = (int)1e9;
vl g[N], dist;
ll a[N], b[N], dp[N], in[N], out[N], vis[N], level[N];
ll n, m;


unordered_map<ll,ll> par, rnk;

void initialize(){
	for(ll i=1; i<=n; i++){
		par[i]=i;
		rnk[i]=1;
	}
}

ll find_set(ll a){
	if(par[a]==a)
		return a;
	return par[a]=find_set(par[a]);
}

void union_set(ll a, ll b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(rnk[a]<rnk[b])
			swap(a,b);
		par[b]=a;
		rnk[a]+=rnk[b];
	}
}

int32_t main()
{
	IOS
	ll t,k,x,y,z,p,q,u,v,ct=0,flag=0, ans=0;
	cin>>n>>m;
	initialize();
	vector<pair<ll,pair<ll,ll>>> input;
	vector<pair<ll,ll>> result;
	f(i,m){
		cin>>u>>v>>x;
		input.pb({x, {u, v}});
	}
	sort(input.begin(), input.end());
	f(i,m){
		z=input[i].F, x=input[i].S.F, y=input[i].S.S;
		if(find_set(x)!=find_set(y)){
			ans+=z;
			result.pb(input[i].S);
			union_set(x, y);
		}
	}
	cout<<ans<<endl;
	f(i, result.size()){
		cout<<result[i].F<<" "<<result[i].S<<endl;
	}
}
