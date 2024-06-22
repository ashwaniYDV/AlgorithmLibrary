// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = i + 1; j < n; j++) {
                int y = nums[j];
                int l = j + 1, r = n - 1;

                while (l < r) {
                    long long sum = (long)x + (long)y + (long)nums[l] + (long)nums[r];
                    if (sum == target) {
                        res.push_back({x, y, nums[l], nums[r]});

                        // to handle duplicates
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;

                    }
                    else if (sum > target) {
                        r--;
                    } else {
                        l++;
                    }
                }

                // to handle duplicates
                while (j + 1 < n && nums[j] == nums[j + 1]) j++;
            }
            // to handle duplicates
            while (i + 1 < n && nums[i] == nums[i + 1]) i++;
        }

        return res;
    }
};
