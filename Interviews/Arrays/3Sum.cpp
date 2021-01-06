// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            int x = nums[i];
            
            while(l < r) {
                if(x + nums[l] + nums[r] == 0) {
                    res.push_back({x, nums[l], nums[r]});
                    
                    // to handle duplicates
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                    
                } else if(x + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
            
            // to handle duplicates
            while(i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        
        return res;
    }
};
