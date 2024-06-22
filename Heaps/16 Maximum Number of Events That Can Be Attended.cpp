// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/solutions/510263/java-c-python-priority-queue/
// https://youtu.be/dTVB1W7-BvY?si=rbrxr0Nv9nAU3dKT

/*
You are given an array of events where events[i] = [startDayi, endDayi]. 
Every event i starts at startDayi and ends at endDayi.
You can attend an event i at any day d where startTimei <= d <= endTimei. 
You can only attend one event at any time d.
Return the maximum number of events you can attend.
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        
        // insert deadline of events in min heap
        priority_queue<int, vector<int>, greater<int>>pq;

        int i = 0, res = 0;

        for(int d = 1; d <= 100000; d++) {
            // remove the events which already ended before current day
            while(!pq.empty() && pq.top() < d) pq.pop();

            // insert deadline of events which are starting today into heap
            while(i < n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }
            
            // remove one event for current day (event with earliest deadline will be on top)
            if(!pq.empty()) {
                pq.pop();
                res++;
            }

            if(i == n && pq.empty()) break;
        }

        return res;
    }
};





class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue <int, vector<int>, greater<int>> pq;
        
        int i = 0, res = 0, d = 0, n = events.size();
        
        while (i < n || !pq.empty()) {
            if (pq.empty()) d = events[i][0];
            
            while (i < n && events[i][0] == d) {
                pq.push(events[i++][1]);
            }

            pq.pop();
            ++res, ++d;

            while (!pq.empty() && pq.top() < d) {
                pq.pop();
            }
        }
        return res;
    }
};