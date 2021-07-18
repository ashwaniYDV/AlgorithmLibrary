// https://www.spoj.com/problems/LPIS/

/*
Find the longest perfect increasing subsequence of given sequence.
In a perfect increasing subsequence the difference between any two consecutive elements is always 1.

For example, let’s consider a sequence S = {5, 2, 6, 3, 7, 8, 4}
{5, 7, 8} is an increasing subsequence of sequence S, but not a perfect increasing subsequence.
But {5, 6, 7, 8} is perfect increasing subsequence as the difference between any two consecutive elements is exactly 1.

CONSTRAINTS:
1 <= N <= 1e5
1 <= a[i] <= 1e6

OUTPUT:
A single integer in a line denoting the length of the longest perfect increasing subsequence.

Sample Input: #1
9
5 1 5 6 2 3 8 7 4
Sample Output: #1
4

Sample Input: #2
8
2 2 1 3 5 4 5 6
Sample Output: #2
5
*/


const int N = 1e6+5;
int n, m;

void solve() {
    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    
    vector<int> dp(N, 0);
    int res = 1;

    for(int x: a) {
        dp[x] = dp[x - 1] + 1;
        res = max(res, dp[x]);
    }
    
    cout << res;
}








const int N = 1e6+5;
int n, m;

void solve() {
    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    
    unordered_map<int, int> dp;
    int res = 1;

    for(int x: a) {
        dp[x] = dp[x - 1] + 1;
        res = max(res, dp[x]);
    }
    
    cout << res;
}














// Print Longest Perfect Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

// Function for LIS
int findLIS(int a[], int n) {
    unordered_map<int, int> dp;

    // Initialize result
    int LIS_size = 1;
    int LIS_index = 0;

    dp[a[0]] = 1;

    for (int i = 1; i < n; i++) {
        dp[a[i]] = dp[a[i] - 1] + 1;
        if (LIS_size < dp[a[i]]) {
            LIS_size = dp[a[i]];
            LIS_index = a[i];
        }
    }

    // print LIS size
    cout << "LIS_size = " << LIS_size << "\n";

    // print LIS after setting start element
    cout << "LIS : ";
    int start = LIS_index - LIS_size + 1;
    while (start <= LIS_index) {
        cout << start << " ";
        start++;
    }
}

int main() {
    int a[] = { 2, 5, 3, 7, 4, 8, 5, 13, 6 };
    int n = sizeof(a) / sizeof(a[0]);
    findLIS(a, n);
    return 0;
}
