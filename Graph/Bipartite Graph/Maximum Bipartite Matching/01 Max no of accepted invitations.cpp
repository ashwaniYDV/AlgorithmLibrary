// https://leetcode.com/problems/maximum-number-of-accepted-invitations/

/*
There are m boys and n girls in a class attending an upcoming party.
You are given an m x n integer matrix grid, where grid[i][j] equals 0 or 1. 
If grid[i][j] == 1, then that means the ith boy can invite the jth girl to the party. 
A boy can invite at most one girl, and a girl can accept at most one invitation from a boy.
Return max possible number of accepted invitations. 


Input: grid = [[1,1,1],
               [1,0,1],
               [0,0,1]]
Output: 3
Explanation: The invitations are sent as follows:
- The 1st boy invites the 2nd girl.
- The 2nd boy invites the 1st girl.
- The 3rd boy invites the 3rd girl.

Input: grid = [[1,0,1,0],
               [1,0,0,0],
               [0,0,1,0],
               [1,1,1,0]]
Output: 3
Explanation: The invitations are sent as follows:
-The 1st boy invites the 3rd girl.
-The 2nd boy invites the 1st girl.
-The 3rd boy invites no one.
-The 4th boy invites the 2nd girl.
 
Constraints:
1 <= m, n <= 200
*/


// TLE solution
class Solution {
public:
    int n, m;

    int f(int i, vector<int> check, vector<vector<int>>& grid) {
        if(i == n) return 0;

        int res = f(i+1, check, grid);
        for(int j = 0; j < m; j++) {
            if(grid[i][j] && !check[j]) {
                check[j] = 1;
                res = max(res, 1 + f(i+1, check, grid));
                check[j] = 0;
            }
        }

        return res;
    }

    int maximumInvitations(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> check(m, 0);
        return f(0, check, grid);
    }
};