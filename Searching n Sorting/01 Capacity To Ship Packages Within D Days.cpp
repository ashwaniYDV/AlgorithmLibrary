// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

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

















class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int left = 0, right = 0;
        for (int w: weights){
            left = max(left, w);
            right += w;
        }
        while(left < right) {
            int mid = (left + right) / 2;
            int curr_days = 1, curr_bagsize = 0;
            for(auto w : weights) {
                if(curr_bagsize + w > mid) {
                    curr_days++; 
                    curr_bagsize = 0;
                }
                curr_bagsize += w;
            }
            if(curr_days <= D) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
