// https://codeforces.com/blog/entry/84413
// O(2 ^ N * (N ^ 2))
// Credit: https://codeforces.com/profile/Not-Afraid

/*
You are given an array of size n (n is always even).
You have to perform n/2 moves.
In each move, you can remove any two elements from the array 
and each move will contribute gcd(removed_val_1, removed_val_2) * move_number. 
So we have to maximize the score.

Constraints:-
n <= 20
arr[i] <= 10^5
*/



int dp[1 << 20];
vector<int> a;

int go(int mask) {
    int used = __builtin_popcount(mask);
    
    // all array elements are used
    if (used == n) {
        return 0;
    }

    if (dp[mask] != -1) { 
        return dp[mask];
    }

    int cur_move = (used / 2) + 1;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!(mask & (1 << i)) && !(mask & (1 << j))) {
                int points = __gcd(a[i], a[j]) * cur_move;
                int rem = go(mask | (1 << i) | (1 << j));
                ans = max(ans, rem + points);
            }
        }
    }

    return dp[mask] = ans;
}


void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    cout << go(0);
}
