// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// FFFFFFTTTTTTTTTT

class Solution {
public:
    bool check(int mid, int days, vector<int>& weights) {
        int n = weights.size();
        int cnt = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum + weights[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += weights[i];
        }
        // if currently i have some sum, then i require one more day
        if(sum) cnt++;

        return cnt <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo =  *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while(lo < hi) {
            int mid = (lo + hi) / 2;
            
            if(check(mid, days, weights)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
