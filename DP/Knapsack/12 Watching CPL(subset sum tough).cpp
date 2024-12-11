// https://www.codechef.com/JAN21B/problems/WIPL

/*
Dp will give correct ans:-
Sort array in descending order.
Dp(i, sum)-> min steps such that we are at ith pos with height of tower 1 as sum and height of tower 2 as prefixsum upto ith pos - sum.
*/


const int MAXN = 5e5+5;
const int N = 5e3+5;
int n, m;

// unoptimized recursive
/*
int fun(int pos, int sum, int n, int k, vector<int> &a) {
    if(sum >= k and (pref[pos] - sum) >= k) {
        return 0;
    };
    if(pos >= n)  return 1e10;

    return 1 + min(fun(pos+1, sum + a[pos], n, k, a), fun(pos+1,  sum, n, k, a));
}
*/

void solve() {
    int x, y, k;
    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    
    if(n == 1) {
        cout << -1 << endl;
        return;
    }

    sort(all(a), greater<>());

    if(a[0] >= k && a[1] >= k) {
        cout << 2 << endl;
        return;
    }
    if(a[0] >= k) {
        int sum = 0;
        for(int i = 1; i < n; i++) {
            sum += a[i];
            if(sum >= k) {
                cout << i+1 << endl;
                return;
            }
        }
        cout << -1 << endl;
        return;
    }

    vector<vector<bool>> dp(n+1, vector<bool>(2*k+5, false));
    f(i, n+1) dp[i][0] = true;
    
    int sum = 0;

    for (ll i = 1; i <= n; i++) {
        sum += a[i-1]; 
        for (ll j = 1; j <= 2*k; j++) { 
            if(j < a[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i-1]];
            }
            if(dp[i][j] && j >= k && (sum - j) >= k) {
                cout << i << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}
 
int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}
