#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
 
#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>=n;a<n?i+=1:i-=1)
#define rep(i,a, n) for(i = a; i < n; i++)
#define ren(i,a, n) for(i = a; i >= n; i--)
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
// const ll N = 1e6+5, M = N, ninf = -2e5, inf = (int)1e9;
// vl g[N], dist;
// ll a[N], b[N], dp[N], in[N], out[N], vis[N], level[N];
// const ll N=1005;
ll n, m;

ll dirX[]={1, -1, 0, 0};
ll dirY[]={0, 0, 1, -1};
ll noOfWays=0;

bool isSafe(vector<vector<ll>>& maize, ll x, ll y){
    if( x >= 0 && x < n && y >= 0 && y < m && maize[x][y] == 1) 
        return true;
    return false; 
}

void solveMaze(vector<vector<ll>>& maize, ll x, ll y, ll destX, ll destY, vector<vector<ll>>& visited){
	if(x==destX && y==destY && maize[x][y]==1){
		visited[x][y]=1;
		noOfWays++;
	}
	if(!isSafe(maize, x, y)) return;

	// already visited
	if(visited[x][y]==1) return;

	visited[x][y]=1;

	for(ll i=0; i<4; i++){
		solveMaze(maize, x+dirX[i], y+dirY[i], destX, destY, visited);
	}

	visited[x][y]=0;
}

void solve(){
	ll t,z,p,q,u,v,x,y,ct=0,flag=0;
	cin>>n>>m;
	vector<vector<ll>>maize(n, vector<ll>(m));
	vector<vector<ll>>visited(n, vector<ll>(m));
	f(i,n){
		f(j,m){
			cin>>maize[i][j];
			visited[i][j]=0;
		}
	}
	solveMaze(maize, 0, 0, n-1, m-1, visited);
	cout<<noOfWays<<endl;
}
 
int32_t main()
{
	IOS
	solve();
}
