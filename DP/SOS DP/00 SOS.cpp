// https://codeforces.com/blog/entry/45223
// https://unacademy.com/class/sum-over-subsets-dp-sos-dp/5QHT2VC0

/*
Time  = O(n * 2^n)
Space = O(n * 2^n)
*/

void solve() {
    int x, y, z;
    cin >> n;
    int size = (1 << n);
    int a[size];
    for(int mask = 0; mask < size; mask++) 
        cin >> a[mask];


    int f[size];
    int dp[size][n+1];

    // base case
    for(int mask = 0; mask < size; mask++) {
        dp[mask][0] = a[mask];
    }

    for(int mask = 0; mask < size; mask++) {
        for(int i = 1; i <= n; i++) {
            // case 1: ith bit is on (since binary rep is 0 indexed, we'll use (i-1) in code)
            if(mask & (1 << (i-1))) {
                dp[mask][i] = dp[mask][i-1] + dp[mask ^ (1 << (i-1))][i-1];
            }
            // case 2: ith bit is off
            else {
                dp[mask][i] = dp[mask][i-1];
            }
        }
    }

    for(int mask = 0; mask < size; mask++) {
        f[mask] = dp[mask][n];
    }

    for(int mask = 0; mask < size; mask++) {
        cout << f[mask] << " ";
    }
}
