// https://leetcode.com/problems/jump-game-ii/

// Jump game II - Method 1
class Solution {
public:
    int INF = 1e9;
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j >= n) break;
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};

// Jump game II - Method 2
class Solution {
public:
    int INF = 1e9;
    int n;
    
    int go(int pos, vector<int>& jump, vector<int>& dp) {
        if(pos == n - 1) {
            return 0;
        }
        if(pos >= n || jump[pos] == 0) {
            return INF;
        }
        
        if(dp[pos] != -1) return dp[pos];

        int res = INF;
        for(int i = 1; i <= jump[pos]; i++) {
            res = min(res, 1 + go(pos + i, jump, dp));
        }

        return dp[pos] = res;
    }
    
    int jump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n+5, -1);
        return go(0, nums, dp);
    }
};
