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
        sort(jobs.begin(), jobs.end(), [](array<int, 3>& a1, array<int, 3>& a2) -> bool {
            if(a1[0] != a2[0]) return a1[0] < a2[0];
            return a1[1] < a2[1];
        });

        vector<int> dp(n+1, -1);
        return fun(0, jobs, dp);
    }
};
