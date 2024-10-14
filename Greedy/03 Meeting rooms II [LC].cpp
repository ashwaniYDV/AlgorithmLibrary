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