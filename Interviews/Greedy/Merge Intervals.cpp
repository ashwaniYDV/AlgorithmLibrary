// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    static bool compare(vector<int>& a1, vector<int>& a2) {
        return a1[0] < a2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        
        // sort on the basis of starting of interval
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for (int i = 1; i < n; i++) {
            // res.back.end < intervals[i].start
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                // res.back.end = max(res.back.end, intervals[i].end)
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        
        return res;
    }
};
