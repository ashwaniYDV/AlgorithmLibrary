// https://leetcode.com/problems/two-sum/

// 2 pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> a;
        
        for(int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }
        sort(a.begin(), a.end());
        
        int l = 0, r = n - 1;
        
        while(l < r) {
            if(a[l].first + a[r].first == target) {
                return {a[l].second, a[r].second};
            } else if(a[l].first + a[r].first > target) {
                r--;
            } else {
                l++;
            }
        }
        return {};
    }
};



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(k - nums[i])) {
                return {mp[k - nums[i]], i};
            }
            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};