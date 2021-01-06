// https://leetcode.com/problems/russian-doll-envelopes/

/* This is same as "Non Crossing Building Bridges" problem.
In bridges problem two north and two south points can share.
But here both width and heigt should be in strictly increasing order and two widths and heights must not be same

Idea is:
(1) Sort on the basis of widths
(2) Do LIS on the basis of heights (LIS will ensure that all the heights are distinct and in increasing order)
(3) Thus we have to add addition check for strictly increasing width also
    [Which is done on the dp steps]
*/

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0) return 0;
        
        // sort on the basis of widths in ascending order
        sort(envelopes.begin(), envelopes.end(), compare);
        
        vector<int> dp(n+1, 1);
        int mx = 1;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                // condition for distinct widths
                if(envelopes[i][1] > envelopes[j][1] && envelopes[i][0] > envelopes[j][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        return mx;
    }
};
