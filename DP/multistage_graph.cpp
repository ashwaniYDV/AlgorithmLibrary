// https://youtu.be/FcScLYJI42E 
// Abdul Bari

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
	n=8;
	ll stages=4, mn;
	ll cost[n+1], d[n+1], path[n+1];
	ll c[n+1][n+1]={{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
					{INT_MAX, INT_MAX, 2, 1 , 3, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
					{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 2, 3, INT_MAX, INT_MAX,},
					{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 6, 7, INT_MAX, INT_MAX},
					{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 6, 8, 9, INT_MAX},
					{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 6},
					{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 4},
					{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5},
					{INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}};
	cost[n]=0;
	for(ll i=n-1; i>=1; i--){
		mn=INT_MAX;
		for(ll j=i+1; j<=n; j++){
			if(c[i][j]!=INT_MAX && c[i][j]+cost[j] < mn){
				mn=c[i][j]+cost[j];
				d[i]=j;
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
