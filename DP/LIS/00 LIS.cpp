/* 
Key Idea: 
dp[i] is the length of the longest subsequence that ends at the i'th element
i.e. dp[i] is storing the value of LIS including nums[i] as the last element of the LIS array.
*/

// O(n.log(n))
// https://youtu.be/66w10xKzbRM


// O(n^2)
class Solution {
public:
    vector<int> LIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        if(n==0)
            return ans;
        
        int mx = 1;
        vector<int> dp(n+1, 1);
        
        for(int i=1; i < n; ++i) {
            for(int j=0; j < i; ++j) {
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        //Now push the answer LIS
        int prev = -1;
        for(int i = n-1; i >= 0; i--) {
            if(dp[i] == mx &&  (prev > nums[i] || prev==-1)) {
                ans.push_back(nums[i]);
                mx -= 1;
                prev = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// O(nlog(n))          [Increasing Subsequence]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> seq;
        seq.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > seq.back()) {
                seq.push_back(nums[i]);
            } else {
                int idx = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[idx] = nums[i];
            }
        }
        
        return seq.size();
    }
};



// O(nlog(n))          [Non decreasing Subsequence]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> seq;
        seq.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            if(nums[i] >= seq.back()) {
                seq.push_back(nums[i]);
            } else {
                int idx = upper_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[idx] = nums[i];
            }
        }
        
        return seq.size();
    }
};
