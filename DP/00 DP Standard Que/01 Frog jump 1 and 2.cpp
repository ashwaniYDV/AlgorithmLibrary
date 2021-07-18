// https://www.naukri.com/code360/problems/frog-jump_3621012?leftPanelTabValue=PROBLEM

/*
Frog Jump 1
You can take 1 or 2 jumps.
*/

// top down
#include <bits/stdc++.h> 
using namespace std;

int f(int i, vector<int>& heights, vector<int>& dp) {
    if(i == 0) return 0;

    if(dp[i] != -1) return dp[i];

    int x = abs(heights[i] - heights[i - 1]) + f(i - 1, heights, dp);
    
    int y = INT_MAX;
    if(i >= 2) y = abs(heights[i] - heights[i - 2]) + f(i - 2, heights, dp);

    return dp[i] = min(x, y);
}
int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, -1);
    return f(n - 1, heights, dp);
}


// bottom up
#include <bits/stdc++.h> 
using namespace std;

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n);

    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int x = abs(heights[i] - heights[i - 1]) + dp[i - 1];
        
        int y = INT_MAX;
        if(i >= 2) y = abs(heights[i] - heights[i - 2]) + dp[i - 2];
        
        dp[i] = min(x, y);
    }
    return dp[n-1];
}


// space optimized
#include <bits/stdc++.h> 
using namespace std;

int frogJump(int n, vector<int> &heights) {
    int prev1 = 0, prev2 = 0;

    for(int i = 1; i < n; i++) {
        int x = abs(heights[i] - heights[i - 1]) + prev1;
        
        int y = INT_MAX;
        if(i >= 2) y = abs(heights[i] - heights[i - 2]) + prev2;
        
        int cur = min(x, y);

        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}









/*
Frog Jump 2
You can take 1 or 2 or ... k jumps.
*/

#include <bits/stdc++.h> 
using namespace std;

int f(int i, vector<int>& heights, vector<int>& dp, int k) {
    if(i == 0) return 0;

    if(dp[i] != -1) return dp[i];

    int res = INT_MAX;

    for(int j = 1; j <= k && (i - j >= 0); j++) {
        int x = abs(heights[i] - heights[i - j]) + f(i - j, heights, dp, k);
        res = min(res, x);
    }
    
    return dp[i] = res;
}
int frogJump(int n, vector<int> &heights) {
    int k = 2;
    vector<int> dp(n, -1);
    return f(n - 1, heights, dp, k);
}



#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights) {
    int k = 2;
    vector<int> dp(n);

    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int res = INT_MAX;
        for(int j = 1; j <= k && (i - j >= 0); j++) {
            int x = abs(heights[i] - heights[i - j]) + dp[i - j];
            res = min(res, x);
        }
        dp[i] = res;
    }
    return dp[n-1];
}