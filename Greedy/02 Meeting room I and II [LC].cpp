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







// https://leetcode.com/problems/meeting-rooms-ii/description/

/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Input: intervals = [[7,10],[2,4]]
Output: 1
 
Constraints:
1 <= intervals.length <= 10^4
0 <= starti < endi <= 10^6
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> arr, dep;
        for(auto &it: intervals){
            arr.push_back(it[0]);
            dep.push_back(it[1]);
        }

        // Sort arrival and departure vectors
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        

        // room_needed indicates number of rooms needed at a time
        int room_needed = 1, result = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] < dep[j]) {
                room_needed++;
                i++;
            }
            else {
                room_needed--;
                j++;
            }

            result = max(result, room_needed);
        }

        return result;
    }
};
