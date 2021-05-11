class Solution {
public:
    #define ll long long
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        ll left = 0, right = 0;
        for(ll x: nums) {
            right += x;
            left = max(left, x);
        }
        while(left <= right) {
            ll mid = left - (left - right) / 2;
            ll sum = 0, cnt = 1;
            for(ll x: nums) {
                if(sum + x > mid) {
                    cnt++;
                    sum = 0;
                }
                sum += x;
            }
            if(cnt > m) {
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
    #define ll long long
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        ll left = 0, right = 0;
        for(ll x: nums) {
            right += x;
            left = max(left, x);
        }
        while(left < right) {
            ll mid = left - (left - right) / 2;
            ll sum = 0, cnt = 1;
            for(ll x: nums) {
                if(sum + x > mid) {
                    cnt++;
                    sum = 0;
                }
                sum += x;
            }
            if(cnt > m) {
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
