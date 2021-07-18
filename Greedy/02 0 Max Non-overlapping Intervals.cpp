// https://leetcode.com/problems/non-overlapping-intervals/

/*
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/



/*
Classic non overlapping interval problem.

Greedy choice is to always pick the next interval whose end time is least among remaining intervals 
and start time is >= finish time of previously selected interval. 
We can sort the intervals according to their end time 
so that we always consider the next interval as min end time interval.

1) Sort the intervals according to their end time
2) Select the first interval from the sorted array and print it.
3) Do following for remaining intervals in the sorted array.
   a) If start time of this interval > end time of previously selected interval then 
      select this interval and print it and update the end point as this interval's end point.
   b) Othewise skip this interval 
*/


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;
        
        // sort in ascending order of end time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
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