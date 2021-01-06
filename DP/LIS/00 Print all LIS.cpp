// https://www.youtube.com/watch?v=3mD20VSib5E
// Print All Longest Increasing Subsequences

#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define int long long int
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 1e5 + 5;
const int N = 1e5+5;
int n, m;


struct Node {
    int len;
    int idx;
    int val;
    string pathSoFar; 
};

void solve() {
    cin >> n;
    vector<int> nums(n);
    f(i, n) cin >> nums[i];

    vector<int> dp(n+1, 1);
    int mx = 1;

    for(int i=1; i < n; ++i) {
        for(int j=0; j < i; ++j) {
            if(nums[i] > nums[j]){
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        mx = max(mx, dp[i]);
    }

    /////////////////
    queue<Node> q;
    f(i, n) {
        if(dp[i] == mx)
            q.push({mx, i, nums[i], to_string(nums[i])});
    }

    int totalLIS = 0;
    // bfs traversal to print all LIS
    while(q.size()) {
        Node nodea = q.front();
        q.pop();

        if(nodea.len == 1) {
            cout << nodea.pathSoFar << endl;
            totalLIS++;
        }

        // for(int j = 0; j < nodea.idx; j++) [Method 2: as per answer is required]
        for(int j = nodea.idx - 1; j >= 0; j--) {
            if(dp[j] == nodea.len-1 && nums[j] < nodea.val) {
                Node nodeb = {dp[j], j, nums[j], to_string(nums[j]) + " -> " + nodea.pathSoFar};
                q.push(nodeb);
            }
        }
    }

    cout << "\nTotal LIS = " << totalLIS << endl;
    /////////////////
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}

/*

INPUT:
10
10 22 42 33 21 50 41 60 80 3

OUTPUT:
10 -> 22 -> 33 -> 41 -> 60 -> 80
10 -> 22 -> 33 -> 50 -> 60 -> 80
10 -> 22 -> 42 -> 50 -> 60 -> 80

Total LIS = 3






INPUT:
11
10 22 42 33 33 21 50 41 60 80 3

OUTPUT:
10 -> 22 -> 42 -> 50 -> 60 -> 80
10 -> 22 -> 33 -> 50 -> 60 -> 80
10 -> 22 -> 33 -> 50 -> 60 -> 80
10 -> 22 -> 33 -> 41 -> 60 -> 80
10 -> 22 -> 33 -> 41 -> 60 -> 80

Total LIS = 5
*/
