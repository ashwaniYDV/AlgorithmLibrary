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



struct Edge {
	ll source;
	ll dest;
	ll weight;
};

bool compare(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}

ll findParent(ll v, ll *parent){
	if(parent[v]==v) return v;
	return findParent(parent[v], parent);
}

vector<Edge> input;
vector<Edge> result;
void kruskals(){
	sort(input.begin(), input.end(), compare);
	ll parent[n+1];
	for(ll i=1;i<=n;i++) parent[i]=i;

	for(Edge currEdge: input){
		ll sourceParent = findParent(currEdge.source, parent);
		ll destParent = findParent(currEdge.dest, parent);
		if(sourceParent!=destParent){
			result.pb(currEdge);
			parent[sourceParent]=destParent;
		}
	}
}

int32_t main()
{
	IOS
	ll k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n>>m;
	f(i,m){
		cin>>u>>v>>x;
		Edge edg={u, v, x};
		input.pb(edg);
	}
	kruskals();
	ll cost=0;
	for(Edge e: result){
		cout<<e.source<<" "<<e.dest<<" "<<e.weight<<endl;
		cost+=e.weight;
	}
	cout<<"Min cost: "<<cost;
}
