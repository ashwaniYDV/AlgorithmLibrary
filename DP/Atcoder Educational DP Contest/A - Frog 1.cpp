// https://atcoder.jp/contests/dp/tasks/dp_a

/*
There are N stones, numbered 1,2,…,N. 
For each i (1 ≤ i ≤N), the height of Stone i is hi.
There is a frog who is initially on Stone 1. 
He will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. 
Here, a cost of ∣hi − hj∣ is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches StoneN.
*/

int fun(int i, vector<int>& h, vector<int>& dp){
    if(i == n - 1){
        return 0;
    }
    if(i >= n) {
        return INT_MAX;
    }
    if (dp[i] != -1) return dp[i];

    return dp[i] = min(abs(h[i] - h[i+1]) + fun(i + 1, h, dp), abs(h[i] - h[i+2]) + fun(i + 2, h, dp));
}

void normalfun(vector<int>& h) {
    vector<int> dp(n+5, -1);
    cout << fun(0, h, dp) << endl;
}

void dpfun(vector<int>& h) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);

    for(int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout << dp[n-1] << endl;
}

void solve() {
    cin >> n;
    vector<int> h(n);
    f(i, n) cin >> h[i];
    normalfun(h);
    dpfun(h);
}

int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
