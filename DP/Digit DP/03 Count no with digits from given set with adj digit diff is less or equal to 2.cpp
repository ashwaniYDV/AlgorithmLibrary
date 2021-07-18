// http://www.lightoj.com/volume_showproblem.php?problem=1122
/*
Given a set of digits S, and an integer n, 
you have to find how many n-digit integers are there, 
which contain digits that belong to S and the difference between any two adjacent digits 
is not more than two.

Input:
Input starts with an integer T (≤ 300), denoting the number of test cases.
Each case contains two integers, m (1 ≤ m < 10) and n (1 ≤ n ≤ 10). 
The next line will contain m integers (from 1 to 9) separated by spaces. 
These integers form the set S as described above. 
These integers will be distinct and given in ascending order.

Output
For each case, print the case number and the number of valid n-digit integers in a single line.

Sample Input
3
3 2
1 3 6
3 2
1 2 3
3 3
1 4 6

Output for Sample Input
Case 1: 5
Case 2: 9
Case 3: 9
*/
 
int dp[12][12];
vector<int> s;

int digit_dp(int pos, int prevDigit) {
    if(pos == n) return 1;

    if(dp[pos][prevDigit] != -1) return dp[pos][prevDigit];

    int res = 0;
    f(i, m) {
        if(prevDigit == 99 || abs(s[i] - prevDigit) <= 2) {
            res += digit_dp(pos + 1, s[i]);
        }
    }
    return dp[pos][prevDigit] = res;
}

void solve(int testcase) {
    cin >> m >> n;
    s = vector<int>(m);
    
    f(i, m) cin >> s[i];

    memset(dp,-1,sizeof(dp));
    int res = digit_dp(0, 99);
    cout << "Case " << testcase << ": " << res << endl;
}


signed main() {
    IOS
    clock_t begin = clock();
    PRECISION(10);
    int t = 1;
    cin >> t;
    f(i, t) {
        solve(i+1);
    }
    cerr << "Time elapsed: " << (clock() - begin) * 1000.0 / CLOCKS_PER_SEC << "ms" << '\n';
}
