// You are given a tree. It has nodes from 1 to n. Each node is having a value. You are at root node and your current score is zero.
// At each step you have to move one step down and add the value of that node to the initial sum. 
// Find the max sum on going from root to leaf.

// https://youtu.be/gm4Ye0fESpU

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>n;a<n?i+=1:i-=1)
#define pb push_back
#define F first
#define S second
#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

const ll mod = 1000000007;
const ll N = 3e5, M = N;
ll a[N], dp[N];
vl g[N];
 
vector <ll> adj[350000];
// bool visited[350000] = { false };
void dfs(ll u, ll par){
	dp[u]=a[u];
	ll mx=0;
	for(ll child: adj[u]){
		if(child==par) continue;
		dfs(child, u);
		mx=max(mx, dp[child]);
	}
	dp[u]+=mx;
}

 
int main()
{
	ios
	ll t,n,k,x,y,z,p,q,u,v;
	ll ct=0,flag=0;
	cin>>n;
	f(i,n-1) cin>>u>>v, adj[u].pb(v), adj[v].pb(u);
	fa(i,1,n+1) cin>>a[i];
	dfs(1,0);
	cout<<dp[1]<<endl;

}
