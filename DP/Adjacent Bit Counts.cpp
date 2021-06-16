// https://www.geeksforgeeks.org/count-binary-strings-k-times-appearing-adjacent-two-set-bits/

/*
Problem:
Given two integers n and k, count the number of binary strings of length n with k as number of times adjacent 1’s appear.

Examples:

Input  : n = 5, k = 2
Output : 6
Explanation:
Binary strings of length 5 in which k number of times
two adjacent set bits appear.
00111  
01110
11100
11011
10111
11101

Input  : n = 4, k = 1
Output : 3
Explanation:
Binary strings of length 3 in which k number of times
two adjacent set bits appear.
0011  
1100
0110
*/

/*
Solution:

Let there be an array dp[i][j][2] where 
dp[i][j][0] = number of binary strings with length i having j number of two adjacent 1's and ending with 0.
dp[i][j][1] = number of binary strings with length i and j adjacent 1's but ending with 1.

Base case:
dp[1][0][0] = 1 and dp[1][0][1] = 1

Transition: 
dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]
dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1]

Result:
dp[n][k][0] + dp[n][k][1]
*/





// dp[i][j][0] stores count of binary strings of length i with j consecutive 1's and ending at 0.
// dp[i][j][1] stores count of binary strings of length i with j consecutive 1's and ending at 1. 

void solve() {
    ll t, k, x, y;
    cin >> n >> k;
    ll dp[n+1][k+1][2];

    memset(dp, 0, sizeof(dp));

    // If n = 1 and k = 0.
    dp[1][0][0] = 1; // string = 0
    dp[1][0][1] = 1; // string = 1

    loop(i, 2, n){
        loop(j, 0, k){
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];

            dp[i][j][1] = dp[i - 1][j][0];
            if(j - 1 >= 0) dp[i][j][1] += dp[i - 1][j - 1][1];
        }
    }
    cout << dp[n][k][0] + dp[n][k][1] << endl;
}
