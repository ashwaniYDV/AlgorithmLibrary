// Practice is the only shortcut to improve
 
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

// upto 10^8
ll dp[10][80][2];

ll digit_dp(string str, ll pos=0, ll sum=0, ll tight=1){
	if(pos==str.length()) return sum;

	if(dp[pos][sum][tight]!=-1) return dp[pos][sum][tight];
	
	if(tight==1){
		ll res=0;
		for(ll i=0;i<=str[pos]-'0';i++){
			if(i==str[pos]-'0')
				res+=digit_dp(str,pos+1,sum+i,1);
			else
				res+=digit_dp(str,pos+1,sum+i,0);
		}
		return dp[pos][sum][tight]=res;
	}else{
		ll res=0;
		for(ll i=0;i<=9;i++){
			res+=digit_dp(str,pos+1,sum+i,0);
		}
		return dp[pos][sum][tight]=res;
	}
}

void solve(){
	ll t,z,p,q,u,v,x,y,ct=0,flag=0;
	ll l,r;
	cin>>l>>r;
	string strL=to_string(l-1);
	string strR=to_string(r);
	memset(dp,-1,sizeof(dp));
	ll ansL=digit_dp(strL);
	memset(dp,-1,sizeof(dp));
	ll ansR=digit_dp(strR);
	cout<<ansR-ansL<<endl;
}
 
int32_t main()
{
	IOS
	ll _;
	// cin>>_;
	// while(_--)
		solve();
}
