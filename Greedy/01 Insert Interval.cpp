// https://leetcode.com/problems/insert-interval/

/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] 
and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti 
and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
*/

class Solution {
    public: vector<vector<int>> insert(vector < vector < int >> & intervals, vector < int > & newInterval) {
        int n = intervals.size();

        vector<vector<int>> res;

        // sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        //     return a[0] < b[0];
        // });

        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
