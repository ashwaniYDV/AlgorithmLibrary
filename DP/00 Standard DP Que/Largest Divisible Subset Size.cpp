// https://codeforces.com/problemset/problem/566/F

/*
NOTE: 
n/1  +  n/2  +  n/3  +  ...  +  n/n = n*log(n) 
*/


// Method 1: (Using LIS concept) [O(n^2)]
// https://leetcode.com/problems/largest-divisible-subset/


// Method 2: [O(nlogn)]
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e6+5;
int a[N+5], dp[N+5];

int n, res;

int main() {
    IOS;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[a[i]] = 1;
    }

    res = 1;

    for (int i = 0; i < n; ++i) {
        for(int j = 2*a[i]; j <= N; j += a[i]) {
            // check if j is present in array a by if(dp[j])
            if(dp[j]) {
                dp[j] = max(dp[j], 1 + dp[a[i]]);
                res = max(res, dp[j]);
            }
        }
    }
    cout << res << endl;

    return 0;
}
