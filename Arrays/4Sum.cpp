// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            for(int j = i + 1; j < n; j++) {
                int l = j + 1, r = n - 1;
                int y = nums[j];

                while(l < r) {
                    if(x + y + nums[l] + nums[r] == target) {
                        res.push_back({x, y, nums[l], nums[r]});

                        // to handle duplicates
                        while(l < r && nums[l] == nums[l + 1]) l++;
                        while(l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;

                    } else if(x + y + nums[l] + nums[r] > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
                
                // to handle duplicates
                while(j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            // to handle duplicates
            while(i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        
        return res;
    }
};

