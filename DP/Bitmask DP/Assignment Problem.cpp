// Assignment Problem (classic problem taugh in colleges)
// https://youtu.be/685x-rzOIlY

// Hungarian_algorithm
// https://en.wikipedia.org/wiki/Hungarian_algorithm

/*
Problem Statement:
Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. 
It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way 
that the total cost of the assignment is minimized.

Input Format:
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input:
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

Sample Output:
13

Constraints:
N <= 20
*/



// Method 1: (Less memory efficient)
#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for(int i=a;i<n;i++)
#define loop(i,a, n) for(int i = a; i <= n; i++)
#define loopb(i,a, n) for(int i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 20;
int n, m;


int dp[20][1 << 20];
vector<vector<int>> cost;

int go(int job, int mask) {
    if(job == n) return 0;

    if (dp[job][mask] != -1) { 
        return dp[job][mask];
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) {
            ans = min(ans, cost[i][job] + go(job+1, mask | (1 << i)));
        }
    }

    return dp[job][mask] = ans;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cost.resize(n, vector<int>(n));
    f(i, n) {
        f(j, n) {
            cin >> cost[i][j];
        }
    }   
    cout << go(0, 0);
}
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}












// Method 2: (More memory efficient)
#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for(int i=a;i<n;i++)
#define loop(i,a, n) for(int i = a; i <= n; i++)
#define loopb(i,a, n) for(int i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5+5;
const int N = 20;
int n, m;


int dp[1 << 20];
vector<vector<int>> cost;

int go(int mask) {
    int job = __builtin_popcount(mask);

    if(job == n) return 0;

    if (dp[mask] != -1) { 
        return dp[mask];
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) {
            ans = min(ans, cost[i][job] + go(mask | (1 << i)));
        }
    }
    return dp[mask] = ans;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cost.resize(n, vector<int>(n));
    f(i, n) {
        f(j, n) {
            cin >> cost[i][j];
        }
    }   
    cout << go(0);
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
