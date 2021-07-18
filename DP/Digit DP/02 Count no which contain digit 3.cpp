// https://youtu.be/hxbqUX7IIvw
// Hackerearth - Benny and the broken odometer
// https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/

/*
One fine day, Benny decided to calculate the number of kilometers that she traveled by her bicycle. 
Therefore, she bought an odometer and installed it onto her bicycle. But the odometer was broken. 
It was not able to display the digit 3. This would precisely mean, that the odometer won't be able to display the numbers having one of their digits as 3.

For example, after the number 1299, the odometer will show 1400.

Benny was traveling a lot and now she wants to know the number of kilometers that she has traveled. 
You will be given only the number that Benny saw on the odometer. Your task is to determine the real distance.
*/
 


int dp[11][2][2];
string str;

int digit_dp(int pos, int tight, int flag){
    if(pos == str.length()) return flag;

    if(dp[pos][tight][flag] != -1) return dp[pos][tight][flag];
    
    int res = 0;
    int ub = tight ? (str[pos] - '0') : 9;

    for(int i = 0; i <= ub; i++) {
        int fl = flag;
        if(i == 3) fl = 1;

        res += digit_dp(pos + 1, (tight & (i == ub)), fl);
    }
    
    return dp[pos][tight][flag] = res;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    str = to_string(n);
    int res = digit_dp(0, 1, 0);
    cout << n - res << endl;
}


signed main() {
    IOS
    clock_t begin = clock();
    PRECISION(10);
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr << "Time elapsed: " << (clock() - begin) * 1000.0 / CLOCKS_PER_SEC << "ms" << '\n';
}
