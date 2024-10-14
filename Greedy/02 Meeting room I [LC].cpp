// https://leetcode.com/problems/meeting-rooms/

/*
Given an array of meeting time intervals where intervals[i] = [starti, endi], 
determine if a person could attend all meetings.

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Input: intervals = [[7,10],[2,4]]
Output: true
*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return true;
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int cnt = 1;
        int end = intervals[0][1];

        for(int i = 1 ; i < intervals.size(); i++) {
            if(intervals[i][0] >= end) {
                end = intervals[i][1];
                cnt++;
            }
        }

        return cnt == intervals.size();
    }
};
