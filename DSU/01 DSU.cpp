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


unordered_map<ll,ll> par, size;

void initialize(){
	for(ll i=1; i<=n; i++){
		par[i]=i;
		size[i]=1;
	}
}

ll find_par(ll a){
	if(par[a]==a)
		return a;
	return find_par(par[a]);
}

void union_set(ll a, ll b){
	a=find_par(a);
	b=find_par(b);
	if(a==b)
		return;
	if(size[a]<size[b])
		swap(a,b);
	par[b]=a;
	size[a]+=size[b];
}

int32_t main()
{
	IOS
	ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n;
	initialize();
	cin>>t;
	while(t--){
		cin>>x>>y;
		cout<<find_par(x)<<" "<<find_par(y)<<endl;
		union_set(x,y);
		cout<<find_par(x)<<" "<<find_par(y)<<endl;
	}
}
