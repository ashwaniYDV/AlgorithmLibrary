// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

/*
Count number of ways to partition a set into k subsets?
----------------------------------------------------------------------------------   
Input: n = 3, k = 2
Output: 3
Explanation: Let the set be {1, 2, 3}, 
             we can partition it into 3 subsets in following ways
             {{1,2}, {3}},  {{1}, {2,3}},  {{1,3}, {2}}  
----------------------------------------------------------------------------------             
             
Recursive Solution

Approach: 
Firstly, let’s define a recursive solution to find the solution for nth element. 
There are two cases. 
The previous n – 1 elements are divided into k partitions, i.e S(n-1, k) ways. Put this nth element into one of the previous k partitions. So, count = k * S(n-1, k)
The previous n – 1 elements are divided into k – 1 partitions, i.e S(n-1, k-1) ways. Put the nth element into a new partition ( single element partition).So, count = S(n-1, k-1)
Total count = k * S(n-1, k) + S(n-1, k-1).

Algorithm: 
Create a recursive function which accepts two parameters, n and k. The function returns total number of partitions of n elements into k sets.
Handle the base cases. If n = 0 or k = 0 or k > n return 0 as there cannot be any subset. If n is equal to k or k is equal to 1 return 1.
Else calculate the value as follows: S(n, k) = k*S(n-1, k) + S(n-1, k-1), i.e call recursive function with the recuried parameter and calculate the value of S(n, k).
Return the sum.
*/



#include<bits/stdc++.h>
using namespace std;
 
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
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 5e5 + 5;
const int N = 1e6+5;
int n, m;


int countP(int n, int k) {
    // Base cases
    if (n == 0 || k == 0 || k > n)
        return 0;
    if (k == 1 || k == n)
        return 1;
 
    return  k*countP(n-1, k) + countP(n-1, k-1);
}


int countP_DP(int n, int k) {
    // Table to store results of subproblems
    int dp[n+1][k+1];
 
    // Base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= k; i++) {
        dp[0][k] = 0;
    }
 
    // Fill rest of the entries in dp[][] in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }
 
  return dp[n][k];
}
 
void solve() {
    int x, y, k;
    cout <<  countP(3, 2) << endl;
    cout <<  countP_DP(3, 2) << endl;
}   
 
int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
