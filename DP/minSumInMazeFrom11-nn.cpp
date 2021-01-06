// https://youtu.be/YBSt1jYwVfU
// https://leetcode.com/problems/minimum-path-sum/submissions/

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
ll n, m;


void fun(vector<vector<ll>> grid){
	ll n=grid.size();
	ll m=grid[0].size();
	ll dp[n][m];
	ll s=0;
	for(ll i=0; i<m; i++){
		s+=grid[0][i];
		dp[0][i]=s;
	}
	s=0;
	for(ll i=0; i<n; i++){
		s+=grid[i][0];
		dp[i][0]=s;
	}

	for(ll i=1;i<n;i++){
		for(ll j=1;j<m;j++){
			dp[i][j]=grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout<<dp[n-1][m-1];
}

int32_t main()
{
	IOS
	ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;
	vector<vector<ll>>vv;
	vv.pb({1,2});
	vv.pb({1,1});
	fun(vv);
}
