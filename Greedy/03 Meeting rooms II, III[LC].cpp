// https://leetcode.com/problems/meeting-rooms-ii/
/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of conference rooms required. 

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Input: intervals = [[7,10],[2,4]]
Output: 1
*/

// Method 1
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<int> arr, dept;

        for(auto& it: intervals) {
            arr.push_back(it[0]);
            dept.push_back(it[1]);
        }

        sort(arr.begin(), arr.end());
        sort(dept.begin(), dept.end());

        int room_needed = 1, result = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] < dept[j]) {
                room_needed++;
                i++;
            } else {
                room_needed--;
                j++;
            }

            result = max(result, room_needed);
        }

        return result;
    }
};




// Method 2
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> pref;
        
        for (auto &it: intervals) {
            pref[it[0]]++;
            pref[it[1]]--;
            // pref[it[1] + 1]--; sometime we have to do like this
        }
        
        int cnt = 0, res = 0;
        for (auto &it: pref) {
            cnt += it.second;
            res = max(res, cnt);
        }
        return res;
    }
};















// https://leetcode.com/problems/meeting-rooms-iii/

/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.
You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). 
All the values of starti are unique.

Meetings are allocated to rooms in the following manner:
* Each meeting will take place in the unused room with the lowest number.
* If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
* When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.


Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 

Constraints:
1 <= n <= 100
1 <= meetings.length <= 10^5
meetings[i].length == 2
0 <= starti < endi <= 5 * 10^5
All the values of starti are unique.
*/


/*
Intuition
=========
With each meeting, check if there are any free rooms. If there are, then use the room with the smallest number. Otherwise, assign the meeting to the room whose meeting will end the soonest.
*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> freq(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms; // {roomAvailabilityTime, room}
        priority_queue<int, vector<int>, greater<int>> unusedRooms;

        for (int i = 0; i < n; i++) unusedRooms.push(i);

        for (auto& it: meetings) {
            int start = it[0], end = it[1];

            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }

            if (!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                freq[room]++;
            } else {
                auto [roomAvailabilityTime, room] = usedRooms.top();
                usedRooms.pop();
                int usageDuration = end - start;
                usedRooms.push({roomAvailabilityTime + usageDuration, room});
                freq[room]++;
            }
        }

        int maxfreq = 0, maxfreqRoom = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i] > maxfreq) {
                maxfreq = freq[i];
                maxfreqRoom = i;
            }
        }
        return maxfreqRoom;
    }
};
