// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

/*
Given N activities with their start and finish day given in array start[ ] and end[ ]. 
Select the max no of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a given day.
*/

/*
Same as classic non overlapping interval problem.

The greedy choice is to always pick next activity whose finish time is least among the remaining activities 
and start time is >= finish time of previously selected activity. 
We can sort the activities according to their finishing time 
so that we always consider the next activity as minimum finishing time activity.

1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do following for remaining activities in the sorted array.
    a) If the start time of this activity is greater than to the finish time of previously selected activity then 
      select this activity and print it.
    b) Otherwise skip this activity 
*/



class Solution {
public:
    static bool compare(pair<int, int>& i1, pair<int, int>& i2) { 
        return i1.second < i2.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n) {
        // Function to find the maximum number of activities that can be performed by a single person.
        vector<pair<int, int>> a;
        for(int i = 0; i < n; i++) {
            a.push_back({start[i], end[i]});
        }
        sort(a.begin(), a.end(), compare);
    
        int endTime = a[0].second;
        int count = 1;
        
        for (int i = 1; i < n; i++) {
            // If this activity has start time > the finish time of previously selected activity, then select it 
            if (a[i].first > endTime) {
                endTime = a[i].second;
                count++;
            }
        }
        return count;
    }
};









// Weighted Job Scheduling Problem
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution {
public:
    int n;

    // FFFFFFFTTTTTTTT
    int findNextStartTimeIdx(int l, int currentEndTime, vector<array<int, 3>>& jobs) {
        int r = n;
        while(l < r) {
            int mid = (l+r)/2;
            int nextStartTime = jobs[mid][0];
            if(nextStartTime >= currentEndTime) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int fun(int i, vector<array<int, 3>>& jobs, vector<int>& dp) {
        if (i == n ) return 0;
        if (dp[i]!= -1) return dp[i];

        // Skip job[i]
        int skipJob = fun(i+1, jobs, dp);

        // take job[i]
        int nextStartTimeIdx = findNextStartTimeIdx(i, jobs[i][1], jobs);
        int takeJob = jobs[i][2] + fun(nextStartTimeIdx, jobs, dp);

        return dp[i] = max(skipJob, takeJob);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        
        // startTime, endTime, profit
        vector<array<int, 3>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // sorting based on (start, end) time
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n+1, -1);
        return fun(0, jobs, dp);
    }
};
