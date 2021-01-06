// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> dp_lis(n + 1, 1);
        vector<int> dp_cnt(n + 1, 1);

        int lis = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]){
                    if (dp_lis[j] + 1 > dp_lis[i]) {
                        dp_lis[i] = dp_lis[j] + 1;
                        dp_cnt[i] = dp_cnt[j];
                    } else if (dp_lis[j] + 1 == dp_lis[i]) {
                        dp_cnt[i] += dp_cnt[j];
                    }
                }
            }
            lis = max(lis, dp_lis[i]);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(dp_lis[i] == lis) {
                cnt += dp_cnt[i];
            }
        }
        
        return cnt;
    }
};
