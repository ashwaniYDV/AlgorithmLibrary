// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/

/*
You are given an m x n integer matrix mat and an integer target.
Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.
Return the minimum absolute difference.
*/

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<set<int>> a;
    
    int go(int i, int sum, int& target) {
        if(i == n) {
            return abs(sum - target);
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int res = 1e9;
        
        for(int x: a[i]) {
            int total = sum + x;
            res = min(res, go(i+1, total, target));
            if(res == 0 || total > target) break;
        }
        
        return dp[i][sum] = res;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        n = mat.size(), m = mat[0].size();
        
        a.clear();
        for(auto& it: mat) {
            a.push_back(set<int>(it.begin(), it.end()));
        }
        
        dp.resize(n+1, vector<int>(70*70+5, -1));
        return go(0, 0, target);
    }
};
