// https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize "03"
#pragma GCC target("sse4")

#define ll long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;a<n?i<n:i>=n;a<n?i+=1:i-=1)
#define loop(i,a, n) for(ll i = a; i <= n; i++)
#define loopb(i,a, n) for(ll i = a; i >= n; i--)
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
// const ll N = 1e6+5;	
// ll a[N], b[N], dp[N], in[N], out[N], level[N], vis[N];
// vl g[N];
ll n, m;

bool isPalindrome(string str, ll low, ll high) { 
    while (low < high) { 
        if (str[low] != str[high]) 
            return false; 
        low++; 
        high--; 
    } 
    return true; 
}

void allPalPart(vector<vector<string> >& allPart, vector<string>& currPart, ll start, ll n, string s) { 
    // If 'start' has reached len 
    if (start >= n) { 
        allPart.push_back(currPart); 
        return; 
    } 
  
    // Pick all possible ending points for substrings 
    for (ll i=start; i<n; i++) { 
        // If substring str[start..i] is palindrome 
        if (isPalindrome(s, start, i)) { 
            // Add the substring to result 
            currPart.push_back(s.substr(start, i-start+1)); 
  
            // Recur for remaining remaining substring 
            allPalPart(allPart, currPart, i+1, n, s); 
              
            // Remove substring str[start..i] from current  
            // partition 
            currPart.pop_back(); 
        } 
    } 
} 

void solve() {
	string s = "nitin";
	n = s.length();
	vector<vector<string> > allPart; 
	vector<string> currPart; 
	allPalPart(allPart, currPart, 0, n, s);
	for (ll i=0; i< allPart.size(); i++ ) { 
        for (ll j=0; j<allPart[i].size(); j++) {
            cout << allPart[i][j] << " "; 
        }
        cout << "\n"; 
    }
}

int32_t main() {
	IOS
	solve();
}
