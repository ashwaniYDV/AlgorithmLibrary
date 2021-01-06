// https://leetcode.com/problems/non-overlapping-intervals/
// similar to classic interval scheduling problem

class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) { 
        return v1[1] < v2[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;
        
        // sort in ascending order of end time
        sort(intervals.begin(), intervals.end(), compare);
        
        int end = intervals[0][1];
        // count = max no. of non overlaping intervals
        int count = 1;
        
        for (int i = 1; i < n; i++) {
            // intervals[i].start >= end
            if (intervals[i][0] >= end) {
                // end = intervals[i].end
                end = intervals[i][1];
                count++;
            }
        }
        return n - count;
    }
};
