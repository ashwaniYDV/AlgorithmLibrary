// https://leetcode.com/problems/reducing-dishes/

// DP Soln
class Solution {
public:
    int n;
    int go(int pos, int t, vector<int>& satisfaction, vector<vector<int>>& dp) {
        if(pos == n) return 0;
        
        if(dp[pos][t] != -1) return dp[pos][t];
        
        int res = t*satisfaction[pos] + go(pos+1, t+1, satisfaction, dp);
        res = max(res, go(pos+1, t, satisfaction, dp));
        
        return dp[pos][t] = res;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n+5, vector<int>(n+5, -1));
        
        return go(0, 1, satisfaction, dp);
    }
};




// Greedy Soln
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        
        int res = 0, total = 0; 
        for (int i = n - 1; i >= 0; i--) {
            if (total + satisfaction[i] > 0) {
                total += satisfaction[i];
                res += total;
            } else {
                break;
            }
        }
        return res;
    }
};
