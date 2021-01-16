// https://youtu.be/d7kvyp6dfz8

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


double prob[20][20];
double dp[1 << 20];

double pMove(int prevMask, int j) {
    int k = __builtin_popcount(prevMask);
    // kC2
    double denominator = (k * (k-1)) / 2;

    double moveProb = 0;
    for (int fish = 0; fish < n; fish++) {
        if((prevMask) & (1 << fish)) {
            moveProb += prob[fish][j];
        }
    }

    return moveProb / denominator;
}

double go(int mask) {
    int alive = __builtin_popcount(mask);
    
    // all fish are alive (prob = 1)
    if (alive == n) {
        return 1;
    }

    if (dp[mask] > 0) { 
        return dp[mask];
    }

    double ans = 0;

    for (int fishWhichDies = 0; fishWhichDies < n; fishWhichDies++) {
        if(!((mask) & (1 << fishWhichDies))) {
            int prevMask = mask | (1 << fishWhichDies);
            double prevDayProb = go(prevMask);
            ans += prevDayProb * pMove(prevMask, fishWhichDies);
        }
    }

    return dp[mask] = ans;
}

// assuming initialy only one fish is left and going backward to calculate all the states of DP
void solve() {
    cin >> n;
    f(i, n) {
        f(j, n) {
            cin >> prob[i][j];
        }
    }

    memset(dp, -1, sizeof dp);
    
    f(i, n) cout << go(1 << i) << " ";
    cout << endl;
}
 
int32_t main() {
    IOS
    PRECISION(8)
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
