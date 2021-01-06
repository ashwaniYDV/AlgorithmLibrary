// dp_lds[i] stores value of longest decreasing subsequence ending with nums[i]  (i.e including nums[i])

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


void solve() {
    cin >> n;
    vector<int> nums(n);
    f(i, n) cin >> nums[i];
    
    int mx_lis = 0, mx_lds = 0;
    vector<int> dp_lis(n+1, 1);
    vector<int> dp_lds(n+1, 1);
    
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            // longest increasing
            if(nums[i] > nums[j]){
                dp_lis[i] = max(dp_lis[i], dp_lis[j] + 1);
            }
            // longest decreasing
            if(nums[i] < nums[j]){
                dp_lds[i] = max(dp_lds[i], dp_lds[j] + 1);
            }
        }
        mx_lis = max(mx_lis, dp_lis[i]);
        mx_lds = max(mx_lds, dp_lds[i]);
    }
    cout << mx_lis << endl;
    cout << mx_lds << endl;
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
