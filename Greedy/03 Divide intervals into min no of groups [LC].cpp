// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

/*
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].
You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.
Return the minimum number of groups you need to make.

Note:
    Two intervals intersect if there is at least one common number between them. 
    For example, the intervals [1, 5] and [5, 8] intersect.


Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.
*/


// Method 1
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> arr, dept;
        for(auto& it: intervals) {
            arr.push_back(it[0]);
            dept.push_back(it[1]);
        }

        sort(arr.begin(), arr.end());
        sort(dept.begin(), dept.end());

        int roomsNeeded = 1, res = 1;
        int i = 1, j = 0;

        while(i < n && j < n) {
            if(arr[i] <= dept[j]) {
                roomsNeeded++;
                i++;
            } else {
                roomsNeeded--;
                j++;
            }

            res = max(res, roomsNeeded);
        }

        return res;
    }
};


// Method 2
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> pref;
        
        for (auto &it: intervals) {
            pref[it[0]]++;
            pref[it[1] + 1]--;
        }
        
        int cnt = 0, res = 0;
        for (auto &it: pref) {
            cnt += it.second;
            res = max(res, cnt);
        }
        return res;
    }
};
