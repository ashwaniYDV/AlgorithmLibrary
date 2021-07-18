// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
// https://atcoder.jp/contests/dp/tasks/dp_d
// https://atcoder.jp/contests/dp/tasks/dp_e


int fun(int pos, int W, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp){
    if(pos >= n || W == 0) return 0;
 
    if(dp[pos][W] != -1) return dp[pos][W];
 
    if(weight[pos] > W) return dp[pos][W] = fun(pos+1, W, weight, value, dp);
 
    return dp[pos][W] = max(fun(pos + 1, W, weight, value, dp), value[pos] + fun(pos+1, W - weight[pos], weight, value, dp));
}

void normalfun(vector<int>& weight, vector<int>& value, int W) {
    vector<vector<int>> dp(105, vector<int>(100005, -1));
    cout << fun(0, W, weight, value, dp) << endl;
}

void dpfun(vector<int>& weight, vector<int>& value, int W) {
    int dp[n+1][W+1];
    for (ll i = 0; i <= n; i++) { 
        for (ll w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) {
                dp[i][w] = 0; 
            } else if (weight[i-1] > w) {
                dp[i][w] = dp[i-1][w]; 
            } else {
                dp[i][w] = max(dp[i-1][w], value[i-1] + dp[i-1][w-weight[i-1]]);
            }
       } 
   } 
   cout << dp[n][W] << endl;
}

void solve() {
    int W;
    cin >> n >> W;
    vector<int> weight(n), value(n);
    f(i,n) cin >> weight[i] >> value[i];
    normalfun(weight, value, W);
    dpfun(weight, value, W);
}



























void dpfun(int n, int W, vector<int>& weight, vector<int>& value) {
    int totalValue = 0;
    
    f(i, n) {
        totalValue += value[i];
    }

    // dp[i][j] denotes the least weight to get a value of j from the first i objects
    ll dp[n+1][totalValue+1];

    // It takes 0 weight here
    for(int i = 0; i <= n; i++) { 
        dp[i][0] = 0;
    }
    // Just set it arbitrarily large because we want to calculate min value of weight
    for(int i = 1; i <= totalValue; i++) {   
        dp[0][i] = 1e18;
    }

    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= totalValue; j++) {
            // If I choose this object the value will go over j
            if(j < value[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Either don't choose this object(dp[i][j]) or choose this object
                dp[i][j] = min(dp[i - 1][j], weight[i - 1] + dp[i - 1][j - value[i - 1]]);
            }

           // Is it possible to get value of j in less than w weight
            if(dp[i][j] <= W) {
                // Find maximum such j
                ans = max(ans, j);
            }
        }
    }

    cout << ans << endl;
}

void solve() {
    int x, y, p, q, W;
    cin >> n >> W;
    vector<int> value(n), weight(n);
    f(i, n) {
        cin >> weight[i] >> value[i];
    }
    dpfun(n, W, weight, value);
}
