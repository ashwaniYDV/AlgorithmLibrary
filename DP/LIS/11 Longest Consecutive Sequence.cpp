// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        sort(nums.begin(), nums.end());
        
        int mx = 1, mxSoFar = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1] + 1) {
                mxSoFar++;
            } else if(nums[i] == nums[i-1]) {
                // do nothing
            } else {
                mxSoFar = 1;
            }
            mx = max(mx, mxSoFar);
        }
        
        return mx;
    }
};








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
	cin>>n;
	f(i,n) cin>>a[i];
	map<ll, ll>dp;
	f(i,n){
		dp[a[i]]=max(dp[a[i]], dp[a[i]-1]+1);
	}
	ll mx=0;
	ll ele;
	for(auto it: dp){
		if(it.S>mx){
			mx=it.S;
			ele=it.F;
		}
	}
	cout<<mx<<endl;
	ll pos;
	for(ll i=n-1;i>=0;i--){
		if(a[i]==ele){
			pos=i;
			break;
		}
	}
	ll end=ele-mx+1;
	list<ll> ans;
	for(ll i=pos;i>=0;i--){
		if(ele<end){
			break;
		}
		if(a[i]==ele){
			ans.push_front(i+1);
			ele--;
		}
	}
	for(ll x: ans){
		cout<<x<<" ";
	}
}
