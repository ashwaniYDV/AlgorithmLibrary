// https://leetcode.com/problems/count-days-without-meetings/description/

/*
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). 
You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
Return the count of days when the employee is available for work but no meetings are scheduled.
Note: The meetings may overlap.
*/


/*
Intuition
---------
* Merge the overlapping intervals of the meetings.
* Return the sum of difference between the end time of a meeting and the start time of the next meeting for all adjacent pairs.
*/

class Solution {
public:
    vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& a) {
        int n = a.size();

        // sort on basis of start time
        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            return x[0] < y[0];
        });

        vector<vector<int>> merged;
        merged.push_back(a[0]);

        for(int i = 1; i < n; i++) {
            if(a[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], a[i][1]);
            } else {
                merged.push_back(a[i]);
            }
        }

        return merged;
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> a = mergeOverlappingIntervals(meetings);
        int n = a.size();

        int res = a[0][0] - 1;
        for(int i = 1; i < n; i++) {
            res += a[i][0] - a[i - 1][1] - 1;
        }
        res += days - a[n-1][1];

        return res;
    }
};
