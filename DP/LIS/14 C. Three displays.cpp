// https://codeforces.com/problemset/problem/987/C

/*
There are n displays placed along a road, and the i-th of them can display a text with font size si only. 
Maria Stepanovna wants to rent such three displays with indices i < j < k that the font size increases if you move along the road in a particular direction. 
Namely, the condition si < sj < sk should be held.
The rent cost is for the i-th display is ci. 
Please determine the smallest cost Maria Stepanovna should pay.
*/


const int N = 3e3+5;
int n, m;

struct node {
    int size;
    int cost;
};

vector<node> a;

void solve() {
    cin >> n;
    a.resize(n);
    f(i, n) cin >> a[i].size;
    f(i, n) cin >> a[i].cost;

    int dp[n][3];
    f(i, n) {
        dp[i][0] = a[i].cost;
        dp[i][1] = INF;
        dp[i][2] = INF;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i].size > a[j].size) {
                dp[i][1] = min(dp[i][1], a[i].cost + dp[j][0]);
                dp[i][2] = min(dp[i][2], a[i].cost + dp[j][1]);
            }
        }
    }

    int res = INF;
    f(i, n) res = min(res, dp[i][2]);
    
    cout << (res == INF ? -1 : res) << endl;
}
