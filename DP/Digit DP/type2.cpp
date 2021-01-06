// http://www.lightoj.com/volume_showproblem.php?problem=1122
/*
Given a set of digits S, and an integer n, 
you have to find how many n-digit integers are there, 
which contain digits that belong to S and the difference between any two adjacent digits 
is not more than two.

Input:
Input starts with an integer T (≤ 300), denoting the number of test cases.
Each case contains two integers, m (1 ≤ m < 10) and n (1 ≤ n ≤ 10). 
The next line will contain m integers (from 1 to 9) separated by spaces. 
These integers form the set S as described above. 
These integers will be distinct and given in ascending order.

Output
For each case, print the case number and the number of valid n-digit integers in a single line.

Sample Input
3
3 2
1 3 6
3 2
1 2 3
3 3
1 4 6

Output for Sample Input
Case 1: 5
Case 2: 9
Case 3: 9
*/
 
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

ll dp[12][12];

ll digit_dp(ll n, vector<ll> s, ll pos=0, ll prevDigit=0){
	if(pos==n){
		return 1;
	}

	if(dp[pos][prevDigit]!=-1) return dp[pos][prevDigit];

	ll res=0;
	for(ll i=0; i<s.size(); i++){
		if(prevDigit==0 || abs(s[i]-prevDigit) <= 2){
			res+=digit_dp(n, s, pos+1, s[i]);
		}
	}
	return dp[pos][prevDigit]=res;
}

void solve(ll counter){
	ll t,z,p,q,u,v,x,y,ct=0,flag=0;
	cin>>m>>n;
	vector<ll> s(m);
	for(auto &x: s){
		cin>>x;
	}
	memset(dp,-1,sizeof(dp));
	ll ans=digit_dp(n, s);
	cout<<"Case "<<counter<<": "<<ans<<endl;
}
 
int32_t main()
{
	IOS
	ll _;
	cin>>_;
	ll ct=1;
	while(_--){
		solve(ct);
		ct++;
	}
}
