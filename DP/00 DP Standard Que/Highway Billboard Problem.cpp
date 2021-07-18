// https://www.geeksforgeeks.org/highway-billboard-problem/
// https://youtu.be/SiGqwJOvflE

/*
Consider a highway of M miles. The task is to place billboards on the highway such that revenue is maximized. 
The possible sites for billboards are given by number x1 < x2 < ….. < xn-1 < xn, specifying positions in miles measured from one end of the road. 
If we place a billboard at position xi, we receive a revenue of ri > 0. 
There is a restriction that no two billboards can be placed within t miles or less than it. 
Note : All possible sites from x1 to xn are in range from 0 to M as need to place billboards on a highway of M miles.

Examples: 

Input : M = 20
        x[]       = {6, 7, 12, 13, 14}
        revenue[] = {5, 6, 5,  3,  1}
        t = 5
Output: 10
By placing two billboards at 6 miles and 12 miles will produce the maximum revenue of 10.

Input : M = 15
        x[] = {6, 9, 12, 14}
        revenue[] = {5, 6, 3, 7}
        t = 2
Output : 18  
*/



/*
Two Solutions:
--------------
Method 1: It depends on the number of billboards
Time = O(n ^ 2)

Method 2: It depends on the number of miles
Time = O(m)
*/





// Method 1.1
// Time = O(n ^ 2), Space = O(n ^ 2)

#include <bits/stdc++.h>
using namespace std;

int M, t, n;
vector<int> x, revenue;

int go(int i, int prevPos) {
    if (i >= n) return 0;

    if (prevPos == -1) {
        int a = go(i + 1, -1);
        int b = revenue[i] + go(i + 1, i);

        return max(a, b);
    }

    int res = go(i + 1, prevPos);
    if (x[i] - x[prevPos] > t) {
        res = max(res, revenue[i] + go(i + 1, i));
    }
    return res;
}

int main() {
    M = 15;
    x = {6, 9, 12, 14};
    revenue = {5, 6, 3, 7};
    t = 2;

    n = x.size();

    cout << go(0, -1) << endl;
}








// Method 1.2 (LIS variation)
// Time = O(n ^ 2), Space = O(n)

#include <bits/stdc++.h>
using namespace std;

int M, t, n;
vector<int> x, revenue;

int main() {
    M = 15;
    x = {6, 9, 12, 14};
    revenue = {5, 6, 3, 7};
    t = 2;

    n = x.size();

    // LIS variation
    vector<int>dp(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = revenue[i];
        res = max(res, revenue[i]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (x[i] - x[j] > t) {
                dp[i] = max(dp[i], dp[j] + revenue[i]);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << endl;
}













/*
Let dp[i] (1 <= i <= M) = max revenue generated from beginning to i miles

Now for each mile on the highway, we need to check whether this mile has the option for any billboard,
if not then the maximum revenue generated till that mile would be same as maximum revenue generated till one mile before.

But if that mile has the option for billboard then we have 2 options:
a) Either we will place the billboard, ignore the billboard in previous t miles, and add the revenue of the billboard placed.
b) Ignore this billboard. 

So dp[i] = max(dp[i - 1], dp[i - t - 1] + revenue[i])
*/

// Method 2
// Time = O(m), Space = O(m)

#include <bits/stdc++.h>
using namespace std;

int M, t, n;
vector<int> x, revenue;

int main() {
    M = 15;
    x = {6, 9, 12, 14};
    revenue = {5, 6, 3, 7};
    t = 2;

    n = x.size();

    // dp[i] = max revenue till mile i.
    vector<int> dp(M + 1, 0);

    int nxtBoardIdx = 0;
    for (int i = 1; i <= M; i++) {
        if (nxtBoardIdx < n && x[nxtBoardIdx] == i) {
            // We have 2 options, we either take current or we ignore current billboard.

            // If current position is less than or equal to t, then we can have only one billboard.
            if (i <= t) {
                dp[i] = max(dp[i - 1], revenue[nxtBoardIdx]);
            } else {
                dp[i] = max(dp[i - 1], dp[i - t - 1] + revenue[nxtBoardIdx]);
            }

            nxtBoardIdx++;
        } else {
            dp[i] = dp[i - 1];
        }
    }

    cout << dp[M];
}
