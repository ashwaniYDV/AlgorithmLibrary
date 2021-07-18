// https://www.geeksforgeeks.org/problems/geeks-training/1
// https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM
// https://atcoder.jp/contests/dp/tasks/dp_c

/*
Geek is planing this ‘N’ days-long training schedule. 
Each day, he can perform any one of these three activities. 
(Running, Fighting Practice or Learning New Moves). 
Each activity has some merit points on each day. 
As Geek has to improve all his skills, he can’t do the same activity in two consecutive days. 
Can you help Geek find out the maximum merit points Geek can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. 
Your task is to calculate the maximum number of merit points that Geek can earn.
*/

// top down
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp) {
        if(i < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = 0;
        if(j == 0) res = a[i][0] + max(f(i - 1, 1, a, dp), f(i - 1, 2, a, dp));
        if(j == 1) res = a[i][1] + max(f(i - 1, 0, a, dp), f(i - 1, 2, a, dp));
        if(j == 2) res = a[i][2] + max(f(i - 1, 0, a, dp), f(i - 1, 1, a, dp));
        
        return dp[i][j] = res;
    }
    int maximumPoints(vector<vector<int>>& a, int n) {
        vector<vector<int>> dp(n, vector<int>(3, -1));

        return max({f(n-1, 0, a, dp), f(n-1, 1, a, dp), f(n-1, 2, a, dp)});
    }
};


// bottom up
class Solution {
public:
    int maximumPoints(vector<vector<int>>& a, int n) {
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0] = a[0];
    
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                if(j == 0) dp[i][j] = a[i][j] + max(dp[i-1][1], dp[i-1][2]);
                if(j == 1) dp[i][j] = a[i][j] + max(dp[i-1][0], dp[i-1][2]);
                if(j == 2) dp[i][j] = a[i][j] + max(dp[i-1][0], dp[i-1][1]);
            }
        }
    
        return max({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] });
    }
};


// space optimized
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& a, int n) {
        vector<int> prevDp = a[0];
    
        for(int i = 1; i < n; i++) {
            vector<int> curDp(3, 0);
            for(int j = 0; j < 3; j++) {
                if(j == 0) curDp[j] = a[i][j] + max(prevDp[1], prevDp[2]);
                if(j == 1) curDp[j] = a[i][j] + max(prevDp[0], prevDp[2]);
                if(j == 2) curDp[j] = a[i][j] + max(prevDp[0], prevDp[1]);
            }
            prevDp = curDp;
        }
    
        return max({ prevDp[0], prevDp[1], prevDp[2] });
    }
};


// space optimized
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& a, int n) {
        vector<int> prevDp = a[0];
    
        for(int i = 1; i < n; i++) {
            vector<int> curDp(3, 0);
            for(int j = 0; j < 3; j++) {
                int mx = INT_MIN;
                for(int k = 0; k < 3; k++) {
                    if(k != j) mx = max(mx, prevDp[k]);
                }
                curDp[j] = a[i][j] + mx;
            }
            prevDp = curDp;
        }
    
        return max({ prevDp[0], prevDp[1], prevDp[2] });
    }
};