
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int res, diff = 1e9;
        
        for(int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(sum - target) < diff) {
                    res = sum;
                    diff = abs(sum - target);
                    if(diff == 0) return res;
                }
                
                if(sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        
        return res;
    }
};
