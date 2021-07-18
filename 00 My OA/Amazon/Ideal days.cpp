/*
Alexa team is working on a new feature that suggests days for camping based on the weather forecast. 
According to a survey, a day is ideal for camping:
if the amount of rainfall has been non-increasing for the prior k days from the considered day, 
and will be non-decreasing for the following k days from the considered day. 

Given the predicted rainfall for the next n days, find all the ideal days. 

Formally, the day is ideal if the following is true: 
day[i-k] ≥ day[i-k+1] ≥ … ≥ day[i- 1] ≥ day[i] ≤ day[i+1] ≤ day[i+2] ≤ … ≤ day[i+k-1] ≤ day[i+k] 

Return the array of ideal days in ascending order. 
Note that the ith element of the array represents the data for the day i + 1. 
It is guaranteed that there is at least one ideal day. 

Example 
=======
day = [3, 2, 2, 2, 3, 4] 
K = 2 
ans = [3, 4]
*/


vector<int> predictDays(vector<int> day, int k) {
    int n = day.size();
    vector<int> dpl(n, 0), dpr(n, 0);

    for(int i = 1; i < n; i++) {
        if(day[i] <= day[i - 1]) 
            dpl[i] = dpl[i - 1] + 1;
        else 
            dpl[i] = 0;
    }

    for(int i = n - 2; i >= 0; i--) {
        if(day[i] <= day[i + 1]) 
            dpr[i] = dpr[i + 1] + 1;
        else 
            dpr[i] = 0;
    }

    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(dpl[i] >= k && dpr[i] >= k) {
            res.push_back(i+1);
        }
    }
    return res;
}
