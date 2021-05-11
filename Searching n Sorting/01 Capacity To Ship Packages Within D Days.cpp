// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int left = 0, right = 0;
        for (int w: weights){
            left = max(left, w);
            right += w;
        }

        while(left <= right) {
            int mid = (left + right) / 2;
            int cnt = 1, sum = 0;
            for(int i = 0; i < n; i++) {
                if(sum + weights[i] > mid) {
                    cnt++;
                    sum = 0;
                }
                sum += weights[i];
            }
            if(cnt > D) {
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
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
            if(curr_days > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
