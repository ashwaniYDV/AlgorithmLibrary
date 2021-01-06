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
typedef vector<int> vi;
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

void combinationSum(vector<ll>& ar, ll sum, vector<vector<ll> >& res, vector<ll>& curr, ll index) { 
    // If  current sum becomes negative 
    if (sum < 0) return;
    // if we get exact answer 
    if (sum == 0) { 
        res.push_back(curr); 
        return;
    } 
  
    // Recur for all remaining elements that have value smaller than sum. 
    // for(ll i=index; i<ar.size() && sum-ar[i]>=0; i++){
    for(ll i=index; i<ar.size(); i++){
        // Till every element in the array starting from i which can contribute to the sum add them to list
        curr.push_back(ar[i]); 
        // recur for next numbers 
        combinationSum(ar, sum - ar[i], res, curr, i); 
        // remove number from list (backtracking) 
        curr.pop_back(); 
    } 
} 

int32_t main()
{
    IOS
    ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;

    vector<ll> ar; 
    ar.push_back(2); 
    ar.push_back(4); 
    ar.push_back(8); 
    ar.push_back(6); 
    ar.push_back(8); 
    ll n = ar.size();
  
    // set value of sum 
    ll sum = 8;

    // sort input array 
    sort(ar.begin(), ar.end()); 
    // remove duplicates 
    ar.erase(unique(ar.begin(), ar.end()), ar.end()); 

    vector<ll> curr; 
    vector<vector<ll> > res; 

    combinationSum(ar, sum, res, curr, 0); 

    for (ll i = 0; i < res.size(); i++) { 
        if (res[i].size() > 0) { 
            for (ll j = 0; j < res[i].size(); j++) 
                cout << res[i][j] << " "; 
            cout << "\n"; 
        } 
    } 
}
