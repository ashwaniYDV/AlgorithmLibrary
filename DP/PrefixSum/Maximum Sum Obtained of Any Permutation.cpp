// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

/*
We have an array of integers, nums, and an array of requests where requests[i] = [starti, endi]. 
The ith request asks for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi]. Both starti and endi are 0-indexed.
Return the maximum total sum of all requests among all permutations of nums.
Since the answer may be too large, return it modulo 10^9 + 7.


Example 1:
Input: nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
Output: 19
Explanation: One permutation of nums is [2,1,3,4,5] with the following result: 
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
Total sum: 8 + 3 = 11.
A permutation with a higher total sum is [3,5,4,2,1] with the following result:
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
Total sum: 11 + 8 = 19, which is the best that you can do.

Constraints:
n == nums.length
1 <= n <= 10^5
0 <= nums[i] <= 10^5
1 <= requests.length <= 10^5
requests[i].length == 2
0 <= starti <= endi < n
*/


/*
Hint:
Indexes with higher frequencies should be bound with larger values of nums.
*/


class Solution {
public:
    const int mod = 1e9 + 7;

    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> freq(n);

        for (auto it : requests) {
            freq[it[0]]++;
            if (it[1] + 1 < n) freq[it[1] + 1]--;
        }

        for (int i = 1; i < n; i++) {
            freq[i] += freq[i - 1];
        }

        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ((long)freq[i] * (long)nums[i]);

            sum %= mod;
            if (sum < 0) sum += mod;
        }

        return (int)sum;
    }
};


















class Solution {
public:
    const int mod = 1e9 + 7;

    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        // {freq, index}
        vector<pair<int, int>> freq(n);

        for (auto it : requests) {
            freq[it[0]].first++;
            if (it[1] + 1 < n) freq[it[1] + 1].first--;
        }

        freq[0].second = 0;
        for (int i = 1; i < n; i++) {
            freq[i].first += freq[i - 1].first;
            freq[i].second = i;
        }

        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        // greater freq value index should have greater nums value
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[freq[i].second] = nums[i];
        }

        for (int i = 1; i < n; i++) arr[i] += arr[i - 1];

        int sum = 0;
        for (auto it : requests) {
            int l = it[0], r = it[1];
            sum += arr[r];
            sum -= (l > 0) ? arr[l - 1] : 0;

            sum %= mod;
            if (sum < 0) sum += mod;
        }

        return sum;
    }
};
