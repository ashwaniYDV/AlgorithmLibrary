// https://leetcode.com/problems/house-robber/
// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261
// https://youtu.be/GrMBfJNk_NY?si=-qvs6C_PJ-TOVa0l

/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed.
Adjacent houses have security systems connected and 
it will automatically contact police if two adjacent houses were broken in same night.
Given an integer array nums representing the amount of money of each house, 
return max amount of money you can rob tonight without alerting police.
*/


// top down
class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp) {
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + f(i - 2, nums, dp);
        int notPick = f(i - 1, nums, dp);
        
        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return f(n - 1, nums, dp);
    }
};


// bottom up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            int pick = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        return dp[n-1];
    }
};


// space optimized
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            
            int cur = max(pick, notPick);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};










// Time = O(n * k), Space = O(n)
const int N = 1e5 + 5;
int n, m, k;

void solve() {
    cin >> n;
    vector<int> a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    k = 1;

    if (n <= k) {
        int res = 0;
        for (int i = 1; i <= n; i++) res += a[i];
        cout << res << endl;
        return;
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = dp[i - 1] + a[i];
    }

    for (int i = k + 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        int sum = 0;
        for (int j = i; j > i - k; j--) {
            sum += a[j];
            dp[i] = max(dp[i], sum + dp[j - 2]);
        }
    }

    cout << dp[n] << endl;
}
