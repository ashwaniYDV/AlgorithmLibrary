/*
https://leetcode.com/problems/best-team-with-no-conflicts/

Actually, this problem is similar to find the maximum sum of increasing subsequence.

This problem want both age and score are increasing.
We can sort by age and do DP for scores.

Key points:
1) Create another arr by pair{age[i], socres[i]} and sorted by age.
2) Calculate max sum of LIS on the basis of scores on sorted array by age
*/

// O(n^2)
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        // first: age;  second: scores
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; ++i){
            arr[i].first = ages[i];
            arr[i].second = scores[i];
        }
        // sort by age
        sort(arr.begin(), arr.end());
        
        // calculate maximum sum LIS by scores on sorted array by age
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            dp[i] = arr[i].second;
        }
        
        int team_score = dp[0];
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; j++){
                // arr sorted by age, latter element has to have high score to maintain increasing susequence
                if(arr[i].second >= arr[j].second){
                    dp[i] = max(dp[i], dp[j] + arr[i].second); 
                }
            }
            team_score = max(team_score, dp[i]); 
        }
        
        return team_score;
    }
};
