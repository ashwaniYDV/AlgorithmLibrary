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
 
pair<ll,ll>bfs(ll root){
    vector<ll>dis(n+1,0);
    queue<ll>q;
    q.push(root);
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        for(auto next:g[node]){
            if(dis[next] || next==root) continue;
            dis[next]=dis[node]+1;
            q.push(next);
        }
    }
    ll mx=0,pos=1;
    for(ll i=1;i<=n;i++)
    	if(dis[i]>mx) mx=dis[i], pos=i;
    		return {pos,mx};
}
 
ll diameter(ll root){
    pair<ll,ll>p1=bfs(root);
    return bfs(p1.F).S;
}
 
 
int32_t main()
{
	IOS
	FRE
	ll t,m,k,x,y,z,p,q,u,v,ct=0,flag=0;
	cin>>n;
	f(i,n-1) cin>>u>>v, g[u].pb(v), g[v].pb(u);
	ll ans=diameter(1);
	cout<<ans;
}
