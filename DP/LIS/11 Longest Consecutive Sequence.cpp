// https://leetcode.com/problems/longest-consecutive-sequence/

// O(nlogn)
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





// O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dp;
        int res = 0;
        for (int x : nums) {
            if (dp[x]) continue;
            dp[x] = dp[x + dp[x + 1]] = dp[x - dp[x - 1]] = dp[x + 1] + dp[x - 1] + 1;
            res = max(res, dp[x]);
        }
        return res;
    }
};



// Explanation of above O(n) soln
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> dp;
        int res = 0;
        for(int x: nums) {

            //it is in the middle of some consecutive sequence OR we can say it is already visited earlier
            //therefore it does not contribute to a longer sequence
            if(dp[x]) continue; 

            //we cannot find adjacent sequences to x, therefore it is a single element sequence by itself
            if(dp.find(x-1) == dp.end() && dp.find(x+1) == dp.end()){ // 
                res = max(res, dp[x] = 1);
                continue;
            }

            //found a sequence at x+1, we can safely extend the length by 1
            if(dp.find(x-1) == dp.end()){ 

                //we want to maintain the TWO boundaries of the sequence
                //the new length of the sequence is the original length m[x+1] incremented by 1
                //left boundary dp[x] = dp[x+1] +1;
                //right boundary dp[x+dp[x+1]] = dp[x+1]+1;
                //why x+dp[x+1]? it is equal to dp[x+1]+(x+1)-1 
                //meaning the old left boundary x+1 plus the old length dp[x+1] minus 1
                //e.g. for sequence 3,4,5,6 dp[3] = 4, and right boundary 6 = 3+dp[3]-1 (here x+1 == 3);
                int r = dp[x] = dp[x+dp[x+1]] = dp[x+1]+1;
                res = max(res, r);
                continue;
            }

            //this is similar to the above case just extend to the right
            if(dp.find(x+1) == dp.end()){
                int r = dp[x] = dp[x-dp[x-1]] = dp[x-1]+1;
                res = max(res,r);
                continue;
            }

            //here, we found both sequences at x+1 and x-1, for reasons we explained,
            //the sequences have no overlap.
            //Now, we just need to add the length of current element x (which is 1) to both left and right boundaries
            //the new length will be :  
            //old length of left sequence (dp[x-1]) + old length of right sequence (dp[x+1]) + 1
            //We also need to mark dp[x] as visited, here we can either mark it with 1 or the new length;
            int r = dp[x] = dp[x-dp[x-1]] = dp[x+dp[x+1]] = 1 + dp[x+1]+ dp[x-1];
            res = max(res,r);
        }
        return res;
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
