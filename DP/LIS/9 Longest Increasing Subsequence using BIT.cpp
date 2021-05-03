// https://www.geeksforgeeks.org/longest-increasing-subsequence-using-bit/

/*
Approach:  

1) First, use coordinate compression (replace all values of the array to numbers ranging from 1 to N). 
   This will reduce the maximum number in the array and help us solve the above problem in NlogN time. Also, this will help us to reduce memory.
2) Make a new array BIT of length N + 1.
3) Now, traverse the array from left to right and add the current element to the BIT.
4) When ith element (A[i]) is inserted in the BIT, check for the length of the longest subsequence that can be formed till A[i] – 1. 
   Let this value be x. If x + 1 is greater than the current element in BIT, update the BIT.
*/

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
            // int x = query(mp[{nums[i], -i}] - 1);
            update(mp[{nums[i], -i}], x + 1);
            LIS = max(LIS, x + 1);
        }

        return LIS;
    }
};
