// Single source shortest path for weighted graphs
// It fails for negative weights (in that case we can use bellman ford)

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

vector<pll> adj[N];
void dijkstra(ll source){
	f(i,n+1) dp[i]=inf;
    priority_queue <pll, vector<pll>, greater<pll> > pq;
    pq.push({0, source});
    dp[source] = 0;

    while(!pq.empty()){
        pll x = pq.top();
        pq.pop();

        ll u = x.second;

        // if(dp[u] < x.first) continue;

        for(pll y: adj[u]){
            if(dp[y.first] > dp[u] + y.second){
                dp[y.first] = dp[u] + y.second;
                pq.push({dp[y.first], y.first});
            }
        }
    }
}

int32_t main()
{
	IOS
	ll k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n>>m;
	f(i,m) cin>>u>>v>>x, adj[u].pb({v,x}), adj[v].pb({u,x});
	cin>>x;
	dijkstra(x);
	for(ll i=1; i<=n; i++){
		cout<<"Distance of "<<i<<" from "<<x<<" is "<<dp[i]<<endl;
	}
}
