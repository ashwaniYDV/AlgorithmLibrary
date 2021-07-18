// Assignment Problem (classic problem taugh in colleges)
// https://youtu.be/685x-rzOIlY

// Hungarian_algorithm
// https://en.wikipedia.org/wiki/Hungarian_algorithm

/*
Problem Statement:
Let there be N workers and N jobs. 
Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. 
It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way 
that the total cost of the assignment is minimized.

Input Format:
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input:
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

Sample Output:
13

Constraints:
N <= 20
*/



// Method 1: (Less memory efficient)
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 20;
int n, m;

int dp[20][1 << 20];
vector<vector<int>> cost;

int go(int i, int mask) {
    if(i == n) return 0;
    // we can use this also
    // if(mask == ((1 << n) - 1)) return 0;

    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }

    int ans = INF;
    for (int job = 0; job < n; ++job) {
        if (!(mask & (1 << job))) {
            ans = min(ans, cost[i][job] + go(i+1, mask | (1 << job)));
        }
    }

    return dp[i][mask] = ans;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cost.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    cout << go(0, 0);
}









// Method 2.1: (More memory efficient) (Top down)
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 20;
int n, m;

int dp[1 << 20];
vector<vector<int>> cost;

int go(int mask) {
    int i = __builtin_popcount(mask);
    
    if(i == n) return 0;
    // if(mask == ((1 << n) - 1)) return 0;

    if (dp[mask] != -1) {
        return dp[mask];
    }

    int ans = INF;
    for (int job = 0; job < n; ++job) {
        if (!(mask & (1 << job))) {
            ans = min(ans, cost[i][job] + go(mask | (1 << job)));
        }
    }

    return dp[mask] = ans;
}

int32_t main() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cost.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    cout << go(0);
}



// Method 2.2: (More memory efficient) (Bottom up)
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 20;
int n, m, totalMask;

int dp[1 << 20];
vector<vector<int>> cost;

int32_t main() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    cost.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    totalMask = (1 << n) - 1;
    dp[totalMask] = 0;

    for(int mask = totalMask - 1; mask >= 0; mask--) {
        int i = __builtin_popcount(mask);

        int ans = INF;
        for (int job = 0; job < n; ++job) {
            if (!(mask & (1 << job))) {
                ans = min(ans, cost[i][job] + dp[mask | (1 << job)]);
            }
        }

        dp[mask] = ans;
    }


    cout << dp[0];
}
