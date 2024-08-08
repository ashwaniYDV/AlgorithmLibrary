// https://leetcode.com/problems/top-k-frequent-elements/description/

/*
Given an integer array nums and an integer k, return k most frequent elements. 
You may return the answer in any order.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]
*/

// Method 1.1: Bucket sort, Time = O(N)
/*
Since the array nums has size of n, the frequency can be up to n.
We can create bucket to store numbers by frequency.
Then start bucketIdx = n, we can get the k numbers which have largest frequency.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums) cnt[x] += 1;
        
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for (auto [num, freq] : cnt) {
            bucket[freq].push_back(num);
        }
        
        vector<int> res;
        for (int bucketId = n; bucketId >= 1; bucketId--) {
            for (int num : bucket[bucketId]) {
                if (k == 0) return res;
                
                res.push_back(num);
                k--;
            }
        }
        return res;
    }
};

// Method 1.2: Bucket sort, Time = O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums) cnt[x] += 1;
        
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for (auto [num, freq] : cnt) {
            bucket[freq].push_back(num);
        }
        
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};



// Method 2: Time = O(N*logK)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
        }
        
        vector<int> res;
        // pair<first, second>: {frequency, number}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};