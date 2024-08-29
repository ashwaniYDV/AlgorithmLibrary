// https://leetcode.com/problems/best-team-with-no-conflicts/

/*
You are the manager of a basketball team. 
For upcoming tournament, you want to choose the team with highest overall score. 
The score of the team is sum of scores of all players in the team.
However, basketball team is not allowed to have conflicts. 
A conflict exists if a younger player has a strictly higher score than an older player. 
A conflict does not occur between players of the same age.
Given two lists, scores and ages, return the highest overall score of all possible basketball teams.

Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.

Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.

Input: scores = [1,2,3,5], ages = [8,9,10,1]
Output: 6
Explanation: It is best to choose the first 3 players. 
*/


/*
Intuition
---------
Actually, this problem is similar to find the maximum sum of increasing subsequence.
This problem want both age and score are increasing.
We can sort by age and do DP for scores.

Approach
--------
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
        
        int res = dp[0];
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; j++){
                // arr sorted by age, latter element has to have high score to maintain increasing susequence
                if(arr[i].second >= arr[j].second){
                    dp[i] = max(dp[i], dp[j] + arr[i].second); 
                }
            }
            res = max(res, dp[i]); 
        }
        
        return res;
    }
};
