class Solution {
   public:
      int twoSumClosest(vector < int > & nums, int target) {
         sort(nums.begin(), nums.end());
         int n = nums.size();

         int res, diff = 1e9;
         int l = 0, r = n - 1;
         while (l < r) {
            int sum = nums[l] + nums[r];
            if (abs(sum - target) < diff) {
               res = sum;
               diff = abs(sum - target);
               if(diff == 0) return res;
            }

            if (sum > target) {
               r--;
            } else {
               l++;
            }
         }

         return res;
      }
};
