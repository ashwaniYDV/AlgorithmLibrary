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




// Using BIT 
// https://codeforces.com/problemset/problem/340/D
// O(nlog(n))          [Increasing Subsequence]
class Solution {
public:
    static const int N = 1e5+5;
    int BIT[N];
    int n;
    
    void update(int i, int val) {
        while(i <= n) {
            BIT[i] = max(BIT[i], val);
            i += (i&-i);
        }
    }
    int query(int i) {
        int mx = 0;
        while(i > 0) {
            mx = max(mx, BIT[i]);
            i -= (i&-i);
        }
        return mx;
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        if(n == 0) return 0;
        
        // this preprocessing is done to make all the nums element unique
        vector<pair<int,int> > v;
        for(int i = 0; i < n; i++) v.push_back({nums[i], -i});
        sort(v.begin(), v.end());
        map<pair<int, int>, int> mp;
        int c = 1;
        for(auto i: v) mp[i] = c++;
        
        int LIS = 0;
        for(int i = 0; i < n; i++) {
            int x = query(mp[{nums[i], -i}]);
            update(mp[{nums[i], -i}], x + 1);
            LIS = max(LIS, x + 1);
        }

        return LIS;
    }
};
