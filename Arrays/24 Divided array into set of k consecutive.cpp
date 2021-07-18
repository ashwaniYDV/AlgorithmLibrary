// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// https://leetcode.com/problems/hand-of-straights/submissions/1243123171/

/*
Given an array of integers nums and a positive integer k, 
check whether it is possible to divide this array into sets of k consecutive numbers.
Return true if it is possible. Otherwise, return false.

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
*/

// Method 1
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k) return false;
        
        map<int, int> mp;
        for(int x: nums) mp[x]++;

        for(auto it: mp) {
            if(it.second == 0) continue;
            
            int x = it.first;
            int freq = it.second;

            for(int i = x; i < x + k; i++) {
                if(!mp.count(i)) return false;
                mp[i] -= freq;
                if(mp[i] < 0) return false;
            }
        }
        
        return true;
    }
};



// Method 2
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k) return 0;

        sort(nums.begin(), nums.end());

        int m = n / k;
        vector<vector<int>> v(m);
        map<int, int> mp;

        int j = 0;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            if(mp.count(x)) {
                int idx = mp[x] + 1;
                if(idx == m) return false;
                v[idx].push_back(x);
                mp[x] = idx;
            } else {
                while(j < m && v[j].size() == k) {
                    j++;
                }
                if(j < m) {
                    v[j].push_back(x);
                    mp[x] = j;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 1; j < k; j++) {
                if(v[i][j] != v[i][j-1] + 1) return false;
            }
        }


        return true;
    }
};