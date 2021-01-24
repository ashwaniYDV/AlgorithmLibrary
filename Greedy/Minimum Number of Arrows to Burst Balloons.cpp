// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) { 
        return v1[1] < v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0) return 0;
        
        // sort in ascending order of end x-coordinate
        sort(points.begin(), points.end(), compare);
        
        int end = points[0][1];
        // count = max no. of non overlaping intervals
        int count = 1;
        
        for (int i = 1; i < n; i++) {
            // points[i].start >= end
            if (points[i][0] > end) {
                // end = points[i].end
                end = points[i][1];
                count++;
            }
        }
        return count;
    }
};
